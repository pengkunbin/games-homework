# 项目名称

## 简介
该项目是一个基于光栅化技术的渲染器实现，使用了Eigen库进行矩阵和向量运算，并结合OpenCV库进行图像处理。项目包含了多个作业，每个作业实现了不同的渲染技术和功能。

## 依赖
- Eigen3
- OpenCV
- C++17

## 编译和运行

1. 安装CMake（如果尚未安装）：
   ```bash
   brew install cmake
   ```
2. 进入到每个子文件夹中
   ```bash
   sh start.sh
   ```

## 功能描述

### 作业1
- 实现了基本的光栅化渲染器，支持加载顶点和索引数据，并进行简单的三角形绘制。
- 主要代码文件：
  - `main.cpp`：包含了渲染器的初始化和主循环逻辑。
  - `rasterizer.hpp`：定义了光栅化渲染器的接口和数据结构。
  - `rasterizer.cpp`：实现了光栅化渲染器的具体功能。

### 作业2
- 增加了深度缓冲区，实现了基本的深度测试。
- 主要代码文件：
  - `main.cpp`：包含了渲染器的初始化和主循环逻辑。
  - `rasterizer.hpp`：定义了光栅化渲染器的接口和数据结构。
  - `rasterizer.cpp`：实现了光栅化渲染器的具体功能。

### 作业3
- 增加了法线贴图和位移贴图的支持，实现了更为复杂的光照模型。
- 主要代码文件：
  - `main.cpp`：包含了渲染器的初始化和主循环逻辑。
  - `rasterizer.hpp`：定义了光栅化渲染器的接口和数据结构。
  - `rasterizer.cpp`：实现了光栅化渲染器的具体功能。
  - `OBJ_Loader.h`：用于加载OBJ模型文件。

## 代码示例

### 加载顶点和索引数据

cpp:homework-1/main.cpp
startLine: 73
endLine: 79

### 设置模型、视图和投影矩阵

cpp:homework-2/rasterizer.cpp
startLine: 121
endLine: 157

### 法线贴图和位移贴图

cpp:homework-3/main.cpp
startLine: 202
endLine: 259

## 贡献
欢迎提交Pull Request来贡献代码，或者通过提交Issue来报告问题。

## 许可证
该项目使用MIT许可证，详情请参阅LICENSE文件。

希望这个README能够帮助你更好地理解和使用该项目。如果有任何问题，请随时联系我。