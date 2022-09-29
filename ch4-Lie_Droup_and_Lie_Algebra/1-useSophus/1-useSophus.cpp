#include <iostream>
#include <cmath>

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>

#include <sophus/so3.hpp>
#include <sophus/se3.hpp> // cmake不报错

using namespace std;
using namespace Eigen;

// Sophus的基本用法
int main(int argc, char const *argv[])
{
    // 沿着Z轴转90度的旋转矩阵
    Matrix3d R = AngleAxisd(M_PI / 2, Vector3d(0, 0, 1)).toRotationMatrix();
    cout << "R = \n"  << R << endl;
    // 或者四元数
    Quaterniond q(R);
    cout << "q = \n" << q << endl;
    
    // 特殊正交群 SO3
    Sophus::SO3d SO3_R(R);  // Sophus::SO3d可以直接从旋转矩阵构造
    Sophus::SO3d SO3_q(q); // 也可以直接从四元数构造
    // 二者是等价的
    cout << "SO(3) from matrix: \n" << SO3_R.matrix() << endl;
    cout << "SO(3) from quaternion: \n" << SO3_q.matrix() << endl;

    /**
     * 使用对数映射获取它的李代数
     */
    Vector3d so3 = SO3_R.log();
    cout << "so3 = " << so3.transpose() << endl;

    // hat 为向量到反对称矩阵
    cout << "so3 hat = \n" << Sophus::SO3d::hat(so3) << endl;
    // vee 反对称矩阵到向量
    cout << "so3 hat vee = " << Sophus::SO3d::vee(Sophus::SO3d::hat(so3)).transpose() << endl;


    // 增量扰动模型的更新
    Vector3d update_so3(1e-4, 0, 0); // 假设每次更新量这么多
    Sophus::SO3d SO3_updated = Sophus::SO3d::exp(update_so3) * SO3_R; // 扰动模型
    cout << "SO3 updated = \n " << SO3_updated.matrix() << endl;

    cout << "*************************" << endl;
    // SE(3)操作

    Vector3d t(1, 0, 0);  // 沿着x平移1
    Sophus::SE3d SE3_Rt(R, t);  // 从R,t构造SE(3)
    Sophus::SE3d SE3_qt(q, t);  // 从q,t构造SE(3)
    cout << "SE3 from R,t = \n" << SE3_Rt.matrix() << endl;
    cout << "SE3 from q,t = \n" << SE3_qt.matrix() << endl;

    // 李代数se(3)是一个六维向量，方便起见使用typedef定义，转换为四位向量
    typedef Matrix<double, 6, 1> Vector6d;
    Vector6d se3 = SE3_Rt.log();
    cout << "se3 = " << se3.transpose() << endl;


    // 观察输出，可以发现Sophus中，se(3)的平移在前，旋转在后
    // 转换为4维向量
    cout << "se3 hat = \n" << Sophus::SE3d::hat(se3) << endl;
    // 转换为se3
    cout << "se3 hat vee = \n" << Sophus::SE3d::vee(Sophus::SE3d::hat(se3)).transpose() << endl;


    // se3 更新
    Vector6d update_se3; // 更新量
    update_se3.setZero();
    update_se3(0, 0) =  1e-4d;
    Sophus::SE3d SE3_updated = Sophus::SE3d::exp(update_se3) * SE3_Rt;
    cout << "SE3 updated = \n" << SE3_updated.matrix() << endl; 
    return 0;
}
