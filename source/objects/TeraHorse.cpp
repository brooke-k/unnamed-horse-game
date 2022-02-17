/**
 * @file TeraHorse.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 16/Feb/2022
 *
 */

#include "../headers/TeraHorse.hpp"
#include <iostream>

using namespace std;

std::ostream &operator<<(std::ostream &os, TeraHorse &horse)
{
  horse.addTeraHorseStream(os);
  return os;
}

void TeraHorse::setBroke(bool isBroke)
{
  this->broke = isBroke;
}

bool TeraHorse::isBroke()
{
  return this->broke;
}

void TeraHorse::addTeraHorseStream(ostream &os)
{
  addHorseStream(os);
  os << "  Tera Horse Info:" << endl;
  os << "    Broke: ";
  isBroke() ? os << "Yes" : os << "No";
}
