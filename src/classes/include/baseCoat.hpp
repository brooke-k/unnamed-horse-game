/**
 * @file baseCoat.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 19/Jul/2022
 *
 */

#include <string>

using namespace std;
class BaseCoat
{
private:
  string colourName;
  bool *alleles;
  int geneDec;

public:
  BaseCoat(bool redFact1 = true, bool redFact2 = false, bool agouti1 = true, bool agouti2 = false)
  {
    this->alleles = new bool[4]{0};
    this->alleles[0] = redFact1;
    this->alleles[1] = redFact2;
    this->alleles[2] = agouti1;
    this->alleles[3] = agouti2;

    this->geneDec = BaseCoat::inDecimal(alleles);
    this->colourName = BaseCoat::asString(this->geneDec);
  }

  BaseCoat(int geneDec)
  {
    this->geneDec = geneDec;
    alleles = new bool[4]{0};
    BaseCoat::asArray(alleles, geneDec);
    this->colourName = BaseCoat::asString(geneDec);
  }

  BaseCoat(const BaseCoat *src)
  {
    if (this == src)
    {
      return;
    }
    this->geneDec = src->geneDec;
    this->colourName = BaseCoat::asString(this->geneDec);
    this->alleles = new bool[4]{0};
    BaseCoat::asArray(this->alleles, this->geneDec);
  }

  BaseCoat *operator=(const BaseCoat *src)
  {
    if (this == src)
    {
      return this;
    }
    this->geneDec = src->geneDec;
    BaseCoat::asArray(this->alleles, src->geneDec);
    this->colourName = src->colourName;
  }

  static int inDecimal(const bool *alleles);

  static string asString(int geneDecimal);
  static string asString(const bool *alleles);

  static void asArray(bool *dest, int geneDecimal);

  void setGeneDec(int geneDec);
  void setAllelesArr(const bool *alleles);

  string getCoatName();
  int getGeneDec();
  string getAllelesAlpha();
  string getAllelesBin();

  int updateAllele(int pos, bool newValue);

  friend ostream &operator<<(ostream &os, BaseCoat &bc);
};
