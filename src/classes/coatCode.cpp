/**
 * @file coatCode.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 21/Jul/2022
 *
 */

#include <string>
#include <iostream>
#include <bitset>
#include "./include/coatCode.hpp"
using namespace std;

// Operator Overloads

ostream &operator<<(ostream &os, CoatCode &cc)
{

  unsigned long int rawCode = cc.getRawCode();
  bitset<32> bset(rawCode);

  os << "|-- COAT CODE DATA --|" << endl;
  os << "  Code: " << bset << endl;
  BaseCoat tc;
  os << tc.getBaseAsString(bset) << endl;
  bitset<32> beans(0);

  os
      << tc.getBaseAsString(beans) << endl;

  return os;
}

// Getters and Setters

unsigned long int CoatCode::getRawCode()
{
  return code;
}

// Calculators

// Static Methods
unsigned long int CoatCode::baseCoatTrue()
{
  bitset<32> baseSet{0x0};
  for (int i = 0; i < 6; i++)
  {
    baseSet.set(i, true);
  }
  return baseSet.to_ulong();
}
