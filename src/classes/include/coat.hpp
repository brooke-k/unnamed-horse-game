/**
 * @file Coat.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 21/Jul/2022
 *
 */

#include "./whiteMarkCoat.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;
class Coat : public WhiteMarkCoat
{
public:
  Coat(unsigned long int code = rand()) : WhiteMarkCoat(code) { return; }
  Coat(Coat &src)
  {
    *this = src;

    return;
  }
  Coat &operator=(const Coat *src)
  {
    if (this == src)
    {
      return *this;
    }
    return *this;
  }

  ~Coat()
  {
    return;
  }

  Coat &operator+=(const Coat &rhs);

  Coat &operator*=(const Coat &rhs);

  Coat &operator+=(const unsigned long int &bval);

  friend Coat operator*(Coat &lhs, const Coat &rhs);

  friend ostream &operator<<(ostream &os, Coat &coat);

  friend Coat &operator+(Coat &lhs, const Coat &rhs);

  string minPrint();
  void fullPrint();
};