/**
 * File: Horse.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com)
 * Date: 27/Jan/2022
 *
 */

#include <cstring>
#include <ostream>
#include "Health.hpp"

#define VARIANT_SIZE 4

class Horse : public Health
{
protected:
  char *variant;
  char *name;
  int age;  // Value < 0 signifies an unknown age
  char sex; // To be uppercase only
  int nameLength;
  // NOT IMPLEMENTED YET
  // HorseVariant variant;
  // Lineage lineage;

public:
  friend std::ostream &operator<<(std::ostream &os, Horse &horse);
  char *getName() const;
  int getAge();
  char getSex();
  void setName(char *name, int length);
  void setAge(int age);
  void setSex(char sex);
  virtual void setVariant(const char *);
  virtual void setVariant(char *);
  virtual char *getVariant() const;

  Horse(char *name, int length, char sex, int age = -1, const char *variant = "N/A");
  void addHorseStream(std::ostream &os);

  virtual ~Horse();
  Horse &operator=(Horse &src);
  Horse(Horse &src);
};