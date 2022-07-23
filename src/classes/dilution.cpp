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

// Getters and Setters

bool Dilution::hasDilutions()
{
  unsigned long int bcode = getCodeAsULong();
  unsigned long int allDiluteUL = 67092480;
  bitset<32> allDilute(allDiluteUL);
  bitset<32> bitCode(bcode);
  unsigned long int temp = allDiluteUL & bcode;
  bitset<32> anded(temp);
  return anded.any();
}

bitset<32> Dilution::getDiluteBitset32()
{
  return bitset<32>(diluteCode);
}

bitset<12> Dilution::getDiluteBitset12()
{
  return diluteSet;
}

unsigned long int Dilution::getDilute()
{
  return diluteCode;
}

ostream &operator<<(ostream &os, Dilution &dl)
{
  os << dl.diluteToString() << endl;
  return os;
}
string Dilution::getDiluteBin()
{
  return (bitset<12>(diluteCode)).to_string();
}

string Dilution::diluteToString()
{

  // string infoString = ((BaseCoat)(*this)).toString();
  string infoString = baseToString();
  if (hasDilutions())
  {
    infoString.append("\n\r  Dilution code: ");
    infoString.append(to_string(getDilute()));
    infoString.append("\n\r  Dilution Bin: ");
    infoString.append(getDiluteBin());
  }
  else
  {
    infoString.append("\n\r  Dilutions: None");
  }
  return infoString;
}

string Dilution::calculateDilutionCoat()
{
  bitset<32> bset = getCodeAsBitSet32();
  string coatName = getBaseName();

  if (bset[0] || bset[1]) // White coats do not have any possible dilutions
  {
    coatName = "White";
  }
  else if (diluteSet.to_ulong() < 4) // Matches all red coats
  {
    coatName = calculateRedDilutions();
  }
  else if (!(bset[4] || bset[5])) // Matches all black coats
  {
    coatName = calculateBlackDilutions();
  }
  else // Matches all remaining (bay) dilutions
  {
    coatName = calculateBayDilutions();
  }
  return coatName;
}