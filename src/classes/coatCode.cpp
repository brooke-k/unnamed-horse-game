/**
 * @file coatCode.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 21/Jul/2022
 *
 */
#ifndef PRINTFORM
#define PRINTFORM
#include "./include/utilities/printForm.hpp"
#endif // PRINTFORM
#include <string>
#include <iostream>
#include <bitset>
#include <sstream>

#include "./include/coats/coatCode.hpp"
using namespace std;

// Operator Overloads
ostream &operator<<(ostream &os, CoatCode &cc)
{

  os << cc.codeToString() << endl;
  os << cc.getBottomBorder() << endl;
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

/** BNOTE Deprecated method. Being refactored out. */
string CoatCode::getPrintTopBorder()
{
  string topBorder = "\n\r\u250F";
  for (int i = 0; i < 78; i++)
  {
    topBorder.append("\u2501");
  }
  topBorder.append("\u2513");
  return topBorder;
}

/** BNOTE Deprecated method. Being refactored out. */
string CoatCode::getPrintTitleBorder()
{
  string titleBorder = "\n\r\u2523";
  for (int i = 0; i < 78; i++)
  {
    titleBorder.append("\u2501");
  }
  titleBorder.append("\u252B");
  return titleBorder;
}

/** BNOTE Deprecated method. Being refactored out. */
string CoatCode::getBottomBorder()
{
  string bottomBorder = "\n\r\u2517";
  for (int i = 0; i < 78; i++)
  {
    bottomBorder.append("\u2501");
  }
  bottomBorder.append("\u251B");
  return bottomBorder;
}

/** BNOTE Deprecated method. Being refactored out. */
string CoatCode::getPrintSection()
{
  string printSection = "\n\r\u2520";
  for (int i = 0; i < 78; i++)
  {
    printSection.append("\u2500");
  }
  printSection.append("\u2528");

  return printSection;
}

string CoatCode::codeToString()
{
  string infostr(getPrintTopBorder());
  infostr = addPrintLine(infostr, "         \u2605 HORSE \u2605 COAT \u2605 INFO \u2605", 3);
  infostr.append(getPrintTitleBorder());
  infostr = addPrintLine(infostr, "ESSENTIAL COAT DATA");
  stringstream inhex;
  inhex << hex << getCodeAsULong();

  string hexVal = "0x";
  hexVal.append(inhex.str());
  infostr = addPrintLine(infostr, "Hex code: ", hexVal, 1);

  infostr = addPrintLine(infostr, "Decimal code: ", to_string(code), 1);
  infostr = addPrintLine(infostr, " Binary code: ", getFullSet().to_string(), 1);
  infostr = addPrintLine(infostr, " Seg. binary: ", getSectionedBin(), 1);
  return infostr;
}

/** BNOTE Deprecated method. Being refactored out. */
string CoatCode::addPrintLine(string baseString, string toPrintFirst, string toPrintSecond, int indentLevel)
{
  string originalString = baseString;
  string printLine = toPrintFirst;
  if (indentLevel < 1)
  {
    originalString.append("\n\r\u2503  ");
  }
  else if (indentLevel == 1)
  {
    originalString.append("\n\r\u2503    ");
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
  originalString.append(toPrintSecond);
  originalString.append("\e[80G\u2503");
  return originalString;
}

/** BNOTE Deprecated method. Being refactored out. */
string CoatCode::addPrintLine(string baseString, string toPrint, int indentLevel)
{
  return addPrintLine(baseString, toPrint, "", indentLevel);
}

/** BNOTE Deprecated method. Being refactored out. */
string CoatCode::addPrintLine(string baseString, string toPrint)
{
  return addPrintLine(baseString, toPrint, "", 0);
}

/** BNOTE Deprecated method. Being refactored out. */
string CoatCode::addPrintLine(string baseString, string toPrintFirst, string toPrintSecond)
{
  return addPrintLine(baseString, toPrintFirst, toPrintSecond, 0);
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
void CoatCode::fullPrint()
{
  printTopBorder();
  printFormLine("COAT CODE DATA", "", 3);
  printThickInnerBorder();
  printFormLine("ESSENTIAL VALUES", "", 0);
  bitset<32> tempCode(code);
  printFormLine("Binary value: ", getSectionedBin(), 1);
  stringstream inhex;
  inhex << hex << getCodeAsULong();
  printFormLine("Hexadecimal value: 0x", inhex.str(), 1);
  printInnerBorder();
  printFormLine("SEGMENTED DATA: ", "", 0);
  printFormLine("Base coat bin.: ", getBaseSet().to_string(), 1);
  inhex << hex << getBaseSet().to_ullong();
  printFormLine("Base coat hex.: 0x", inhex.str(), 1);
  printFormLine("Base coat colour: ", "Undefined", 1);
  printFormLine("", "");
  printFormLine("Dilution coat bin.: ", getDiluteSet().to_string(), 1);
  printFormLine("Dilution coat colour: ", "Undefined", 1);
  inhex << hex << getDiluteSet().to_ullong();
  printFormLine("Dilution coat hex.: 0x", inhex.str(), 1);
  printFormLine("", "");
  printFormLine("Fade coat bin.: ", getFadeSet().to_string(), 1);
  inhex << hex << getFadeSet().to_ullong();
  printFormLine("Fade coat hex.: 0x", inhex.str(), 1);
  printFormLine("Fade coat colour: ", "Undefined", 1);
  printFormLine("", "");
  printFormLine("White marking bin.: ", getMarkSet().to_string(), 1);
  inhex << hex << getMarkSet().to_ullong();
  printFormLine("White marking hex.: 0x", inhex.str(), 1);
  printFormLine("White marking coat colour: ", "Undefined", 1);
  printBottomBorder();
}