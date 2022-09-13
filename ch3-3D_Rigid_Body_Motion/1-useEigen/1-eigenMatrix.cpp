#include <iostream>
using namespace std;

#include <ctime>

// Eigen核心部分
#include <eigen3/Eigen/Core>
// 稠密矩阵的代数运算(求逆、特征值等)
#include <eigen3/Eigen/Dense>

using namespace Eigen;

// 矩阵维度
#define MATRIX_SIZE 50

/*********************
 * Eigen的基本使用
 ********************/

int main(int argc, char const *argv[])
{
    // Eigen中所有向量和矩阵都是Eigen::Matrix, 它是一个模板类。它的前
    // 三个参数为数据类型、行、列

    /**
     * @brief Eigen 数据类型
     */

    // 声明一个2*3的float矩阵
    Matrix<float, 2, 3> matrix_23;

    // Eigen通过typedef提供了许多内置类型，不过底层仍是Eigen::Matrix
    // 例如，Vector3d 实质上是Eigen::Matrix<double, 3, 1>，即三维向量
    Vector3d v_3d;

    // 一样的
    Matrix<double, 3, 1> vd_3d;

    // Matrix3d 实质上是Eigen::Matrix<double,3,3>
    Matrix3d matrix_33 = Matrix3d::Zero();

    // 如果不确定矩阵的大小，可以使用动态大小的矩阵
    Matrix<double, Dynamic, Dynamic> matrix_dynamic;

    // 更简单的动态大小的矩阵
    MatrixXd matrix_x;

    /**
     * @brief Eigen 矩阵操作
     */
    // 输入数据(初始化)
    matrix_23 << 1, 2, 3, 4, 5, 6;
    // 输出
    cout << "matrix 2*3 from 1 to 6: \n"
         << matrix_23 << endl;

    // 使用()访问矩阵中的元素
    cout << "print matrix 2*3: \n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << matrix_23(i, j) << "\t";
        cout << endl;
    }

    // 矩阵向量相乘（实际上仍是矩阵和矩阵）
    v_3d << 3, 2, 1;
    vd_3d << 4, 5, 6;

    // 但是在Eigen里不能混合两种不同类型的矩阵，像这样是错的
    // Matrix<double, 2,1> result_wrong_type = matrix_23 * v_3d; // double * float

    // 应该进行显式转换
    Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;

    // .transpose()  矩阵转置
    cout << "[1,2,3; 4,5,6]*[4,5,6]:\n"
         << result.transpose() << endl;

    // 不能混淆矩阵的维度:
    // Matrix<double, 2, 3> result_wrong_dimension = matrix_23.cast<double>() * v_3d;

    // 矩阵运算： 四则运算(+-*/)不做演示

    // 随机数矩阵
    matrix_33 = Matrix3d::Random();
    cout << "random matrix:\n"
         << matrix_33 << endl;
    // 矩阵转置
    cout << "transpose:\n"
         << matrix_33.transpose() << endl;
    // 各元素求和
    cout << "sum: " << matrix_33.sum() << endl;
    // 矩阵的迹trace
    cout << "trace: " << matrix_33.trace() << endl;
    // 矩阵数乘
    cout << "times 10: \n"
         << 10 * matrix_33 << endl;
    // 逆
    cout << "inverse:\n"
         << matrix_33.inverse() << endl;
    // 行列式子
    cout << "det: " << matrix_33.determinant() << endl;

    // 特征值
    // 实对称矩阵可以保证对角化成功
    SelfAdjointEigenSolver<Matrix3d> eigen_solver(matrix_33.transpose() * matrix_33);
    cout << "Eigen values = \n"
         << eigen_solver.eigenvalues() << endl; // 特征值
    cout << "Eigen vectors = \n"
         << eigen_solver.eigenvectors() << endl; // 特征向量
    return 0;
}
