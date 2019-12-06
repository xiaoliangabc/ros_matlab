cmake_minimum_required(VERSION 2.8.3)
project(ros_matlab)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
)

## The catkin_package macro generates cmake config files for your package
catkin_package(
)

## Specify additional locations of header files
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)


set(MATLAB_ROOT /usr/local/MATLAB/R2019a/)
include_directories(${MATLAB_ROOT}extern/include/)
LINK_DIRECTORIES(${MATLAB_ROOT}runtime/glnxa64/)

## Declare a C++ executable
add_executable(ros_matlab src/main.cc src/libAdd.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(ros_matlab ${catkin_LIBRARIES})
target_link_libraries(ros_matlab -lmwmclmcrrt)
target_link_libraries(ros_matlab ${PROJECT_SOURCE_DIR}/src/libAdd.so)
