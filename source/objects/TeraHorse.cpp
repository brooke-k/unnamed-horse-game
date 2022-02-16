/**
 * File: TeraHorse.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com)
 * Date: 27/Jan/2022
 *
 */

#include "../headers/TeraHorse.hpp"
#include <iostream>

using namespace std;

std::ostream &operator<<(std::ostream &os, TeraHorse &horse)
{
  Horse tempHorse(horse);
  os << "  Broke: ";
  horse.isBroke() ? os << "Yes" : os << "No";
  os << endl;
  return os;
}

void TeraHorse::setBroke(bool broke)
{
  this->broke = broke;
}

bool TeraHorse::isBroke()
{
  return this->broke;
}
