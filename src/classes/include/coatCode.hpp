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
protected:
  unsigned long int code; // 32-bit genetic coat code
public:
  // Constructors and Destructors
  CoatCode(unsigned long int code = 0)
  {
    this->code = code;
  }
  CoatCode(CoatCode &src)
  {
    this->code = src.code;
  }

  CoatCode &operator=(const CoatCode *src)
  {
    if (this == src)
    {
      return *this;
    }
    this->code = src->code;
    return *this;
  }

  unsigned long int getCodeAsULong() const;
  string getCodeAsString() const;
  bitset<32> getCodeAsBitSet32() const;

  ~CoatCode()
  {
    return;
  }

  virtual string toString();

  // Friends
  friend ostream &
  operator<<(ostream &os, CoatCode &cc);
};
