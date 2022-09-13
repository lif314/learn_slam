#include <iostream>
#include <cmath>
using namespace std;

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>

using namespace Eigen;

/*****************
 * 演示Eigen几何模块的使用方法
 *****************/


/**
 * @brief Eigen 3D变换数据形式
 * 
 * 旋转矩阵(3*3)   Matrix3d
 * 旋转向量(3*1)   AngleAxisd
 * 欧拉角(3*1)     Vector3d 
 * 四元数(4*1)     Quaterniond
 * 欧氏变换矩阵(4*4)Isometry3d
 * 仿射变换(4*4)    Affine3d
 * 射影变换(4*4)    Projective3d
 */

int main(int argc, char const *argv[])
{
    // Eigen/Geometry模块提供了各种旋转和平移的表示

    // 3D旋转矩阵直接使用Matrix3d或Matrix3f
    Matrix3d rotation_matrix = Matrix3d::Identity();
    // 旋转向量使用AngleAxis, 它底层不直接是Matrix, 但运算可以当作矩阵(因为重载了运算符)
    AngleAxis rotation_vector(M_PI / 4, Vector3d(0, 0, 1)); // 沿着z轴旋转45度

    cout.precision(3);
    // 旋转向量转换为矩阵也可以直接赋值
    cout << "rotation_vector to matrix =\n"
         << rotation_vector.matrix() << endl;
    rotation_matrix = rotation_vector.toRotationMatrix();
    cout << "rotation_matrix =\n"
         << rotation_matrix << endl;

    // 用AngleAxis可以进行坐标转换
    Vector3d v(1, 0, 0);
    Vector3d v_rotated = rotation_vector * v;
    cout << "(1,0,0) after rotation (by angle axis) = " << v_rotated.transpose() << endl;
    // 或者使用旋转矩阵进行坐标转换
    v_rotated = rotation_matrix * v;
    cout << "(1,0,0) after rotation (by matrix) = " << v_rotated.transpose() << endl;

    // 欧拉角: 可以将旋转矩阵直接转换成欧拉角
    Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0); // ZYX顺序，即roll pitch yaw顺序
    cout << "yaw pitch roll = " << euler_angles.transpose() << endl;

    // 欧式变换矩阵使用Eigen::IsOmetry
    Isometry3d T = Isometry3d::Identity(); // 虽然称为3D，实质上是4*4矩阵
    T.rotate(rotation_vector);             // 按照toration_vector进行旋转
    T.pretranslate(Vector3d(1, 3, 4));     // 把平移向量设置为(1,3,4)
    cout << "Transform matrix = \n"
         << T.matrix() << endl;

    // 用变换矩阵进行坐标变换
    Vector3d v_transformed = T * v; // 相当于 R*v + t
    cout << "v = " << v.transpose() << endl;
    cout << "v transformed = " << v_transformed.transpose() << endl;

    // 对于仿射变换和射影变换，使用Eigen::Affine3d和Eigen::Projective3d即可

    // 四元数
    // 可以直接把AngleAxis赋值给四元数，反之亦然
    Quaterniond q = Quaterniond(rotation_vector);
    cout << "quaternion from rotation vector = " << q.coeffs().transpose() << endl;
    // 请注意生成coeffs的顺序是(x,y,z,w)， w为实部

    // 也可以将旋转矩阵赋值给四元数
    q = Quaterniond(rotation_matrix);
    cout << "quaternion from rotation matrix = " << q.coeffs().transpose() << endl;

    // 使用四元数旋转一个向量，使用重载的乘法即可
    v_rotated = q * v; // 注意数学上是 qvq^{-1}
    cout << "(1,0,0) after rotation (by quaternion) = " << v_rotated.transpose() << endl;
    // 用常规向量乘法表示
    cout << "should be equal to " << (q * Quaterniond(0, 1, 0, 0) * q.inverse()).coeffs().transpose() << endl;
    return 0;
}