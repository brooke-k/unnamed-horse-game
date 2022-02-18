/**
 * @file HorseVariant.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 17/Feb/2022
 *
 */

#include <string>
#include "Equine.hpp"

class Mundane : protected Equine
{
private:
  WorkingGroup group;
  bool tame;
  bool broke;

protected:
public:
  Mundane() : Equine('X', -1)
  {
    group = GROUP_NOT_KNOWN;
    tame = false;
    broke = false;
  }

  Mundane(WorkingGroup group, bool tame, bool broke) : Equine('X', -1)
  {
    this->group = group;
    this->tame = tame;
    this->broke = broke;
  }
};
