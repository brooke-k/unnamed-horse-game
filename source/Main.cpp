/**
 * @file Main.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 16/Feb/2022
 *
 */

#include <iostream>
#include "../source/headers/Equine.hpp"
#include "../source/headers/EquineEnums.hpp"

using namespace std;

int main(void)
{
  Equine ranchDressing('F', -1);
  cout << ranchDressing;
  return 0;
}