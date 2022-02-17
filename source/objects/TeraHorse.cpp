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
  horse.addTeraHorseStream(os);
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

void TeraHorse::addTeraHorseStream(ostream &os)
{
  addHorseStream(os);
  os << "  Tera Horse Info:" << endl;
  os << "    Broke: ";
  isBroke() ? os << "Yes" : os << "No";
}
