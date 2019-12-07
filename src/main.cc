#include <ros/ros.h>

#include "ros_matlab/libAdd.h"

using namespace std;

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "ros_matlab");
  
  // Initialize the MATLAB Compiler Runtime global state
  if (!mclInitializeApplication(NULL, 0)) {
    ROS_ERROR("Could not initialize the application properly.");
    return -1;
  }

  // Initialize the Vigenere library
  if (!libAddInitialize()) {
    ROS_ERROR("Could not initialize the library properly.");
    return -1;
  }

  double a[3] = {1, 2, 3};
  mwArray m_a(3, 1, mxDOUBLE_CLASS);
  m_a.SetData(a, 3);
  double b[3] = {4, 5, 6};
  mwArray m_b(3, 1, mxDOUBLE_CLASS);
  m_b.SetData(b, 3);
  mwArray result;

  // Call matlab function
  add(1, result, m_a, m_b);
  std::cout << result << std::endl;

  // Shut down the library and the application global state.
  libAddTerminate();
  mclTerminateApplication();

  return 0;
}
