/**
 * @file coatCode.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 21/Jul/2022
 *
 */
#include "./baseCoat.hpp"
#include <string>
#include <iostream>

using namespace std;

class CoatCode
{
private:
  unsigned long int code; // 32-bit genetic coat code
  string englishName;     // English name for coat

protected:
  BaseCoat getBaseCoat();

public:
  // Constructors and Destructors
  CoatCode(unsigned long int geneticCode = 0)
  {
    this->code = geneticCode;
  }
  CoatCode(CoatCode &src)
  {
    this->code = src.code;
    this->englishName = src.englishName;
  }

  CoatCode &operator=(const CoatCode *src)
  {
    if (this == src)
    {
      return *this;
    }
    this->code = src->code;
    this->englishName = src->englishName;
    return *this;
  }

  unsigned long int getBaseAsULong(unsigned long int code);

  unsigned long int getBaseAsULong(const BaseCoat bc);

  string getBaseAsString(bitset<32> bset);

  ~CoatCode()
  {
    return;
  }

  unsigned long int getRawCode();

  static unsigned long int baseCoatTrue();
  static string baseCoatToString(const BaseCoat bc);
  static string baseCoatToString(const unsigned long int bc);

  // Friends
  friend ostream &operator<<(ostream &os, CoatCode &cc);
  friend BaseCoat;
};
