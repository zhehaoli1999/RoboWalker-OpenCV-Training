cmake_minimum_required(VERSION 3.16)
project(Filters)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
add_executable(Filters main.cpp)

file(GLOB OPENCV_LIBS /usr/local/lib/*opencv*.4.5.0.dylib)
#message(STATUS 'opencv_lib find: ${OPENCV_LIBS}')
target_link_libraries(Filters ${OPENCV_LIBS})
