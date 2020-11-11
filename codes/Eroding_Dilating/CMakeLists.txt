cmake_minimum_required(VERSION 3.16)
project(Eroding_Dilating)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
add_executable(Eroding_Dilating main.cpp)

file(GLOB OPENCV_LIBS /usr/local/lib/*opencv*.4.5.0.dylib)
message(STATUS 'opencv_lib find: ${OPENCV_LIBS}')
target_link_libraries(Eroding_Dilating ${OPENCV_LIBS})
