/**
 * @file dilutionCoat.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 21/Jul/2022
 *
 */

#include "./baseCoat.hpp"
#include <iostream>
#include <bitset>
#include <string>

#define ALL_DILUTION 16769024

class Dilution : public BaseCoat
{
public:
  Dilution(unsigned long int code = 0) : BaseCoat(code)
  {
    return;
  }
  Dilution(Dilution &)
  {
    return;
  }
  Dilution &operator=(const Dilution *src)
  {
    return *this;
  }
  virtual ~Dilution()
  {
    return;
  }

  bool hasDilutions();
};