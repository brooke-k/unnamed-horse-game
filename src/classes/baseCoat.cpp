#include "./include/baseCoat.hpp"
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

string BaseCoat::getBaseName()
{
  bitset<8> bset(baseCode);
  if (bset[0] || bset[1])
  {
    return "White";
  }
  else if (!(bset[2] || bset[3]))
  {
    return "Red";
  }
  else if (bset[4] || bset[5])
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
unsigned short BaseCoat::getBase()
{
  return baseCode;
}

bitset<8> BaseCoat::getBaseBitset8()
{
  return bitset<8>(baseCode);
}

string BaseCoat::getBaseName(unsigned short code)
{
  bitset<8> bset(code);
  if (bset[0] || bset[1])
  {
    return "White";
  }
  else if (!(bset[2] || bset[3]))
  {
    return "Red";
  }
  else if (bset[4] || bset[5])
  {
    return "Bay";
  }
  else
  {
    return "Black";
  }
}

string BaseCoat::getBaseName(unsigned long int code)
{
  bitset<32> bset(code);
  if (bset[0] || bset[1])
  {
    return "White";
  }
  else if (!(bset[2] || bset[3]))
  {
    return "Red";
  }
  else if (bset[4] || bset[5])
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

string BaseCoat::toString()
{
  string infoString = ((CoatCode) * this).toString();
  infoString.append("\n\r  Base coat code: ");
  infoString.append(to_string(getBase()));
  infoString.append(("\n\r  Base coat name: "));
  infoString.append(getBaseName());
  return infoString;
}

ostream &operator<<(ostream &os, BaseCoat &bc)
{
  os << bc.toString() << endl;
  return os;
}
