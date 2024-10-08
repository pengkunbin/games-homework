#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

constexpr double MY_PI = 3.1415926;
inline double deg2rad(double deg) { return deg * MY_PI / 180; }

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0], 0, 1, 0, -eye_pos[1], 0, 0, 1,
        -eye_pos[2], 0, 0, 0, 1;

    view = translate * view;

    return view;
}

Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.

    double rad = deg2rad(rotation_angle);
    model << cos(rad), -sin(rad), 0, 0,
        sin(rad), cos(rad), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1;

    return model;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
                                      float zNear, float zFar)
{
    // Students will implement this function

    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the projection matrix for the given parameters.
    // Then return it.
    float top = -tan(deg2rad(eye_fov / 2.0f) * abs(zNear));
    float right = top * aspect_ratio;

    projection << zNear / right, 0, 0, 0,
        0, zNear / top, 0, 0,
        0, 0, (zNear + zFar) / (zNear - zFar), (2 * zNear * zFar) / (zFar - zNear),
        0, 0, 1, 0;

    return projection;
}

int main(int argc, const char **argv)
{
    float angle = 0;
    bool command_line = false;

    // 创建一个 700 * 700 分辨率的渲染器
    rst::rasterizer r(700, 700);

    // 将摄像机的位置摆放在 (0,0,5) 坐标上
    Eigen::Vector3f eye_pos = {0, 0, 5};

    // 初始化三个点
    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};
    // 初始化一个点
    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    // std::cout << "pos_id: " << pos_id;
    auto ind_id = r.load_indices(ind);
    // std::cout << "ind_id: " << ind_id;

    int key = 0;
    int frame_count = 0;

    while (key != 27)
    {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        // 通过 opencv 打开一个可视窗口
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);

        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a')
        {
            angle += 10;
        }
        else if (key == 'd')
        {
            angle -= 10;
        }
    }

    return 0;
}
