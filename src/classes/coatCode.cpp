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

  os << cc.toString() << endl;
  return os;
}

// Getters and Setters
unsigned long int CoatCode::getCodeAsULong() const
{
  return code;
}

bitset<32> CoatCode::getCodeAsBitSet32() const
{
  return bitset<32>(code);
}

string CoatCode::getCodeAsString() const
{
  return to_string(code);
}

string CoatCode::toString()
{
  string infoString = "\n\r|-- COAT CODE DATA --|";
  infoString.append("\n\r  Full Decimal Code: ");
  infoString.append(to_string(code));
  return infoString;
}

// Calculators

// Static Methods

// Misc/Bug Finding
