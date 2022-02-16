/**
 * @file Health.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 16/Feb/2022
 *
 */

#include <iostream>
#include "../headers/Health.hpp"

using namespace std;

// ostream &operator>>(ostream &os, Health &h)
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

// ostream &Health::healthStream()
// {
//   ostream os();
//   os << *this << endl;
//   return os;
// }