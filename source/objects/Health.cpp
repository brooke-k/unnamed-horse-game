/**
 * @file Health.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 16/Feb/2022
 *
 */

#include <iostream>
#include "../headers/Health.hpp"

using namespace std;

ostream &operator>>(ostream &os, Health &h)
{
  os << "HEALTH REPORT" << endl;
  h.healthStream(os);
  os << "End of Health Report." << endl;
  return os;
}

void Health::healthStream(std::ostream &os)
{
  os << "    Height(hh): ";
  (getHeight() < (float)0) ? os << "N/A" << endl : os << getHeight() << endl;
  os << "    Weight(kg): ";
  (getWeight() < (float)0) ? os << "N/A" << endl : os << getWeight() << endl;
  os << "    Happiness: " << getHappiness() << endl;
  os << "    Hunger: " << getHunger() << endl;
  os << "    Thirst: " << getThirst() << endl;
  os << "    Fitness: " << getFitness() << endl;
  os << "    Energy: " << getSleep() << endl;
  os << "    Grooming: " << getGrooming() << endl;
  os << "    Gestating: ";
  (isGestating()) ? os << "YES" << endl : os << "NO" << endl;
  return;
}
