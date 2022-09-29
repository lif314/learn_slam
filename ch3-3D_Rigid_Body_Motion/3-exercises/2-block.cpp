/**
 * 从矩阵中取出分快
 */
 
 #include <iostream>
 #include <eigen3/Eigen/Core>

using namespace std;
using namespace Eigen;

 #define MATRIX_SIZE 50

int main(int argc, char const *argv[])
{
    Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_nn;
    matrix_nn = MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);

    //  方法1
    Matrix3d matrix_33 = Matrix3d::Zero();
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            matrix_33(i,j) = matrix_nn(i,j);
    cout << "I(3*3) = \n" << matrix_33 << endl;

    // 方法2
    matrix_33 = matrix_nn.block(0,0, 3,3);
    cout << "I(3*3) = \n" << matrix_33 << endl;
    return 0;
}
