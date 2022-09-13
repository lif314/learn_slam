/**
 * @file 2-solve_equations.cpp
 * @author your name (you@domain.com)
 * @brief 矩阵解方程
 * @version 0.1
 * @date 2022-09-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <ctime>

// Eigen核心部分
#include <eigen3/Eigen/Core>
// 稠密矩阵的代数运算(求逆、特征值等)
#include <eigen3/Eigen/Dense>

using namespace std;
using namespace Eigen;

#define MATRIX_SIZE 50

int main(int argc, char const *argv[])
{
    // 求解矩阵特征值
    Matrix3d matrix_33 = Matrix3d::Zero(); // 初始化为0矩阵
    matrix_33 = Matrix3d::Random();        // 随机化

    // 输出
    cout << "random matrix:\n"
         << matrix_33 << endl;

    /**
     * @brief 矩阵的特征值和特征向量
     * Ax=lamda x, 其中 x != 0
     * x是特征向量
     * lamda是特征值
     */
    // adjoint 伴随
    // 实对陈矩阵可以保证对角化成功
    SelfAdjointEigenSolver<Matrix3d> eigen_solver(matrix_33.transpose() * matrix_33);
    // 特征值
    cout << "Eigen values: \n"
         << eigen_solver.eigenvalues() << endl;
    // 特征向量
    cout << "Eigen vectors: \n"
         << eigen_solver.eigenvectors() << endl;

    // 解方程
    // 求解 matrix_NN * x = v_Nd 方程
    // 直接求逆自然是最直接的，但是运算量较大

    Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN; // 50*50
    matrix_NN = MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);

    matrix_NN = matrix_NN * matrix_NN.transpose(); // 保证半正定 z^T M Z >= 0
    Matrix<double, MATRIX_SIZE, 1> v_Nd = MatrixXd::Random(MATRIX_SIZE, 1);

    // 计时
    clock_t time_stt = clock();
    // 直接求逆
    Matrix<double, MATRIX_SIZE, 1> x = matrix_NN.inverse() * v_Nd;
    cout << "time of normal inverse is " << 1000 * (clock() - time_stt) / (double)CLOCKS_PER_SEC << "ms" << endl;
    cout << "x = " << x.transpose() << endl;

    // 通常用矩阵分解来求解，例如QR分解。 速度会快很多
    time_stt = clock();
    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout << "time of QR decomposition is " << 1000 * (clock() - time_stt) / (double)CLOCKS_PER_SEC << "ms" << endl;
    cout << "x = " << x.transpose() << endl;

    // 对于正定矩阵，可以使用cholesky分解来解方程
    time_stt = clock();
    x = matrix_NN.ldlt().solve(v_Nd);
    cout << "time  of ldlt decomposition s " << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << endl;
    cout << "x = " << x.transpose() << endl;

    return 0;
}
