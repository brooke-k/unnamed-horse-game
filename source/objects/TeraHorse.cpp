/**
 * File: TeraHorse.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com)
 * Date: 27/Jan/2022
 *
 */

#include "../headers/TeraHorse.hpp"
#include <iostream>

using namespace std;

std::ostream& operator<<(std::ostream& os, TeraHorse& horse){
  os << "  Name: " << horse.getName() << endl;
  os << "  Varient: " << horse.getVariant() << endl;
  os << "  Age: " << horse.getAge() << endl;
  os << "  Sex: " << horse.getSex() << endl;
 os << "  Broke: ";
  horse.isBroke()? os<< "Yes" : os <<"No";
  os << endl;
  return os;
}

void TeraHorse::setBroke(bool broke){
  this->broke = broke;
}

bool TeraHorse::isBroke(){
  return this->broke;
}
