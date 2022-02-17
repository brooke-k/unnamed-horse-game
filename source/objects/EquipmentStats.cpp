/**
 * @file EquipmentStats.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 16/Feb/2022
 *
 */

#include <cmath>
#include <iostream>
#include "../headers/EquipmentStats.hpp"

using namespace std;

int EquipStats::getFit()
{
  return fit;
}
int EquipStats::getSpeed()
{
  return speed;
}

int EquipStats::getJumping()
{
  return jumping;
}

int EquipStats::getAgility()
{
  return agility;
}

int EquipStats::getControl()
{
  return control;
}

int EquipStats::getComfort()
{
  return comfort;
}

int EquipStats::getOverall()
{
  return overall;
}

void EquipStats::equipStatStream(ostream &os)
{
  os << "  Equipment Statistics" << endl;
  os << "    Speed: " << getSpeed() << endl;
  os << "    Jumping: " << getJumping() << endl;
  os << "    Agility: " << getAgility() << endl;
  os << "    Control: " << getControl() << endl;
  os << "    Fit: " << getFit() << endl;
  os << "    Comfort: " << getComfort() << endl;
  os << "    Overall: " << getOverall() << endl;
  return;
}

ostream &operator<<(ostream &os, EquipmentStats &eq)
{
  eq.equipStatStream(os);
  return os;
}
