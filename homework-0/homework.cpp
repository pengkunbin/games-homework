#include <iostream>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<cmath>
#include "homework.h"

#define PI 3.14159

int homework()
{   
    // 初始化(2,1)的点
    Eigen::Vector3f v(2.0f, 1.0f, 1.0f);
    
    std::cout <<  getTransfromMatrix(-45 * PI / 180.0f, 1, 2) << std::endl;

    // 逆时针旋转45度, 并且平移 (1, 2)
    std::cout <<  getTransfromMatrix(-45 * PI / 180.0f, 1, 2) * v << std::endl;
    return 0;
}

Eigen::Matrix3f getTransfromMatrix(double angle, int x, int y) {
  Eigen::Matrix3f transfromMatrix;
  transfromMatrix << cos(angle), -sin(angle), x, sin(angle), cos(angle), y, 0, 0, 1;

  return transfromMatrix;
}