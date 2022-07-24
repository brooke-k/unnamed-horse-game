#include "./include/baseCoat.hpp"
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
    return "Red";
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

string BaseCoat::baseToString()
{
  string infoString = codeToString();
  infoString = addPrintLine(infoString, "BASE COAT DATA");
  infoString = addPrintLine(infoString, "Base Coat: ", getBaseCoatName(), 1);
  infoString = addPrintLine(infoString, "     Code: ", getBaseSet().to_string(), 1);
  infoString = addPrintLine(infoString, "  Alleles: ", getBaseAlleles(), 1);

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
  }
  return alleleString;
}

ostream &operator<<(ostream &os, BaseCoat &bc)
{
  os << bc.baseToString() << endl;
  return os;
}
