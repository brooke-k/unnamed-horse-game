/**
 * @file Main.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 16/Feb/2022
 *
 */

#include <iostream>
#include "../source/headers/Equine.hpp"
#include "../source/headers/EquineEnums.hpp"
#include "../source/headers/Mundane.hpp"

using namespace std;

int main(void)
{
  Equine ranchDressing('F', -1);
  Mundane notRanch("Not Ranch", 'F', 14, RIDING, true, true);
  cout << ranchDressing;
  cout << notRanch;

  rang return 0;
}