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
  string sectionedBin;

  bitset<32> fullSet;
  bitset<6> baseSet;
  bitset<12> diluteSet;
  bitset<4> fadeSet;
  bitset<10> markSet;

  unsigned long int code; // 32-bit genetic coat code
public:
  // Constructors and Destructors
  CoatCode(unsigned long int code = (unsigned long int)0)
  {
    cout << "CoatCode constructor called" << endl;

    this->code = code;
    this->fullSet = bitset<32>(code);
    this->baseSet = bitset<6>(0);
    this->diluteSet = bitset<12>(0);
    this->fadeSet = bitset<4>(0);
    this->markSet = bitset<10>(0);
    this->sectionedBin = "";
    for (int i = 31; i >= 0; i--)
    {
      if (i >= 26)
      {
        this->baseSet[i - 26] = this->fullSet[i];
        this->sectionedBin.append(to_string(this->fullSet[i]));
        if (i == 26)
        {
          this->sectionedBin.append("-");
        }
      }
      else if (i >= 14)
      {
        this->diluteSet[i - 14] = this->fullSet[i];
        this->sectionedBin.append(to_string(this->fullSet[i]));
        if (i == 14)
        {
          this->sectionedBin.append("-");
        }
      }
      else if (i >= 10)
      {
        this->fadeSet[i - 10] = this->fullSet[i];
        this->sectionedBin.append(to_string(this->fullSet[i]));
        if (i == 10)
        {
          this->sectionedBin.append("-");
        }
      }
      else
      {
        this->markSet[i] = this->markSet[i];
        this->sectionedBin.append(to_string(this->fullSet[i]));
      }
    }
    this->coatName = "Not calculated";
  }
  CoatCode(CoatCode &src)
  {
    if (&src != this)
    {
      this->code = src.code;
      this->fullSet = bitset<32>(src.code);
      this->baseSet = bitset<6>(src.baseSet);
      this->diluteSet = bitset<12>(src.diluteSet);
      this->fadeSet = bitset<4>(src.fadeSet);
      this->markSet = bitset<10>(src.markSet);
      this->sectionedBin = src.sectionedBin;
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
    this->fullSet = bitset<32>(src->code);
    this->baseSet = bitset<6>(src->baseSet);
    this->diluteSet = bitset<12>(src->diluteSet);
    this->fadeSet = bitset<4>(src->fadeSet);
    this->markSet = bitset<10>(src->markSet);
    this->sectionedBin = src->sectionedBin;
    this->coatName = src->coatName;
    return *this;
  }

  unsigned long int getCodeAsULong() const;
  string getCodeAsString() const;
  bitset<32> getFullSet() const;
  bitset<6> getBaseSet() const;
  bitset<12> getDiluteSet() const;
  bitset<4> getFadeSet() const;
  bitset<10> getMarkSet() const;
  string getSectionedBin() const;
  string getCoatName() const;
  void setCoatName(string coatName);

  ~CoatCode()
  {
    return;
  }

  string codeToString();
  string getSectionedBin();

  // Friends
  friend ostream &
  operator<<(ostream &os, CoatCode &cc);
};
