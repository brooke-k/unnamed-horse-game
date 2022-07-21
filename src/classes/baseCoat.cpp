#include "./include/baseCoat.hpp"
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

string BaseCoat::getBaseAsString(bitset<32> bset)
{
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

string BaseCoat::getBaseAsString(unsigned long int code)
{
  return getBaseAsString(bitset<32>(code));
}

// Will return the minimum possible dominance for the coat colour. Digits not coding for the base coat will be set to false.
// Non-expressed alleles will be set as heterogynous
unsigned long int BaseCoat::getBaseAsULong(string coatName)
{
  regex nameMatch("^bay$", regex_constants::icase);
  smatch mtch;
  regex_search(coatName, mtch, nameMatch);
  if (!mtch.empty())
  {
    return 20; // Minimum code for a bay coat (NNEeAa)
  }
  nameMatch = regex("^white$", regex_constants::icase);
  regex_search(coatName, mtch, nameMatch);
  if (!mtch.empty())
  {
    return 21; // Minimum code for a white coat (CWNEeAa)
  }
  nameMatch = regex("^red$", regex_constants::icase);
  if (!mtch.empty())
  {
    return 16; // Minimum code for a red coat (NNeeAa)
  }
  nameMatch = regex("^black$", regex_constants::icase);
  if (!mtch.empty())
  {
    return 4; // Minimum code for a black coat (NNEeaa)
  }
  return 20; // Minimum code for a bay coat (NNEeAa), if no match made.
}

bitset<32> BaseCoat::getBaseAsBitset(string coatName)
{
  return bitset<32>(getBaseAsULong(coatName));
}