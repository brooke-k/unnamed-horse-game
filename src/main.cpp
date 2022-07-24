/**
 * @file main.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 19/Jul/2022
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include "./classes/include/coat.hpp"

using namespace std;

int main(void)
{
  bitset<32> maxCalc(0);
  maxCalc.set();
  srand(time(NULL));
  unsigned long int randVal = rand();

  Coat testBase(randVal);
  cout << testBase << endl;

  cout << "END" << endl;

  return 0;
}
