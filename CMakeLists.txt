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

## MATLAB runtime dir
set(MATLAB_DIR /usr/local/MATLAB/R2019a/)

## Specify additional locations of header files
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${MATLAB_DIR}extern/include/
)

## Declare a C++ executable
add_executable(ros_matlab src/main.cc)

## Specify libraries to link a library or executable target against
target_link_libraries(ros_matlab ${catkin_LIBRARIES})
target_link_libraries(ros_matlab ${MATLAB_DIR}runtime/glnxa64/libmwmclmcrrt.so)
target_link_libraries(ros_matlab ${PROJECT_SOURCE_DIR}/lib/libAdd.so)
