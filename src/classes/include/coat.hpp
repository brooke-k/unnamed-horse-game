/**
 * @file Coat.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 21/Jul/2022
 *
 */

#include "./fadeCoat.hpp"

class Coat : public FadeCoat
{
public:
  Coat(unsigned long int code = 0) : FadeCoat(code) { return; }
};