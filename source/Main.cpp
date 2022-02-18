/**
 * @file Main.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 16/Feb/2022
 *
 */

#include <iostream>
#include "../source/headers/Equine.hpp"

using namespace std;

int main(void)
{
  Equine beefHorse("Beebe");
  Equine wild1('F');
  Equine wild2('F', 4);
  Equine beens("Beens 'n' Paste", 'G');
  cout
      << beefHorse;
  cout << wild1;
  cout << beens;

  return 0;
}