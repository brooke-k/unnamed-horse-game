/**
 * @file Equine.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 16/Feb/2022
 *
 */

#include <iostream>
#include "../headers/Equine.hpp"

#include "../headers/EquineEnums.hpp"

using namespace std;

Equine::Equine(char sex, int age)
{
  name = "N/A";
  this->variant = MUNDANE;
  this->sex = sex;
  this->age = age;
}

Equine::Equine()
{
  name = "N/A";
  this->variant = MUNDANE;
  this->sex = 'X';
  this->age = -1;
}

Equine::Equine(std::string name, char sex, int age)
{
  this->name = name;
  this->age = age;
  this->sex = sex;
  this->variant = MUNDANE;
}

Equine::~Equine()
{
  return;
}

Equine &Equine::operator=(Equine &src)
{
  if (this != &src)
  {
    this->name = src.name;
    this->variant = src.variant;
    this->age = src.age;
    this->sex = src.sex;
  }
  return *this;
}

Equine::Equine(Equine &src)
{
  this->age = src.age;
  this->sex = src.sex;
  this->name = name;
  this->variant = variant;
}

std::ostream &operator<<(std::ostream &os, Equine &horse)
{
  horse.horseStream(os);
  return os;
}

void Equine::horseStream(ostream &os)
{
  os << endl
     << endl;
  os << "/------ HORSE REPORT ------\\" << endl;
  os << "  Basic Info:" << endl;
  os << "    Name:       " << getName() << endl;
  os << "    Variant:    " << toString(getVariant()) << endl;
  os << "    Age:        " << getAge() << endl;
  os << "    Sex:        " << getSex() << endl;
  os << "  Health Info: " << endl;
  healthStream(os);
  return;
}

string Equine::getName() const
{
  return name;
}

int Equine::getAge()
{
  return age;
}

char Equine::getSex()
{
  return sex;
}

void Equine::setName(string name)
{
  this->name = name;
}

void Equine::setAge(int age)
{
  this->age = age;
}

void Equine::setSex(char sex)
{
  this->sex = sex;
}

void Equine::setVariant(EqVariant variant)
{
  this->variant = variant;
}

EqVariant Equine::getVariant() const
{
  return variant;
}
