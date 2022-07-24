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

  os << cc.codeToString() << endl;
  return os;
}

// Getters and Setters
unsigned long int CoatCode::getCodeAsULong() const
{
  return code;
}

bitset<32> CoatCode::getCodeAsBitSet32() const
{
  return codeSet;
}

string CoatCode::getCodeAsString() const
{
  return to_string(code);
}

string CoatCode::getCoatName() const
{
  return coatName;
}

void CoatCode::setCoatName(string coatName)
{
  this->coatName = coatName;
}

string CoatCode::codeToString()
{
  string infoString = "\n\r|-- COAT CODE DATA --|";
  infoString.append("\n\r  Full Decimal Code: ");
  infoString.append(to_string(code));
  infoString.append("\n\r  Full Binary Code: ");
  infoString.append(getCodeAsBitSet32().to_string());
  infoString.append("\n\r  Sectioned bin: ");
  infoString.append((getSectionedBin()));
  return infoString;
}

string CoatCode::getSectionedBin()
{
  string sectionedBin = "";
  for (int i = 31; i >= 0; i--)
  {
    sectionedBin.append(to_string(codeSet[i]));
    if (i == 26 || i == 14 || i == 10) // i is at the last value of a code section
    {
      sectionedBin.append("-");
    }
  }
  return sectionedBin;
}

// Calculators

// Static Methods

// Misc/Bug Finding
