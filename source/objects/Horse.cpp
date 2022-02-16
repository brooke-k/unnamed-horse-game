/**
 * File: Horse.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com)
 * Date: 27/Jan/2022
 *
 */

#include "../headers/Horse.hpp"

#include <iostream>

using namespace std;

Horse::Horse(char *name, int length, char sex, int age, const char *variant)
{
  this->name = new char[length + 1]{'\0'};
  strcpy(this->name, name);
  this->age = age;
  this->nameLength = length;
  this->sex = sex;
  this->variant = new char[VARIANT_SIZE]{'\0'};
  strcpy(this->variant, variant);
}

Horse::~Horse()
{
  delete this->name;
  delete this->variant;
}

Horse &Horse::operator=(Horse &src)
{
  if (this != &src)
  {
    if (this->name != NULL)
    {
      delete this->name;
    }
    if (this->variant != NULL)
    {
      delete this->variant;
    }
    this->nameLength = src.nameLength;
    this->name = new char[src.nameLength + 1]{'\0'};
    this->variant = new char[VARIANT_SIZE]{'\0'};
    strcpy(this->name, src.name);
    strcpy(this->variant, src.variant);
    this->age = src.age;
    this->sex = src.sex;
  }
  return *this;
}

Horse::Horse(Horse &src)
{
  this->age = src.age;
  this->nameLength = src.nameLength;
  this->sex = src.sex;
  this->name = new char[this->nameLength + 1]{'\0'};
  this->variant = new char[VARIANT_SIZE]{'\0'};
  strcpy(this->name, src.name);
  strcpy(this->variant, src.variant);
}

std::ostream &operator<<(std::ostream &os, Horse &horse)
{
  os << "/------ HORSE REPORT ------\\" << endl;
  horse.addHorseStream(os);
  // os << "    Height: " << horse.getHeight() << "hh" << endl;
  // os << "    Weight: " << horse.getWeight() << "kg" << endl;
  // os << "    Happiness: " << horse.getHappiness() << endl;
  // os << "    Hunger: " << horse.getHunger() << endl;
  // os << "    Thirst: " << horse.getThirst() << endl;
  // os << "    Fitness: " << horse.getFitness() << endl;
  // os << "    Energy: " << horse.getSleep() << endl;
  // os << "    Grooming: " << horse.getGrooming() << endl;
  // os << "    Gestating: ";
  // (horse.isGestating()) ? os << "Yes" << endl : os << "No" << endl;

  os << "\\----END OF HORSE REPORT ---/" << endl
     << endl;
  ;

  return os;
}

void Horse::addHorseStream(ostream &os)
{
  os << "  Basic Info:" << endl;
  os << "    Name: " << getName() << endl;
  os << "    Variant: " << getVariant() << endl;
  os << "    Age: " << getAge() << endl;
  os << "    Sex: " << getSex() << endl;
  os << "  Health Info: " << endl;
  addHealthStream(os);
  return;
}

char *Horse::getName() const
{
  return name;
}

int Horse::getAge()
{
  return age;
}

char Horse::getSex()
{
  return sex;
}

void Horse::setName(char *name, int length)
{
  if (this->name != NULL)
  {
    delete this->name;
  }
  this->nameLength = length;
  this->name = new char[length + 1]{'\0'};
  strcpy(this->name, name);
}

void Horse::setAge(int age)
{
  this->age = age;
}

void Horse::setSex(char sex)
{
  this->sex = sex;
}

void Horse::setVariant(const char *variant)
{
  if (this->variant != NULL)
  {
    memset(this->variant, '\0', VARIANT_SIZE * sizeof(char));
  }
  else
  {
    this->variant = new char[VARIANT_SIZE]{'\0'};
  }
  strcpy(this->variant, variant);
}

void Horse::setVariant(char *variant)
{
  if (this->variant != NULL)
  {
    memset(this->variant, '\0', VARIANT_SIZE * sizeof(char));
  }
  else
  {
    this->variant = new char[VARIANT_SIZE]{'\0'};
  }
  strcpy(this->variant, variant);
}

char *Horse::getVariant() const
{
  return variant;
}
