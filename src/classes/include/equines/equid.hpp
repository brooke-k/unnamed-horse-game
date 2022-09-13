/**
 * @file equid.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 05/Sep/2022
 *
 */

#include <iostream>
#include <string>
#include "../coats/coat.hpp"

using namespace std;

class Equid
{
private:
  string fullName;
  string barnName;
  int age;
  float height;
  char sex;
  Coat coat;

  void modifyDilutions();

protected:
  void addDilution();
  void removeDilution();
  void chooseBaseCoat();

public:
  Equid(string barnName = "Unknown", string fullName = "Unknown", unsigned long int coatCode = chestnut, char sex = 'X', float height = 0, int age = 0)
  {
    this->fullName = fullName;
    this->barnName = barnName;
    this->age = age;
    this->height = height;
    this->sex = sex;
    this->coat = Coat(coatCode);
  }

  Equid(const Equid &eq)
  {
    this->fullName = eq.fullName;
    this->barnName = eq.barnName;
    this->age = eq.age;
    this->sex = eq.sex;
    this->coat = eq.coat;
    return;
  }

  Equid &operator=(const Equid *eq)
  {
    if (this == eq)
    {
      return *this;
    }
    this->fullName = eq->fullName;
    this->barnName = eq->barnName;
    this->age = eq->age;
    this->sex = eq->sex;
    this->coat = eq->coat;
    return *this;
  }

  string getFullName() const;
  string getBarnName() const;
  int getAge() const;
  char getSex() const;
  Coat getCoat();
  string getCoatName() const;

  void setFullName(string name);
  void setBarnName(string name);
  void setAge(int age);
  void setSex(char sex);
  void setCoat(Coat &coat);
  void setCoat(unsigned long int coatCode);

  void createCustomEquid();

  virtual ~Equid() { return; }

  friend ostream &operator<<(ostream &os, Equid &eq);

  void fullPrint();
};