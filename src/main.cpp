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
#ifndef PRINTFORM
#define PRINTFORM
#include "./classes/include/utilities/printForm.hpp"
#endif // PRINTFORM

using namespace std;

void startUpMessages();

int main(void)
{
  startUpMessages();
  // bitset<32> manusetA(0);
  // bitset<32> manusetB(0);
  // manusetA[1] = 1;
  // manusetB[1] = 1;
  // manusetB[0] = 1;
  // // manusetB[14] = 1;
  // // manusetB[18] = 1;
  // srand(time(NULL));
  // // unsigned long int randVal = rand();

  // Coat cA(manusetA.to_ulong());
  // Coat cB(manusetB.to_ulong());
  // // testBase.minPrint();
  // cA.fullPrint();
  // cB.fullPrint();

  Equid EEE("Cabbage", "Garden Friend", chestnut ^ sabino, 'G', 15.3, 9);

  while (true)
  {
    EEE.createCustomEquid();
  }

  return 0;
}

void startUpMessages()
{
  printTopBorder();
  printFormLine("UNNAMED HORSE GAME", "", 1);
  printFormLine("Welcome!", "", 2);
  printBottomBorder();
  return;
}