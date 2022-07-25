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
  unsigned long int baseCode;
  string baseCoatName;

public:
  BaseCoat(unsigned long int code = (unsigned long int)0) : CoatCode(code)
  {
    this->baseCoatName = calculateBaseCoatName();
  }

  BaseCoat(BaseCoat &src)
  {
    this->baseCoatName = calculateBaseCoatName();
    return;
  }

  BaseCoat &operator=(const BaseCoat *src)
  {
    if (this == src)
    {
      return *this;
    }
    this->baseCoatName = calculateBaseCoatName();
    return *this;
  }
  virtual ~BaseCoat() { return; }

  void setBaseValues(unsigned long int code)
  {
  }
  // Converters
  string getBaseAlleles();

  string baseCoatCodesByName(string coatName);
  string baseToString();
  string getBaseCoatName();
  string calculateBaseCoatName();
  string calculateBaseCoatName(bitset<6> bset);
  string calculateBaseCoatName(unsigned long int bcode);

  friend ostream &operator<<(ostream &os, BaseCoat &bc);
};
