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

string Dilution::getDiluteString()
{
  return diluteName;
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
    infoString.append("\n\r  Dilution name: ");
    infoString.append(getDiluteString());
  }
  else
  {
    infoString.append("\n\r  Dilutions: None");
  }
  return infoString;
}

string Dilution::calculateDilutionCoat()
{
  bitset<6> bset = getBaseBitset6();
  bitset<12> dset = getDiluteBitset12();
  string coatName = getBaseName();

  if (bset[5] || bset[4]) // White coats do not have any possible dilutions
  {
    this->diluteName = "White";
    return diluteName;
  }
  else if (!(bset[3] || bset[2])) // Matches all red coats
  {
    coatName = calculateRedDilutions(dset);
  }
  else if (!(bset[0] || bset[1])) // Matches all black coats
  {
    coatName = calculateBlackDilutions(dset);
  }
  else // Matches all remaining (bay) dilutions
  {
    coatName = calculateBayDilutions(dset);
  }
  coatName.append(calculateDunPresence(dset));
  this->diluteName = coatName;
  return diluteName;
}

string Dilution::calculateRedDilutions(bitset<12> dset)
{

  string coatName = "Red";
  if (dset[8] || dset[9]) // Ch/Ch or Ch/N
  {
    coatName = "Gold";
  }
  else if (dset[6] || dset[7]) // Cr/Cr or Cr/N
  {
    if (dset[6] && dset[7]) // Cr/Cr
    {
      coatName = "Cremello";
    }
    else
    {
      if (dset[10] || dset[11]) // Cr/Prl
      {
        coatName = "Pseudo-cremello";
      }
      else // Cr/N
      {
        coatName = "Palomino";
      }
    }
  }
  else if (dset[10] && dset[11])
  {
    coatName = "Apricot";
  }

  return coatName;
}

string Dilution::calculateBayDilutions(bitset<12> dset) { return "N/A"; }

string Dilution::calculateBlackDilutions(bitset<12> dset) { return "N/A"; }

string Dilution::calculateDunPresence(bitset<12> dset)
{
  if (dset[3] || dset[1]) // D/D, D/nd1, D/nd2 genotype
  {
    return "-base dun with primitive markings";
  }
  else if (!(dset[2] || dset[0])) // nd2/nd2 genotype
  {
    return "";
  }
  else // nd2/nd1
  {
    return " with primitive markings";
  }
}
