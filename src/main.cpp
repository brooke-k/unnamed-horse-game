/**
 * @file main.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 19/Jul/2022
 *
 */

#include <iostream>

#include "./classes/include/baseCoat.hpp"

using namespace std;

int main(void)
{

  BaseCoat testCoat;
  BaseCoat testCoat2(false, true, false);
  BaseCoat t3(2);
  // BaseCoat t4 = t3;
  cout << testCoat << endl;
  cout << testCoat2 << endl;
  cout << t3 << endl;
  // cout << t4 << endl;
  testCoat2 = testCoat;
  cout << testCoat2 << endl;

  cout << "END PROGRAM" << endl;

  return 0;
}
