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
    cout << "Base construct called." << endl;
    this->baseCode = 0;
    this->baseSet = bitset<6>(0);
    bitset<8> tempSet(0);
    bitset<32> bset = getCodeAsBitSet32();
    for (int i = 0; i < 6; i++)
    {
      this->baseSet[i] = bset[i];
      tempSet[i] = bset[i];
    }

    this->baseCode = tempSet.to_ulong();
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

  string getBaseName(unsigned short code);
  string getBaseName(unsigned long int code);

  unsigned long int getBase() const;

  bitset<6> getBaseBitset6();

  string allBaseCoatStr();
  string baseCoatCodesByName(string coatName);
  string baseToString();

  friend ostream &operator<<(ostream &os, BaseCoat &bc);
};
