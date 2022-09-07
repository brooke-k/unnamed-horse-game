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
#include "./classes/include/equines/equid.hpp"

using namespace std;

int main(void)
{
  bitset<32> maxCalc(0);
  maxCalc.set();
  srand(time(NULL));
  // unsigned long int randVal = rand();

  Coat c(rand());
  // testBase.minPrint();
  c.fullPrint();
  cout
      << "END" << endl;

  return 0;
}
