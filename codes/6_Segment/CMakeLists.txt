# 设置cmake的最低版本要求
cmake_minimum_required(VERSION 3.16)
# 设置项目名称
project(ImageLightness)

# 设置c++标准
set(CMAKE_CXX_STANDARD 17)

# 指出头文件所在文件夹
include_directories(/usr/local/include)

# 指出链接库所在文件夹
link_directories(/usr/local/lib)

# 指出需要编译生成的可执行文件（术语是target）
add_executable(ImageLightness main.cpp)

# 查找opencv的所有链接库（Mac: .dylib, Windows: .dll, Linux: .a）
file(GLOB OPENCV_LIBS /usr/local/lib/*opencv*.4.5.0.dylib)

# 打印输出找到的opencv链接库
#message(STATUS 'opencv_lib find: ${OPENCV_LIBS}')

# 为ImageLightness这个target添加链接库
target_link_libraries(ImageLightness ${OPENCV_LIBS})
