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

  BaseCoat beans(false, true);

  BaseCoat b = BaseCoat();
  cout << b.getBaseCoatColour() << endl;
  cout << beans.getBaseCoatColour() << endl;

  cout << "END" << endl;
  return 0;
}
