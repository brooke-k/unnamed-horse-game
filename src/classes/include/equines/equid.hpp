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

public:
  Equid(string fullName, string barnName, int age, float height, char sex, unsigned long int coatCode)
  {
    this->fullName = fullName;
    this->barnName = barnName;
    this->age = age;
    this->height = height;
    this->sex = sex;
    this->coat = Coat(coatCode);
  }

  void fullPrint();
};