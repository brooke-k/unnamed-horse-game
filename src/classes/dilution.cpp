/**
 * @file dilution.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 21/Jul/2022
 *
 */

#include "./include/dilutionCoat.hpp"
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

bool Dilution::hasDilutions()
{
  unsigned long int allDiluteUL = ALL_DILUTION;
  bitset<32> allDilute(allDiluteUL);
  bitset<32> bitCode(code);
  bitset<32> andedCode = allDilute & bitCode;
  return andedCode.any();
}