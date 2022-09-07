#include "./include/coats/baseCoat.hpp"
#ifndef PRINTFORM
#define PRINTFORM
#include "./include/utilities/printForm.hpp"
#endif // PRINTFORM
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

string BaseCoat::calculateBaseCoatName(bitset<6> bset)
{
  if (bset[5] || bset[4])
  {
    return "White";
  }
  else if (!(bset[3] || bset[2]))
  {
    return "Chestnut";
  }
  else if (bset[1] || bset[0])
  {
    return "Bay";
  }
  else
  {
    return "Black";
  }
}

void BaseCoat::fullPrint()
{
  printTopBorder();
  printFormLine("           COAT CODE DATA: Base Coat", "", 3);
  printThickInnerBorder();
  printFormLine("ESSENTIAL VALUES", "", 0);
  bitset<32> tempCode = getFullSet();
  printFormLine("Coat name: ", getCoatName(), 1);
  printFormLine("Binary value: ", getSectionedBin(), 1);
  stringstream inhex;
  inhex << hex << getCodeAsULong();
  printFormLine("Hexadecimal value: 0x", inhex.str(), 1);
  printInnerBorder();
  printFormLine("SEGMENTED DATA: ", "", 0);
  printFormLine("Base coat bin.: ", getBaseSet().to_string(), 1);
  printFormLine("Base coat alleles: ", getBaseAlleles(), 1);
  printFormLine("Base coat colour: ", getBaseCoatName(), 1);
  printFormLine("", "");
  printFormLine("Dilution coat bin.: ", getDiluteSet().to_string(), 1);
  printFormLine("Dilution coat colour: ", "Undefined", 1);
  printFormLine("Dilution coat alleles: ", "Undefined", 1);
  printFormLine("", "");

  printFormLine("Fade coat bin.: ", getFadeSet().to_string(), 1);
  printFormLine("Fade coat alleles: ", "Undefined", 1);
  printFormLine("Fade coat colour: ", "Undefined", 1);
  printFormLine("", "");
  printFormLine("White marking bin.: ", getMarkSet().to_string(), 1);
  printFormLine("White marking alleles: ", "Undefined", 1);
  printFormLine("White marking coat: ", "Undefined", 1);
  printBottomBorder();
}

string BaseCoat::calculateBaseCoatName(unsigned long int bcode)
{
  bitset<6> bset;
  bitset<32> tempSet(bcode);
  for (int i = 31; i >= 26; i--)
  {
    bset[i - 26] = tempSet[i];
  }
  return calculateBaseCoatName(bset);
}

string BaseCoat::calculateBaseCoatName()
{
  return calculateBaseCoatName(getBaseSet());
}

/** BNOTE deprecated to be removed */
string BaseCoat::baseToString()
{
  string infoString = codeToString();
  infoString.append(getPrintSection());
  infoString = addPrintLine(infoString, "BASE COAT DATA");
  infoString = addPrintLine(infoString, "   Base coat: ", getBaseCoatName(), 1);
  infoString = addPrintLine(infoString, "Code segment: ", getBaseSet().to_string(), 1);
  infoString = addPrintLine(infoString, "     Alleles: ", getBaseAlleles(), 1);
  return infoString;
}

string BaseCoat::getBaseCoatName()
{
  return baseCoatName;
}

string BaseCoat::getBaseAlleles()
{

  string tempAlleles[] = {"cr", "cr", "e", "e", "a", "a"};
  bitset<6> bset = getBaseSet();
  string temp = "";
  string alleleString = "";
  for (int i = 0; i < 6; i++)
  {
    if (bset[5 - i])
    {
      temp = tempAlleles[i];
      temp.at(0) = toupper(temp.at(0));
      tempAlleles[i] = temp;
    }
    alleleString.append(tempAlleles[i]);
    if (i % 2 == 1 && i < 5)
    {
      alleleString.append("-");
    }
    else if (i < 5)
    {
      alleleString.append("/");
    }
  }
  return alleleString;
}

ostream &operator<<(ostream &os, BaseCoat &bc)
{
  os << bc.getBaseCoatName() << endl;
  return os;
}
