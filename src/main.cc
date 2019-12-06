#include <ros/ros.h>

#include "libAdd.h"

using namespace std;

int main(int argc, char* argv[]) {
  //初始化， 在C++调用matlab时，必须要进行初始化。  
  if (!libAddInitialize()) {
    printf("Could not initialize !");
    return -1;
  }
  double a[3] = {1, 2, 3};
  mwArray m_a(3, 1, mxDOUBLE_CLASS);
  m_a.SetData(a, 3);
  double b[3] = {4, 5, 6};
  mwArray m_b(3, 1, mxDOUBLE_CLASS);
  m_b.SetData(b, 3);
  mwArray result;
  add(3, result, m_b, m_b);
  libAddTerminate();
  return 0;
}
