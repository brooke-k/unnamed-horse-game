/**
 * @file HorseVariant.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 17/Feb/2022
 *
 */

#include <string>
#include <ostream>
#include "Equine.hpp"

class Mundane : protected Equine
{
private:
  WorkingGroup group;
  bool tame;
  bool broke;

protected:
  void mundaneStream(std::ostream &os);
  friend std::ostream &operator<<(std::ostream &os, Mundane &m);

public:
  Mundane() : Equine('X', -1)
  {
    group = GROUP_NOT_KNOWN;
    tame = false;
    broke = false;
    setVariant(MUNDANE);
  }

  Mundane(WorkingGroup group, bool tame, bool broke) : Equine('X', -1)
  {
    this->group = group;
    this->tame = tame;
    this->broke = broke;
    setVariant(MUNDANE);
  }

  Mundane(Mundane &src) : Equine(src)
  {
    this->group = src.group;
    this->tame = src.tame;
    this->broke = src.broke;
    setVariant(MUNDANE);
  }

  Mundane(std::string name, char sex = 'X', int age = -1, WorkingGroup group = GROUP_NOT_KNOWN, bool tame = false, bool broke = false) : Equine(name, sex, age)
  {
    this->group = group;
    this->tame = tame;
    this->broke = broke;
    setVariant(MUNDANE);
  }

  Mundane &operator=(Mundane &src)
  {
    if (this != &src)
    {
      this->Equine::operator=(src);
      this->group = src.group;
      this->tame = src.tame;
      this->broke = src.broke;
    }
    return *this;
  }

  virtual ~Mundane()
  {
    return;
  }

  void setGroup(WorkingGroup group);
  void setTame(bool tame);
  void setBroke(bool broke);
  WorkingGroup getGroup() const;
  bool isTame() const;
  bool isBroke() const;
};
