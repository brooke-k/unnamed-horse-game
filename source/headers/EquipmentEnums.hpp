/**
 * @file Enums.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 17/Feb/2022
 *
 */

typedef struct EquipmentType
{
  enum Type
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
} EquipType;

typedef struct EquipmentMaterial
{
  enum Material
  {
    leather = 0,
    nylon = 1,
    twine = 2,
    polyester = 3,
    sheepskin = 4,
  };
} EquipMatrl;

typedef struct EquipmentColour
{
  enum BrightColour
  {
    red = 0,
    orange = 1,
    yellow = 2,
    green = 3,
    cyan = 4,
    blue = 5,
    indigo = 6,
    purple = 7,
    pink = 8,
    white = 9,
    grey = 10,
    black = 11,
  };
  enum EarthColour
  {
    balsa = 0,
    pine = 1,
    alder = 2,
    elm = 3,
    cedar = 4,
    sweetgum = 5,
    walnut = 6,
    rosewood = 7,
    ebony = 8,
  };
  enum MetalColour
  {
    silver = 0,
    gold = 1,
    copper = 2,
    brass = 3,
    titanium = 4,
    palladium = 5,
    tungsten = 6
  };
} EquipColour;