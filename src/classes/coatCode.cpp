/**
 * @file coatCode.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 21/Jul/2022
 *
 */

#include <string>
#include <iostream>
#include <bitset>

#include "./include/coatCode.hpp"
using namespace std;

// Operator Overloads
ostream &operator<<(ostream &os, CoatCode &cc)
{

  os << cc.codeToString() << endl;
  return os;
}

// Getters and Setters
unsigned long int CoatCode::getCodeAsULong() const
{
  return code;
}

bitset<32> CoatCode::getFullSet() const
{
  return fullSet;
}

bitset<6> CoatCode::getBaseSet() const { return baseSet; }
bitset<12> CoatCode::getDiluteSet() const { return diluteSet; }
bitset<4> CoatCode::getFadeSet() const { return fadeSet; }
bitset<10> CoatCode::getMarkSet() const { return markSet; }

string CoatCode::getSectionedBin() const
{
  return sectionedBin;
}

string CoatCode::getCodeAsString() const
{
  return to_string(code);
}

string CoatCode::getCoatName() const
{
  return coatName;
}

void CoatCode::setCoatName(string coatName)
{
  this->coatName = coatName;
}

string CoatCode::getPrintTopBorder()
{
  string topBorder = "\n\r\u250f";
  for (int i = 0; i < 47; i++)
  {
    topBorder.append("\u2501");
  }
  return topBorder;
}

string CoatCode::getPrintTitleBorder()
{
  string titleBorder = "\n\r\u2523";
  for (int i = 0; i < 47; i++)
  {
    titleBorder.append("\u2501");
  }
  return titleBorder;
}

string CoatCode::getPrintSection()
{
  string printSection = "\n\r\u2520";
  for (int i = 0; i < 47; i++)
  {
    printSection.append("\u2500");
  }
  return printSection;
}

string CoatCode::codeToString()
{
  string infostr(getPrintTopBorder());
  infostr = addPrintLine(infostr, "      HORSE COAT INFO", 3);
  infostr.append(getPrintTitleBorder());
  infostr = addPrintLine(infostr, "ESSENTIAL COAT DATA", 0);
  infostr.append(getPrintSection());
  infostr = addPrintLine(infostr, "Full Decimal Code: ", 1);
  infostr = addPrintLine(infostr, to_string(code), 2);
  infostr = addPrintLine(infostr, "Full Binary Code: ", 1);
  infostr = addPrintLine(infostr, getFullSet().to_string(), 2);
  infostr = addPrintLine(infostr, "Sectioned bin: ", 1);
  infostr = addPrintLine(infostr, (getSectionedBin()), 2);
  return infostr;
}

string CoatCode::addPrintLine(string baseString, string toPrint, int indentLevel)
{
  string originalString = baseString;
  string printLine = toPrint;
  if (indentLevel < 2)
  {

    originalString.append("\n\r\u2503  ");
  }
  else if (indentLevel == 2)
  {
    originalString.append("\n\r\u2503      ");
  }
  else if (indentLevel == 3)
  {
    originalString.append("\n\r\u2503          ");
  }
  else
  {
    originalString.append("\n\r\u2503              ");
  }

  originalString.append(printLine);
  return originalString;
}

string CoatCode::addPrintLine(string baseString, string toPrint)
{
  return addPrintLine(baseString, toPrint, 0);
}

string CoatCode::getSectionedBin()
{
  string sectionedBin = "";
  for (int i = 31; i >= 0; i--)
  {
    sectionedBin.append(to_string(fullSet[i]));
    if (i == 26 || i == 14 || i == 10) // i is at the last value of a code section
    {
      sectionedBin.append("-");
    }
  }
  return sectionedBin;
}

// Calculators

// Static Methods

// Misc/Bug Finding
