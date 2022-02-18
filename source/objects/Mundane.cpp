/**
 * @file Mundane.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 18/Feb/2022
 *
 */
#include "../headers/Mundane.hpp"
#include "../headers/EquineEnums.hpp"
#include <string>
#include <ostream>

using namespace std;

void Mundane::setGroup(WorkingGroup group)
{
  this->group = group;
}

void Mundane::setTame(bool tame)
{
  this->tame = tame;
}

void Mundane::setBroke(bool broke)
{
  this->broke = broke;
}

WorkingGroup Mundane::getGroup() const
{
  return group;
}

bool Mundane::isTame() const
{
  return tame;
}

bool Mundane::isBroke() const
{
  return broke;
}

void Mundane::mundaneStream(ostream &os)
{
  os << "  Additional Information: " << endl;
  os << "    Working Group: " << toString(getGroup()) << endl;
  os << "    Tamed: " << isTame() << endl;
  os << "    Broke: " << isBroke() << endl;
  return;
}

ostream &operator<<(ostream &os, Mundane &md)
{
  md.horseStream(os);
  md.mundaneStream(os);
  return os;
}