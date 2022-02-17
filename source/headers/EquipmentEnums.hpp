/**
 * @file Enums.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 17/Feb/2022
 *
 */

enum EquipType
{
  bridle = 0,
  saddle = 1,
  blanket = 2,
  boots = 3,
  shoes = 4,
  head = 5,
  body = 6,
  legs = 7,
  bag = 8,
  decor = 9
};

enum EquipMatrl
{
  leather = 0,
  nylon = 1,
  twine = 2,
  polyester = 3,
  sheepskin = 4,

};

enum EquipColour
{
  transparent = 0,

  red = 1,
  orange = 2,
  yellow = 3,
  green = 4,
  cyan = 5,
  blue = 6,
  indigo = 7,
  purple = 8,
  pink = 9,
  white = 10,
  grey = 11,
  black = 12,

  balsa = 20,
  pine = 21,
  alder = 22,
  elm = 23,
  cedar = 24,
  sweetgum = 25,
  walnut = 26,
  rosewood = 27,
  ebony = 28,

  silver = 30,
  gold = 31,
  copper = 32,
  brass = 33,
  titanium = 34,
  palladium = 35,
  tungsten = 36
};

class EquipmentEnums
{
public:
  static std::string toString(EquipType t);
  static std::string toString(EquipColour c);
  static std::string toString(EquipMatrl m);
};
