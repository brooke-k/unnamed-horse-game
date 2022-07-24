/**
 * @file baseCoat.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 21/Jul/2022
 *
 */

#include "./coatCode.hpp"
#include <string>
#include <iostream>
#include <bitset>
#include <regex>
#include <cmath>

using namespace std;

class BaseCoat : public CoatCode
{
  bitset<6> baseSet;
  unsigned long int baseCode;

public:
  BaseCoat(unsigned long int code = (unsigned long int)0) : CoatCode(code)
  {
    cout << "Base construct called: ";
    this->baseCode = 0;
    this->baseSet = bitset<6>(0);
    bitset<32> bset = getCodeAsBitSet32();
    cout << "//" << bset.to_string() << "//" << endl;
    for (int i = 31; i > 25; i--)
    {
      this->baseSet[i - 26] = bset[i];
    }
    cout << "Bananas" << endl;
    this->baseCode = baseSet.to_ulong();
    cout << getCodeAsBitSet32() << endl;
    cout << "BaseCode " << this->baseCode << endl;
  }

  BaseCoat(BaseCoat &src)
  {
    return;
  }

  BaseCoat &operator=(const BaseCoat *src)
  {
    return *this;
  }
  virtual ~BaseCoat() { return; }

  void setBaseValues(unsigned long int code)
  {
  }
  // Converters
  string getBaseString();
  string getBaseName();
  string getBaseAlleles();

  string getBaseName(unsigned long int code);

  unsigned long int getBase() const;

  bitset<6> getBaseBitset6();

  string allBaseCoatStr();
  string baseCoatCodesByName(string coatName);
  string baseToString();

  friend ostream &operator<<(ostream &os, BaseCoat &bc);
};
