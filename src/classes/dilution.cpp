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

string Dilution::getDilutionCoatName()
{
  return dilutionCoatName;
}

string Dilution::getDiluteAlleles()
{

  string temp[] = {"cr", "cr", "ch", "ch", "prl", "prl", "z", "z"};
  bitset<12> dset = getDiluteSet();
  string alleleString = "";
  for (int i = 12, t = 0; i >= 5; i--, t++)
  {
    cout << "dset: " << dset[i] << " at i=" << i << endl;
    if (dset[i])
    {
      cout << "uppered" << endl;
      temp[t].at(0) = toupper(temp[t].at(0));
    }
    alleleString.append(temp[t]);
  }
  return alleleString;
}

ostream &operator<<(ostream &os, Dilution &dl)
{
  os << dl.diluteToString() << endl;
  return os;
}

string Dilution::diluteToString()
{

  // string infoString = ((BaseCoat)(*this)).toString();
  string infoString = baseToString();
  if (hasDilutions())
  {
    infoString.append("\n\r  Dilution code: ");
    infoString.append(to_string(getDiluteSet().to_ullong()));
    infoString.append(", ");
    infoString.append(getDiluteAlleles());
    infoString.append("\n\r  Dilution Bin: ");
    infoString.append(getDiluteSet().to_string());
    infoString.append("\n\r  Dilution name: ");
    infoString.append(getDilutionCoatName());
  }
  else
  {
    infoString.append("\n\r  Dilutions: None");
  }
  return infoString;
}

string Dilution::calculateDilutionCoatName()
{
  return calculateDilutionCoatName(getBaseSet(), getDiluteSet());
}

string Dilution::calculateDilutionCoatName(bitset<32> fset)
{
  bitset<6> bset(0);
  bitset<12> dset(0);
  for (int i = 31; i >= 14; i--)
  {
    if (i >= 26)
    {
      bset[i - 26] = fset[i];
    }
    else
    {
      dset[i - 14] = fset[i];
    }
  }
  return calculateDilutionCoatName(bset, dset);
}

string Dilution::calculateDilutionCoatName(bitset<6> bset, bitset<12> dset)
{
  string dilutionName = getBaseCoatName();
  if (dilutionName.compare("White") == 0)
  {
    return "White";
  }
  else if (dilutionName.compare("Bay") == 0)
  {
    dilutionName = calculateBayDilutions(dset);
  }
  else if (dilutionName.compare("Red") == 0)
  {
    dilutionName = calculateRedDilutions(dset);
  }
  else
  {
    dilutionName = calculateBlackDilutions(dset);
  }
  dilutionName.append(calculateDunPresence(dset));
  return dilutionName;
}

string Dilution::calculateDilutionCoatName(unsigned long int fcode)
{
  return calculateDilutionCoatName(bitset<32>(fcode));
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
