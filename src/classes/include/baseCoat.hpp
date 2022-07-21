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

using namespace std;
class BaseCoat : public CoatCode
{
  unsigned short baseCode;

public:
  BaseCoat(unsigned long int code = 0) : CoatCode(code)
  {
    bitset<32> tempSet(63);
    bitset<32> codeSet(code);

    baseCode = (unsigned short)(tempSet & codeSet).to_ulong();
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

  // Converters
  string getBaseString();
  string getBaseName();

  string getBaseName(unsigned short code);
  string getBaseName(unsigned long int code);

  unsigned short getBase();

  bitset<8> getBaseBitset8();

  string allBaseCoatStr();
  string baseCoatCodesByName(string coatName);
  virtual string toString();

  friend ostream &operator<<(ostream &os, BaseCoat &bc);
};
