/**
 * @file fadeCoat.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 24/Jul/2022
 *
 */

#include "./dilutionCoat.hpp"
#include <bitset>
#include <iostream>
#include <string>
using namespace std;

class FadeCoat : public DilutionCoat
{
private:
  string fadeCoatName;

public:
  FadeCoat(unsigned long int code = (unsigned long int)0) : DilutionCoat(code)
  {
    this->fadeCoatName = calculateFadeCoatName();
    this->setCoatName(this->getFadeCoatName());

    return;
  }
  FadeCoat(FadeCoat &src)
  {
    this->fadeCoatName = calculateFadeCoatName();
    this->setCoatName(this->getFadeCoatName());
  }
  FadeCoat &operator=(const FadeCoat *src)
  {
    if (this == src)
    {
      return *this;
    }
    this->fadeCoatName = calculateFadeCoatName(src->getFadeSet());
    this->setCoatName(this->getFadeCoatName());

    return *this;
  }

  string getFadeCoatName() const;
  void setFadeCoatName(string fadeCoatName);

  virtual ~FadeCoat() { return; }
  string fadeToString();
  string calculateFadeCoatName();
  string calculateFadeCoatName(bitset<4> fdset);
  string getFadeAlleles();

  friend ostream &
  operator<<(ostream &os, FadeCoat &fc);
};