/**
 * @file equid.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 05/Sep/2022
 *
 */

#include "../include/equines/equid.hpp"
#include "../printForm.hpp"
#include <string>
#include <iostream>

using namespace std;

void Equid::fullPrint()
{
  string printString = getTopBorder();
  addLine(printString, 0, "EQUID DATA");
  printString.append(getThickInnerBorder());
  addLine(printString, 1, "Full name: ", this->fullName);
  addLine(printString, 1, "Barn name: ", this->barnName);
  addLine(printString, 1, "Sex: ", to_string(this->sex));
  addLine(printString, 1, "Age: ", to_string(this->age));
  addLine(printString, 1, "Height: ", to_string(this->height));
  addLine(printString, 1, "Coat: ", this->coat.getCoatName());
  printString.append(getBottomBorder());
  cout << printString;
  return;
}