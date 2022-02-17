/**
 * @file Equipment.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 17/Feb/2022
 *
 */

#include "../headers/Equipment.hpp"
#include "../headers/EquipmentEnums.hpp"
#include <string>
#include <vector>

using namespace std;

std::string EquipmentEnums::toString(EquipType t)
{
  switch (t)
  {
  case bridle:
    return "bridle";
  case saddle:
    return "saddle";
  case blanket:
    return "blanket";
  case boots:
    return "boots";
  case shoes:
    return "shoes";
  case head:
    return "head";
  case body:
    return "body";
  case legs:
    return "legs";
  case bag:
    return "bag";
  case decor:
    return "decor";
  default:
    "N/A";
  }
}
std::string EquipmentEnums::toString(EquipColour c)
{
  if (c < 20)
  {

    switch (c)
    {
    case red:
      return "red";
    case orange:
      return "orange";
    case yellow:
      return "yellow";
    case green:
      return "green";
    case cyan:
      return "cyan";
    case blue:
      return "blue";
    case indigo:
      return "indigo";
    case purple:
      return "purple";
    case pink:
      return "pink";
    case white:
      return "white";
    case grey:
      return "grey";
    case black:
      return "black";
    default:
      return "N/A";
    }
  }
  else if (c < 30)
  {
    switch (c)
    {
    case balsa:
      return "balsa";
    case pine:
      return "pine";
    case alder:
      return "alder";
    case elm:
      return "elm";
    case cedar:
      return "cedar";
    case sweetgum:
      return "sweetgum";
    case walnut:
      return "walnut";
    case rosewood:
      return "rosewood";
    case ebony:
      return "ebony";
    default:
      return "N/A";
    }
  }
  else
  {
    switch (c)
    {
    case silver:
      return "silver";
    case gold:
      return "gold";
    case copper:
      return "copper";
    case brass:
      return "brass";
    case titanium:
      return "titanium";
    case palladium:
      return "palladium";
    case tungsten:
      return "tungsten";
    default:
      return "N/A";
    }
  }
}
std::string EquipmentEnums::toString(EquipMatrl m)
{
  switch (m)
  {
  case leather:
    return "leather";
  case nylon:
    return "nylon";
  case twine:
    return "twine";
  case polyester:
    return "polyester";
  case sheepskin:
    return "sheepskin";
  default:
    return "N/A";
  }
}

string Equipment::getName() const
{
  return name;
}
void Equipment::setName(string name)
{
  this->name = name;
}
EquipMatrl Equipment::getMaterial()
{
  return material;
}
EquipType Equipment::getType()
{
  return type;
}
vector<EquipColour> Equipment::getColours()
{
  return colours;
}
void Equipment::addColour(EquipColour colour)
{
  colours.push_back(colour);
}
void Equipment::removeColour(EquipColour colour)
{
  EquipColour c;
  for (int i = 0; i < this->colours.size(); i++)
  {

    if (colours[i] == colour)
    {
      colours.erase(colours.begin() + i);
      i = this->colours.size();
    }
  }
  return;
}
void Equipment::setColours(vector<EquipColour> colours)
{
  this->colours = colours;
}
bool Equipment::isColour(EquipColour colour)
{
  for (auto c : colours)
  {
    if (c == colour)
    {
      return true;
    }
  }
  return false;
}
bool Equipment::isMulticolour()
{
  if (colours.empty())
  {
    return false;
  }
  else if (colours.size() < 1)
  {
    return false;
  }
  else
  {
    return true;
  }
}
void Equipment::equipStream(ostream &os)
{
  os << "  Equipment Info:" << endl;
  os << "    Name: " << this->name << endl;
  os << "    Type: " << EquipmentEnums::toString(this->type) << endl;
  os << "    Material: " << EquipmentEnums::toString(this->material) << endl;
  os << "    Colours: " << endl;
  for (auto c : colours)
  {
    os << "    " << EquipmentEnums::toString(c) << endl;
  }
}

ostream &operator<<(ostream &os, Equipment &e)
{
  e.equipStream(os);
  e.equipStatStream(os);
  return os;
}