/**
 * @file whitePatCoat.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 09/Aug/2022
 *
 */

#include "./fadeCoat.hpp"
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

class WhiteMarkCoat : public FadeCoat
{
private:
  string markCoatName;

public:
  WhiteMarkCoat(unsigned long int code = (unsigned long int)0) : FadeCoat(code)
  {
    this->markCoatName = calculateMarkCoatName();
    this->setCoatName(this->getMarkCoatName());

    return;
  }

  WhiteMarkCoat(WhiteMarkCoat &src)
  {
    this->markCoatName = calculateMarkCoatName();
    this->setCoatName(this->getMarkCoatName());
  }

  WhiteMarkCoat &operator=(const WhiteMarkCoat *src)
  {
    if (this == src)
    {
      return *this;
    }
    this->markCoatName = calculateMarkCoatName(src->getMarkSet());
    this->setCoatName(this->getMarkCoatName());

    return *this;
  }

  virtual ~WhiteMarkCoat() { return; }
  string markToString();
  string calculateMarkCoatName();
  string calculateMarkCoatName(bitset<10> mset);
  string getMarkAlleles();
  void setMarkCoatName(string markCoatName);

  virtual void fullPrint();
  string getMarkCoatName();

  friend ostream &
  operator<<(ostream &os, const WhiteMarkCoat &mc);
};