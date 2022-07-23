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

class Dilution : public BaseCoat
{
private:
  unsigned long int diluteCode;
  bitset<12> diluteSet;
  string diluteName;

  string calculateRedDilutions();
  string calculateBlackDilutions();
  string calculateBayDilutions();

public:
  Dilution(unsigned long int code = (unsigned long int)0) : BaseCoat(code)
  {
    cout << "dilute constructor called" << endl;
    diluteSet.reset();
    bitset<32> bset = getCodeAsBitSet32();
    for (int c = 6, d = 0; c < 18; c++, d++)
    {
      diluteSet[d] = bset[c];
    }
    diluteCode = diluteSet.to_ulong();
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

  string diluteToString();
  unsigned long int getDilute();
  string getDiluteString();
  bitset<32> getDiluteBitset32();
  bitset<12> getDiluteBitset12();
  string
  getDilutionsList();
  bool hasDilutions();

  string getDiluteBin();

  friend ostream &operator<<(ostream &os, Dilution &dl);

  string calculateDilutionCoat();
};