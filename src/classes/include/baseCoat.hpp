/**
 * @file baseCoat.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 21/Jul/2022
 *
 */

#include <string>
#include <iostream>
#include <bitset>
#include <regex>

using namespace std;
class BaseCoat
{
public:
  BaseCoat()
  {
    return;
  }

  BaseCoat(BaseCoat &src)
  {
    return;
  }

  BaseCoat &operator=(const BaseCoat *src)
  {
    return *this;
  }
  ~BaseCoat() { return; }

  // Converters
  string getBaseAsString(bitset<32> bset);

  string getBaseAsString(unsigned long int code);

  unsigned long int getBaseAsULong(string coatName);

  bitset<32> getBaseAsBitset(string coatName);
};
