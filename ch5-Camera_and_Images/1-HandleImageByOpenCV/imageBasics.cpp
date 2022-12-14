/**
 * @file imageBasics.cpp
 * @author your name (you@domain.com)
 * @brief OpenCV图像处理
 * @version 0.1
 * @date 2022-09-30
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

// 时间库，提供计时，时间等功能
#include <chrono>

using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char const *argv[])
{
    // 通过命令行读取图片 argv[1]
    cv::Mat image;
    image = cv::imread(argv[1]); // cv::imread()函数读取指定路径下的图像

    // 判断图像文件是否正确读取
    if (image.data == nullptr) // 数据不存在，可能是文件不存在
    {
        cerr << "文件" << argv[1] << "不存在." << endl;
        return 0;
    }

    // 文件顺利读取，输出文件的基本信息
    cout << "image width: " << image.cols << endl;
    cout << "image heigh: " << image.rows << endl;
    cout << "image channels: " << image.channels() << endl;


    // 显示图像
    cv::imshow("image", image);
    cv::waitKey(0); // 暂停程序，等待一个按键输入

    // 判断图像的类型
    if (image.type() != CV_8UC1 && image.type() != CV_8UC3)
    {
        // 图像类型不符合要求
        cout << "请输入一张彩色图或灰度图." << endl;
        return 0;
    }

    // 遍历图像: 使用std::chrono给算法计时
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    for (size_t y = 0; y < image.rows; y++)
    {
        // 使用cv::Mat::ptr 获得图像行指针
        unsigned char *row_ptr = image.ptr<unsigned char>(y); // row_ptr是第y行的头指针
        for (size_t x = 0; x < image.cols; x++)
        {
            // 访问位于x,y处的像素
            unsigned char *data_ptr = &row_ptr[x * image.channels()]; // data_ptr指向待访问的像素数据

            // 输出该像素的每个通道，如果是灰度图就只有一个通道
            for (int c = 0; c != image.channels(); c++)
            {
                unsigned char data = data_ptr[c]; // data中为I(x,y)第c个通道的值
            }
        }
    }

    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "遍历图像用时：" << time_used.count() << " 秒." << endl;

    // 关于cv::Mat的拷贝
    // 直接赋值并不会拷贝数据
    cv::Mat another_image = image;
    // 修改another_image会导致image产生变化
    another_image(cv::Rect(0, 0, 100, 100)).setTo(0); // 将左上角100*100置为0
    cv::imshow("another image", image);
    cv::waitKey(0);

    // 使用clone函数拷贝数据
    cv::Mat image_clone = image.clone();
    image_clone(cv::Rect(100, 100, 200, 200)).setTo(0);
    cv::imshow("clone image", image_clone);
    cv::waitKey(0);

    // 对于图像还有很多的基本操作
    // 剪切、旋转、缩放等

    cv::destroyAllWindows();
    return 0;
}