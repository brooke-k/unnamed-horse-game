#include "./include/baseCoat.hpp"
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

string BaseCoat::getBaseName()
{

  if (baseSet[5] || baseSet[4])
  {
    return "White";
  }
  else if (!(baseSet[3] || baseSet[2]))
  {
    return "Red";
  }
  else if (baseSet[1] || baseSet[0])
  {
    return "Bay";
  }
  else
  {
    return "Black";
  }
}

// Will return the minimum possible dominance for the coat colour. Digits not coding for the base coat will be set to false.
// Non-expressed alleles will be set as heterogynous
unsigned long int BaseCoat::getBase() const
{
  return baseCode;
}

bitset<6> BaseCoat::getBaseBitset6()
{
  return baseSet;
}

string BaseCoat::getBaseName(unsigned long int code)
{
  bitset<32> bset = getCodeAsBitSet32();
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

string BaseCoat::allBaseCoatStr()
{
  string listStr = "";
  for (unsigned long int i = 0; i < 63; i++)
  {
    listStr.append("\n\rDecimal Code: ");
    listStr.append(to_string(i));
    listStr.append(", Name: ");
    listStr.append(getBaseName(i));
  }
  listStr.append("\n\r");
  return listStr;
}

string BaseCoat::baseCoatCodesByName(string coatName)
{
  string searchStr = "^";
  string listStr = "";
  searchStr.append(coatName);
  searchStr.append("$");
  regex coatRegx(searchStr, regex_constants::icase);
  smatch coatMatch;
  string baseString;
  for (unsigned long int i = 0; i < 63; i++)
  {
    baseString = getBaseName(i);
    regex_match(baseString, coatMatch, coatRegx);
    if (!coatMatch.empty())
    {
      listStr.append("\n\rDecimal Code: ");
      listStr.append(to_string(i));
      listStr.append(", Name: ");
      listStr.append(baseString);
    }
  }
  return listStr;
}

string BaseCoat::baseToString()
{
  string infoString = codeToString();
  infoString.append("\n\r  Base coat code: ");
  infoString.append(baseSet.to_string());
  infoString.append(", ");
  infoString.append(getBaseAlleles());
  infoString.append(("\n\r  Base coat name: "));
  infoString.append(getBaseName());
  return infoString;
}

string BaseCoat::getBaseAlleles()
{

  string tempAlleles[] = {"cr", "cr", "e", "e", "a", "a"};
  bitset<6> bset = getBaseBitset6();
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
