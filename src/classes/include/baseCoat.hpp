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

    this->geneDec = geneDecimal(alleles);
    this->colourName = coatName(this->geneDec);
  }

  BaseCoat(int geneDec)
  {
    this->geneDec = geneDec;
    alleles = new bool[4]{0};
    geneDecToArray(alleles, geneDec);
    this->colourName = coatName(geneDec);
  }

  BaseCoat(const BaseCoat *src)
  {
    if (this == src)
    {
      return;
    }
    if (alleles != nullptr)
    {
      delete alleles;
    }
    this->geneDec = src->geneDec;
    this->colourName = coatName(this->geneDec);
    this->alleles = new bool[4]{0};
    geneDecToArray(this->alleles, this->geneDec);
  }

  ~BaseCoat()
  {
    delete alleles;
    return;
  }

  BaseCoat *operator=(const BaseCoat *src)
  {
    if (this == src)
    {
      return this;
    }
    if (this->alleles != nullptr)
    {
      delete this->alleles;
    }
    alleles = new bool[4];
    this->geneDec = src->geneDec;
    geneDecToArray(this->alleles, src->geneDec);
    this->colourName = src->colourName;
  }

  int geneDecimal(const bool *alleles);

  string coatName(int geneDecimal);
  string coatName(const bool *alleles);

  void geneDecToArray(bool *dest, int geneDecimal);

  void setGeneDec(int geneDec);
  void setbcAllelesArr(const bool *alleles);

  string getCoatName();
  int getGeneDec();
  string getbcAllelesAlpha();
  string getbcAllelesBin();

  int updateAllele(int pos, bool newValue);

  friend ostream &operator<<(ostream &os, BaseCoat &bc);
};
