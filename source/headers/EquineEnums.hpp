/**
 * @file EquineEnums.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 18/Feb/2022
 *
 */

#ifndef EQUINE_ENUMS
#define EQUINE_ENUMS

enum WorkingGroup
{
  DRAFT,
  PONY,
  MINIATURE,
  RIDING,
  CART,
  SPORT,
  WESTERN,
  GROUP_NOT_KNOWN,

};

enum EqVariant
{
  MUNDANE,
  PEGASUS,
  ARCANE,
  UNICORN,
  VARIANT_NOT_KNOWN,

};

static std::string toString(WorkingGroup w)
{
  switch (w)
  {
  case DRAFT:
    return "Draft";
  case PONY:
    return "Pony";
  case MINIATURE:
    return "Miniature";
  case RIDING:
    return "Riding";
  case CART:
    return "Cart";
  case SPORT:
    return "Sport";
  case WESTERN:
    return "Western";
  case GROUP_NOT_KNOWN:
    return "Unknown";
  default:
    return "Unknown";
  }
}

static std::string toString(EqVariant e)
{
  switch (e)
  {
  case MUNDANE:
    return "Mundane";
  case PEGASUS:
    return "Pegasus";
  case ARCANE:
    return "Arcane";
  case UNICORN:
    return "Unicorn";
  case VARIANT_NOT_KNOWN:
    return "Unknown";
  default:
    return "Unknown";
  }
}

#endif // !EQUINE_ENUMS
