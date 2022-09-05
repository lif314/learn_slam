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

int main(int argc, char const *argv[])
{
    Matrix<float, 2, 3> matrix_23;
    matrix_23 << 1, 2, 3, 4, 5, 6;
    cout << "Matrix_23=\n" << matrix_23 << endl;
    
    
    return 0;
}
