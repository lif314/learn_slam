#include <unistd.h>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
#include <iostream>
#include <fstream>

#include <pangolin/pangolin.h>

using namespace std;
using namespace Eigen;

/**
 * @brief
 * - 轨迹文件 trajectory.txt
 *      - 格式  time, t_x, t_y, t_z, q_x, q_y, q_z, q_w
 *      - 世界坐标系下，t为平移，q为旋转四元数
 * - 机器人的位姿
 *      T_{WR}/T_{RW}
 * - "轨迹"严格来说是机器人(相机)坐标系的原点在世界坐标系中的坐标
 *      - 机器人坐标的原点为O_R, 此时O_w就是这个原点在世界坐标系下的坐标
 *      - O_w = T_{WR}O_R = t_{WR}
 * - 库：Pangolin -- 安装教程：https://blog.csdn.net/weixin_44354586/article/details/89399289
 */

// 轨迹文件路径
string trajectory_file = "./trajectory.txt";

void DrawTrajectory(vector<Isometry3d, Eigen::aligned_allocator<Isometry3d>>);

int main(int argc, char const *argv[])
{
    // 位姿
    vector<Isometry3d, aligned_allocator<Isometry3d>> poses;

    // 读文件
    ifstream fin(trajectory_file);
    if (!fin)
    {
        cout << "cannot find trajectory file at " << trajectory_file << endl;
        return 1;
    }

    // 读取数据, 初始化 poses
    while (!fin.eof())
    {
        double time, tx, ty, tz, qx, qy, qz, qw;
        fin >> time >> tx >> ty >> tz >> qx >> qy >> qz >> qw;
        Isometry3d Twr(Quaterniond(qw, qx, qy, qz));
        Twr.pretranslate(Vector3d(tx, ty, tz));
        poses.push_back(Twr);
    }

    cout << "read total " << poses.size() << " pose entries" << endl;

    // 绘制轨迹地图
    DrawTrajectory(poses);

    return 0;
}

void DrawTrajectory(vector<Isometry3d, Eigen::aligned_allocator<Isometry3d>> poses)
{
    // 创建Pangolin桌面和绘制轨迹地图
    pangolin::CreateWindowAndBind("Trajectory Viewer", 1024, 768);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    pangolin::OpenGlRenderState s_cam(
        pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
        pangolin::ModelViewLookAt(0, -0.1, -1.8, 0, 0, 0, 0.0, -1.0, 0.0));

    // Pangolin API Change: Display::SetBounds must be used with Attach::Pix or Attach::ReversePix to specify pixel bounds relative to an edge. See the code samples for details
    // pangolin::View &d_cam = pangolin::CreateDisplay()
    // .SetBounds(0.0, 1.0, 0.0, -1024.0f / 768.0f)
    // .SetHandler(new pangolin::Handler3D(s_cam));

    pangolin::View &d_cam = pangolin::CreateDisplay()
                                .SetBounds(0.0f, 1.0f, 0.0f, pangolin::Attach::Pix(1024), -1024.0f / 768.0f)
                                .SetHandler(new pangolin::Handler3D(s_cam));

    while (pangolin::ShouldQuit() == false)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        d_cam.Activate(s_cam);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glLineWidth(2);

        for (size_t i = 0; i < poses.size(); i++)
        {
            // 画每个位姿的三个坐标轴
            // 初始化位姿
            Vector3d Ow = poses[i].translation();
            Vector3d Xw = poses[i] * (0.1 * Vector3d(1, 0, 0));
            Vector3d Yw = poses[i] * (0.1 * Vector3d(0, 1, 0));
            Vector3d Zw = poses[i] * (0.1 * Vector3d(0, 0, 1));

            glBegin(GL_LINES);
            glColor3f(1.0, 0.0, 0.0);
            glVertex3d(Ow[0], Ow[1], Ow[2]);
            glVertex3d(Xw[0], Xw[1], Xw[2]);

            glColor3f(0.0, 1.0, 0.0);
            glVertex3d(Ow[0], Ow[1], Ow[2]);
            glVertex3d(Yw[0], Yw[1], Yw[2]);

            glColor3f(0.0, 0.0, 1.0);
            glVertex3d(Ow[0], Ow[1], Ow[2]);
            glVertex3d(Zw[0], Zw[1], Zw[2]);
            glEnd();
        }

        // 画出连线
        for (size_t i = 0; i < poses.size(); i++)
        {
            glColor3f(0.0, 0.0, 0.0);
            glBegin(GL_LINES);
            auto p1 = poses[i], p2 = poses[i + 1];
            glVertex3d(p1.translation()[0], p1.translation()[1], p1.translation()[2]);
            glVertex3d(p2.translation()[0], p2.translation()[1], p2.translation()[2]);
            glEnd();
        }
        pangolin::FinishFrame();
        usleep(5000); // sleep 5 ms
    }
}