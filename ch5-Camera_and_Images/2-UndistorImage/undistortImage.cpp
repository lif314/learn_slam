/**
 * @file undistorImage.cpp
 * @author your name (you@domain.com)
 * @brief 图像去畸变
 * @version 0.1
 * @date 2022-09-30
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <opencv2/opencv.hpp>
#include <string>

using namespace std;

// 图像路径
string image_file = "./distorted.png";

int main(int argc, char const *argv[])
{
    /**
     * @brief 图像去畸变代码
     * 自己实现去畸变流程，也可以调用OpenCV中的函数
     */

    // 畸变参数
    double k1 = -0.28340811, k2 = 0.07395907, p1 = 0.00019359, p2 = 1.76187114e-05;
    // 内参: 单位是像素
    double fx = 458.654, fy = 457.296, cx = 367.215, cy = 248.375;

    //读取图像：图像是灰度图，CV_8UC1
    cv::Mat image = cv::imread(image_file, 0);
    int rows = image.rows, cols = image.cols;

    // 去畸变后的图像：初始为空
    cv::Mat image_undistort = cv::Mat(rows, cols, CV_8UC1);

    // 通过在空的去畸变的像素位置上，找到对应的像素值
    for (int v = 0; v < rows; v++)
    {
        for (int u = 0; u < cols; u++)
        {
            // 按照公式，计算(u,v)对应畸变图像中的坐标(u_distorted, v_distorted)
            double x = (u - cx) / fx, y = (v - cy) / fy; // 从像素平面转化到归一化平面上
            double r = sqrt(x * x + y * y);

            // 归一化平面：畸变呈多项式关系
            double x_distorted = x * (1 + k1 * r * r + k2 * r * r * r * r) + 2 * p1 * x * y + p2 * (r * r + 2 * x * x);
            double y_distorted = y * (1 + k1 * r * r + k2 * r * r * r * r) + p1 * (r * r + 2 * y * y) + 2 * p2 * x * y;

            // 回到像素平面
            double u_distorted = fx * x_distorted + cx;
            double v_distorted = fy * y_distorted + cy;

            //  赋值(最近邻插值算法)
            if (u_distorted >= 0 && v_distorted >= 0 && u_distorted < cols && v_distorted < rows)
            {
                image_undistort.at<uchar>(v, u) = image.at<uchar>((int) v_distorted, (int) u_distorted);
            }else
            {
                image_undistort.at<uchar>(v,u) = 0;
            }
        }
    }

    // 画图去畸变的图像
    cv::imshow("distored", image);
    cv::imshow("undistorted", image_undistort);
    cv::waitKey();

    return 0;
}
