/**
 * @file Coat.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 21/Jul/2022
 *
 */

#include "./fadeCoat.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;
class Coat : public FadeCoat
{
public:
  Coat(unsigned long int code = rand()) : FadeCoat(code) { return; }
  Coat(Coat &src)
  {
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
  friend ostream &operator<<(ostream &os, Coat &coat);

  string minPrint();
};