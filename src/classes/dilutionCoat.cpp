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

bool DilutionCoat::hasDilutions()
{
  unsigned long int bcode = getCodeAsULong();
  unsigned long int allDiluteUL = 67092480;
  bitset<32> allDilute(allDiluteUL);
  bitset<32> bitCode(bcode);
  unsigned long int temp = allDiluteUL & bcode;
  bitset<32> anded(temp);
  return anded.any();
}

string DilutionCoat::getDilutionCoatName() const
{
  return dilutionCoatName;
}

string DilutionCoat::getDiluteAlleles()
{

  string temp[] = {"Cr", "Cr", "Ch", "Ch", "Prl", "Prl", "Z", "Z"};
  bitset<12> dset = getDiluteSet();
  string alleleString = "";
  for (int i = 0; i < 8; i++)
  {
    if (dset[11 - i])
    {
      alleleString.append(temp[i]);
    }
    else
    {
      alleleString.append("N");
    }

    if (i % 2 == 1)
    {
      alleleString.append("-");
    }
    else if (i < 8)
    {
      alleleString.append("/");
    }
  }
  for (int i = 8; i < 12; i++)
  {

    if (dset[i])
    {
      alleleString.append("D");
    }
    else
    {
      if (dset[i + 1])
      {
        alleleString.append("nd1");
      }
      else
      {
        alleleString.append("nd2");
      }
    }
    if (i == 8)
    {
      alleleString.append("/");
    }
    i++;
  }
  return alleleString;
}

ostream &operator<<(ostream &os, DilutionCoat &dl)
{
  os << dl.diluteToString();
  os << dl.getBottomBorder() << endl;
  return os;
}

string DilutionCoat::diluteToString()
{

  // string infoString = ((BaseCoat)(*this)).toString();
  string infoString = baseToString();
  infoString.append(getPrintSection());
  infoString = addPrintLine(infoString, "COAT DILUTION DATA", 0);
  infoString = addPrintLine(infoString, "Diluted coat: ", getDilutionCoatName(), 1);
  infoString = addPrintLine(infoString, "Code segment: ", getDiluteSet().to_string(), 1);
  infoString = addPrintLine(infoString, "     Alleles: ", getDiluteAlleles(), 1);
  return infoString;
}

void DilutionCoat::setDilutionCoatName(string dilutionCoatName)
{
  this->dilutionCoatName = dilutionCoatName;
}

void DilutionCoat::calculateDilutions()
{
  setDilutionCoatName(calculateDilutionCoatName());
}

string DilutionCoat::calculateDilutionCoatName()
{
  return calculateDilutionCoatName(getBaseSet(), getDiluteSet());
}

string DilutionCoat::calculateDilutionCoatName(bitset<32> fset)
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

string DilutionCoat::calculateDilutionCoatName(bitset<6> bset, bitset<12> dset)
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
  calculateDunPresence(dset, dilutionName);
  return dilutionName;
}

string DilutionCoat::calculateDilutionCoatName(unsigned long int fcode)
{
  return calculateDilutionCoatName(bitset<32>(fcode));
}

string DilutionCoat::calculateRedDilutions(bitset<12> dset)
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

string DilutionCoat::calculateBayDilutions(bitset<12> dset)
{

  string coatName = "Bay";
  bool hasSilver = false;
  if (dset[4] || dset[5]) // Check for silver influence
  {
    hasSilver = true;
  }
  if (dset[8] || dset[9])
  {
    coatName = "Amber";
  }
  else if (dset[6] || dset[7])
  {
    if (dset[6] && dset[7])
    {
      coatName = "Perlino";
    }
    else
    {
      if (dset[10] || dset[11])
      {
        coatName = "Pseudo-Perlino";
      }
      else
      {
        coatName = "Buckskin";
      }
    }
  }
  else if (dset[10] && dset[11])
  {
    coatName = "Apricot";
  }
  if (hasSilver)
  {
    string temp = coatName;
    coatName = "Flaxen ";
    coatName.append(temp);
  }
  return coatName;
}

string DilutionCoat::calculateBlackDilutions(bitset<12> dset)
{
  string coatName = "Black";
  bool hasSilver = false;
  if (dset[4] || dset[5]) // Check for silver influence
  {
    hasSilver = true;
  }
  if (dset[8] || dset[9]) // Check for champagne
  {
    coatName = "Classic Champagne";
  }
  else if (dset[6] || dset[7]) // Check for cream
  {
    if (dset[6] && dset[7])
    {
      coatName = "Smokey Cream";
    }
    else
    {
      if (dset[10] || dset[11]) // Check for pearl-cream heterozygous
      {
        coatName = "Pseudo-Smokey Cream";
      }
      else
      {
        coatName = "Smokey Black";
      }
    }
  }
  else if (dset[10] && dset[11]) // Check for Prl/Prl
  {
    coatName = "Apricot";
  }
  if (hasSilver)
  {
    string temp = coatName;
    coatName = "Silver ";
    coatName.append(temp);
  }
  return coatName;
}

string DilutionCoat::calculateDunPresence(bitset<12> dset, string &dilutionCoat)
{
  string tempCoat = dilutionCoat;
  if (dset[3] || dset[1]) // D/D, D/nd1, D/nd2 genotype
  {
    dilutionCoat.assign("Primitive ");
    dilutionCoat.append(tempCoat);
    dilutionCoat.append(" Dun");
    return dilutionCoat;
  }
  else if (!(dset[2] || dset[0])) // nd2/nd2 genotype
  {
    return dilutionCoat;
  }
  else // nd2/nd1
  {
    dilutionCoat.assign("Primitive ");
    dilutionCoat.append(tempCoat);
    return dilutionCoat;
  }
}
