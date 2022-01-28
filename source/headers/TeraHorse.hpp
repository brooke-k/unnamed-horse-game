/**
 * File: TeraHorse.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com)
 * Date: 27/Jan/2022
 *
 */

#include <iostream>
#include "./Horse.hpp"

using namespace std;

class TeraHorse: public Horse {
private:
  // Discipline discipline;
  // Appearance appearance;
  // Location birthPlace;
  bool broke;
public:
  TeraHorse(char* name, int nameLength,  char sex, bool broke = false,int age = -1): Horse(name, nameLength, sex, age, "TER"){
    this->broke = broke;
  }

  TeraHorse(TeraHorse& src): Horse(src.name, src.nameLength, src.sex, src.age){
    this->broke = src.broke;
  }

  TeraHorse& operator=(TeraHorse&src){
    if(this != &src){
      if(this->name != NULL){
        delete this->name;
      }
      this->name = new char[src.nameLength+1]{'\0'};
      strcpy(this->name, src.name);
      this->nameLength = src.nameLength;
      this->broke = src.broke;
      this->age = src.age;
      this->sex = src.sex;
    }
  }

  bool isBroke();
   friend std::ostream &operator<<(std::ostream &os, TeraHorse &horse);

  void setBroke(bool broke);

};