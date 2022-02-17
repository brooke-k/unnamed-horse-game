/**
 * @file Equipment.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 17/Feb/2022
 *
 */

#include <string>
#include <vector>
#include "EquipmentStats.hpp"
#include "EquipmentEnums.hpp"

typedef class Equipment : public EquipmentStats
{
private:
  std::string name;
  EquipType type;
  EquipMatrl material;
  std::vector<EquipColour> colours;

public:
  Equipment(std::string name, EquipType type, std::vector<EquipColour> colours, int fit, int speed, int jumping, int control, int agility, int comfort) : EquipStats(fit, speed, jumping, control, agility, comfort)
  {
    this->name = std::string(name);
    this->type = type;
    this->colours = colours;
  }

  Equipment(std::string name, Equipment typie, std::vector<EquipColour> colours) : EquipStats(-1, -1, -1, -1, -1, -1)
  {
    this->name = std::string(name);
    this->type = type;
    this->colours = colours;
  }

  Equipment &
  operator=(Equipment &e)
  {
    if (this != &e)
    {
      this->name = e.name;
      this->type = e.type;
      this->colours = e.colours;
    }
    return *this;
  }

  Equipment(Equipment &e)
  {
    this->name = e.name;
    this->type = e.type;
    this->colours = e.colours;
  }

  ~Equipment()
  {
    return;
  }

  std::string getName() const;
  void setName(std::string);
  EquipType getType();
  EquipMatrl getMaterial();
  std::vector<EquipColour> getColours();
  void addColour(EquipColour colour);
  void removeColour(EquipColour colour);
  void setColours(std::vector<EquipColour> colours);
  bool isColour(EquipColour colour);
  bool isMulticolour();
  void equipStream(ostream &os);
  friend std::ostream &operator<<(std::ostream &os, Equipment &e);

} Equip;