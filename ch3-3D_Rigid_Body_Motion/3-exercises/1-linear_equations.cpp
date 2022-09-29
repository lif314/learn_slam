/**
 * 求解线性方程组 Ax=b
 */

#include <iostream>
#include <ctime>

// Eigen核心部分
#include <eigen3/Eigen/Core>
// 稠密矩阵的代数运算
#include <eigen3/Eigen/Dense>

using namespace std;
using namespace Eigen;

#define MATRIX_SIZE 50

int main(int argc, char const *argv[])
{
    // 初始化矩阵
    Matrix<double, MATRIX_SIZE, MATRIX_SIZE> A;
    A = MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    // 初始化向量
    Matrix<double, MATRIX_SIZE, 1> b = MatrixXd::Random(MATRIX_SIZE, 1);
    // 求解Ax=b
    Matrix<double, MATRIX_SIZE, 1> x;
    // 计时器
    clock_t time_start = clock();

    // 方法1：求逆运算
    x = A.inverse() * b;
    cout << "Inverse time: " << 1000 * (clock() - time_start) << " ms" << endl;
    cout << "x = " << x.transpose() << endl;

    // 方法2：partial pivoting LU decomposition
    time_start = clock();
    x = A.partialPivLu().solve(b);
    cout << "partialPivLu time: " << 1000 * (clock() - time_start) << " ms" << endl;
    cout << "x = " << x.transpose() << endl;

    // 方法3：full pivoting LU decomposition
    time_start = clock();
    x = A.fullPivLu().solve(b);
    cout << "fullPivLu time: " << 1000 * (clock() - time_start) << " ms" << endl;
    cout << "x = " << x.transpose() << endl;


    // 方法4：householderQr
    time_start = clock();
    x = A.householderQr().solve(b);
    cout << "householderQr time: " << 1000 * (clock() - time_start) << " ms" << endl;
    cout << "x = " << x.transpose() << endl;

    // 方法5：colPivHouseholderQr()
    time_start = clock();
    x = A.colPivHouseholderQr().solve(b);
    cout << "colPivHouseholderQr time: " << 1000 * (clock() - time_start) << " ms" << endl;
    cout << "x = " << x.transpose() << endl;

    // 方法6：fullPivHouseholderQr
    time_start = clock();
    x = A.fullPivHouseholderQr().solve(b);
    cout << "fullPivHouseholderQr time: " << 1000 * (clock() - time_start) << " ms" << endl;
    cout << "x = " << x.transpose() << endl;


    // 方法7：completeOrthogonalDecomposition()	
    time_start = clock();
    x = A.completeOrthogonalDecomposition().solve(b);
    cout << "completeOrthogonalDecomposition time: " << 1000 * (clock() - time_start) << " ms" << endl;
    cout << "x = " << x.transpose() << endl;



    // 方法8：llt()
    time_start = clock();
    x = A.llt().solve(b);
    cout << "llt time: " << 1000 * (clock() - time_start) << " ms" << endl;
    cout << "x = " << x.transpose() << endl;



    // 方法9：ldlt()
    time_start = clock();
    x = A.ldlt().solve(b);
    cout << "ldlt time: " << 1000 * (clock() - time_start) << " ms" << endl;
    cout << "x = " << x.transpose() << endl;



    // 方法10：bdcSvd
    time_start = clock();
    x = A.bdcSvd().solve(b);
    cout << "bdcSvd time: " << 1000 * (clock() - time_start) << " ms" << endl;
    cout << "x = " << x.transpose() << endl;


    // 方法11：jacobiSvd()
    time_start = clock();
    x = A.jacobiSvd().solve(b);
    cout << "jacobiSvd time: " << 1000 * (clock() - time_start) << " ms" << endl;
    cout << "x = " << x.transpose() << endl;
    return 0;
}
