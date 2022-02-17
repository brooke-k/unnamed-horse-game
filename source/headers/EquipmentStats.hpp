/**
 * @file EquipmentStats.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 16/Feb/2022
 *
 */

#include <cmath>
#include <iostream>

typedef class EquipmentStats
{
private:
  int fit;
  int speed;
  int jumping;
  int control;
  int agility;
  int comfort;
  int overall;

public:
  EquipmentStats()
  {
    fit = 1;
    speed = 1;
    jumping = 1;
    control = 1;
    agility = 1;
    comfort = 1;
    overall = 1;
  }
  EquipmentStats(int fit, int speed, int jumping, int control, int agility, int comfort)
  {
    this->fit = fit;
    this->speed = speed;
    this->jumping = jumping;
    this->control = control;
    this->agility = agility;
    this->comfort = comfort;
    this->overall = (int)floor((fit + speed + jumping + comfort + control + agility) / 6);
  }

  int getFit();
  int getSpeed();
  int getJumping();
  int getAgility();
  int getControl();
  int getComfort();
  int getOverall();

  void equipStatStream(std::ostream &os);
  friend std::ostream &operator<<(std::ostream &os, EquipmentStats &eq);
} EquipStats;