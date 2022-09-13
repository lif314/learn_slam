#include <iostream>
#include <vector>
#include <algorithm>

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>

using namespace std;
using namespace Eigen;

/**
 * @brief  习题
 *
 * 设有小萝卜一号和二号位于世界坐标系中。记世界坐标系为W，小萝卜的坐标系为
 * R1和R2。
 * 小萝卜一号的位姿为q1=[0.35, 0.2, 0.3, 0.1]^T, t1=[0.3, 0.1, 0.1]^T。
 * 小萝卜二号的位姿为q2=[-0.5,0.4,-0.1,0.2]^T, t2=[-0.1, 0.5, 0.3]^T
 * 这里的q和t表达的是T_{R_k, w}, k = 1,2, 也就是世界坐标系到相机系统坐标系
 * 的变换关系。现在，小萝卜一号看到某个点在自身的坐标系下坐标为P_{R1}=[0.5,0,0.2]^T
 * 求该向量在小萝卜二号坐标系下的坐标
 */

int main(int argc, char const *argv[])
{
    // 计算P_{R_2} = T_{R_2, W}T_{W,R_1}P_{R_1}
    // 注意 四元数使用前需要进行归一化

    // 定义变量
    Quaterniond q1(0.35, 0.2, 0.3, 0.1), q2(-0.5, 0.4, -0.1, 0.2);
    q1.normalize(); // 归一化
    q2.normalize();
    Vector3d t1(0.3, 0.1, 0.1), t2(-0.1, 0.5, 0.3);
    Vector3d p1(0.5, 0, 0.2);

    Isometry3d T1w(q1), T2w(q2);
    T1w.pretranslate(t1); // 添加平移量
    T2w.pretranslate(t2); // 添加平移量

    Vector3d p2 = T2w * T1w.inverse() * p1;
    cout << p2.transpose() << endl;

    return 0;
}
