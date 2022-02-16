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
  h.addHealthStream(os);
  os << "End of Health Report." << endl;
  return os;
}

void Health::addHealthStream(std::ostream &os)
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

// ostream &Health::healthStream(ostream &os)
// {
//   os << "Health Report:" << endl;
//   os << "  Height: " << h.getHeight() << "hh" << endl;
//   os << "  Weight: " << h.getWeight() << "kg" << endl;
//   os << "  Happiness: " << h.getHappiness() << endl;
//   os << "  Hunger: " << h.getHunger() << endl;
//   os << "  Thirst: " << h.getThirst() << endl;
//   os << "  Fitness: " << h.getFitness() << endl;
//   os << "  Energy: " << h.getSleep() << endl;
//   os << "  Grooming: " << h.getGrooming() << endl;
//   os << "  Gestating: ";
//   (h.isGestating()) ? os << "Yes" << endl : os << "No" << endl;
//   os << "End of Health Report." << endl;
//   return os;
// }