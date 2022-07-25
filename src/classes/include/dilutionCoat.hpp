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
  string dilutionCoatName;

  string calculateRedDilutions(bitset<12> bset);
  string calculateBlackDilutions(bitset<12> bset);
  string calculateBayDilutions(bitset<12> bset);
  string calculateDunPresence(bitset<12> bset, string &dilutionCoat);
  void calculateDilutions();

public:
  Dilution(unsigned long int code = (unsigned long int)0) : BaseCoat(code)
  {
    this->dilutionCoatName = calculateDilutionCoatName();
    return;
  }
  Dilution(Dilution &src)
  {
    this->dilutionCoatName = calculateDilutionCoatName(src.getBaseSet(), src.getDiluteSet());
    return;
  }
  Dilution &operator=(const Dilution *src)
  {
    if (src == this)
    {
      return *this;
    }
    this->dilutionCoatName = calculateDilutionCoatName(src->getBaseSet(), src->getDiluteSet());
    return *this;
  }
  virtual ~Dilution()
  {
    return;
  }

  void setDilutionCoatName(string dilutionCoatName);

  string getDilutionCoatName() const;

  string diluteToString();
  unsigned long int getDilute();
  string getDiluteString();
  string
  getDilutionsList();
  bool hasDilutions();
  string getDiluteAlleles();
  bool hasPrimitiveMarkings();
  friend ostream &operator<<(ostream &os, Dilution &dl);

  string calculateDilutionCoatName();
  string calculateDilutionCoatName(bitset<6> bset, bitset<12> dset);
  string calculateDilutionCoatName(bitset<32> fset);

  string calculateDilutionCoatName(unsigned long int dcode);
};