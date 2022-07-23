/**
 * @file coatCode.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 21/Jul/2022
 *
 */

#include <string>
#include <iostream>
#include <bitset>

using namespace std;

class CoatCode
{
private:
  string coatName;

  bitset<32> codeSet;

  unsigned long int code; // 32-bit genetic coat code
public:
  // Constructors and Destructors
  CoatCode(unsigned long int code = (unsigned long int)0)
  {
    cout << "CoatCode constructor called" << endl;
    this->code = code;
    this->codeSet = bitset<32>(code);
    this->coatName = "Not calculated";
  }
  CoatCode(CoatCode &src)
  {
    if (&src != this)
    {
      this->code = src.code;
      this->codeSet = bitset<32>(src.code);
      this->coatName = src.coatName;
    }
  }

  CoatCode &operator=(const CoatCode *src)
  {
    if (this == src)
    {
      return *this;
    }
    this->code = src->code;
    this->codeSet = bitset<32>(src->code);
    this->coatName = src->coatName;
    return *this;
  }

  unsigned long int getCodeAsULong() const;
  string getCodeAsString() const;
  bitset<32> getCodeAsBitSet32() const;
  string getCoatName() const;
  void setCoatName(string coatName);

  ~CoatCode()
  {
    return;
  }

  string codeToString();

  // Friends
  friend ostream &
  operator<<(ostream &os, CoatCode &cc);
};
