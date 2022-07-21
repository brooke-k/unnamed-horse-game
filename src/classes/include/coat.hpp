/**
 * @file Coat.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 21/Jul/2022
 *
 */

#include "./dilutionCoat.hpp"

class Coat : public Dilution
{
public:
  Coat(unsigned long int code = 0) : Dilution(code) { return; }
};