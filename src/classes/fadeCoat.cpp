/**
 * @file fadeCoat.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 24/Jul/2022
 *
 */

#include "./include/coats/fadeCoat.hpp"
#ifndef PRINTFORM
#define PRINTFORM
#include "./include/utilities/printForm.hpp"
#endif // PRINTFORM
#include <bitset>
#include <string>
#include <iostream>
#include <regex>

using namespace std;
string FadeCoat::getFadeCoatName() const
{
  return fadeCoatName;
}

void FadeCoat::setFadeCoatName(string fadeCoatName)
{
  this->fadeCoatName = fadeCoatName;
  this->setCoatName(fadeCoatName);
}

/** BNOTE deprecated to be removed */
string FadeCoat::fadeToString()
{
  string infostr = diluteToString();
  infostr.append(getPrintSection());
  infostr = addPrintLine(infostr, "CODE FADE DATA", 0);
  infostr = addPrintLine(infostr, "  Faded coat: ", getFadeCoatName(), 1);
  infostr = addPrintLine(infostr, "Code segment: ", getFadeSet().to_string(), 1);
  infostr = addPrintLine(infostr, "     Alleles: ", getFadeAlleles(), 1);
  return infostr;
}

ostream &operator<<(ostream &os, FadeCoat &fc)
{
  os << fc.getFadeCoatName() << endl;
  return os;
}

string FadeCoat::calculateFadeCoatName(bitset<4> fdset)
{
  string coatName = getDilutionCoatName();
  smatch wMatch;
  regex whiteRegex("^White$", regex::icase);
  if (regex_match(coatName, wMatch, whiteRegex))
  {
    return "White";
  }
  string fadeCoat = "";
  if (fdset[1] || fdset[0]) // check for roan
  {
    coatName.append(" Roan");
  }
  if (fdset[3] || fdset[2]) // check for grey
  {

    fadeCoat = "Grey";
    fadeCoat.append(" (");
    fadeCoat.append(coatName);
    fadeCoat.append(")");
  }
  else
  {
    fadeCoat = coatName;
  }
  return fadeCoat;
}

string FadeCoat::calculateFadeCoatName()
{
  return calculateFadeCoatName(getFadeSet());
}

string FadeCoat::getFadeAlleles()
{
  string alleleString = "";
  bitset<4> fdset = getFadeSet();
  for (int i = 0; i < 4; i++)
  {
    if (!fdset[3 - i])
    {
      alleleString.append("N");
    }
    else
    {
      if (i < 2)
      {
        alleleString.append("G");
      }
      else
      {
        alleleString.append("Rn");
      }
    }
    if (i == 0 || i == 2)
    {
      alleleString.append("/");
    }
    else if (i == 1)
    {
      alleleString.append("-");
    }
  }
  return alleleString;
}

void FadeCoat::fullPrint()
{
  printTopBorder();
  printFormLine("COAT CODE DATA", "", 3);
  printThickInnerBorder();
  printFormLine("ESSENTIAL VALUES", "", 0);
  bitset<32> tempCode = getFullSet();
  printFormLine("Coat name: ", getCoatName(), 1);
  printFormLine("Binary value: ", getSectionedBin(), 1);
  stringstream inhex;
  inhex << hex << getCodeAsULong();
  printFormLine("Hexadecimal value: 0x", inhex.str(), 1);
  printInnerBorder();
  printFormLine("SEGMENTED DATA: ", "", 0);
  printFormLine("Base coat bin.: ", getBaseSet().to_string(), 1);
  inhex << hex << getBaseSet().to_ullong();
  printFormLine("Base coat hex.: 0x", inhex.str(), 1);
  printFormLine("Base coat colour: ", getBaseCoatName(), 1);
  printFormLine("", "");
  printFormLine("Dilution coat bin.: ", getDiluteSet().to_string(), 1);
  printFormLine("Dilution coat colour: ", getDilutionCoatName(), 1);
  inhex << hex << getDiluteSet().to_ullong();
  printFormLine("Dilution coat hex.: 0x", inhex.str(), 1);
  printFormLine("", "");
  printFormLine("Fade coat bin.: ", getFadeSet().to_string(), 1);
  inhex << hex << getFadeSet().to_ullong();
  printFormLine("Fade coat hex.: 0x", inhex.str(), 1);
  printFormLine("Fade coat colour: ", getFadeCoatName(), 1);
  printFormLine("", "");
  printFormLine("White marking bin.: ", getMarkSet().to_string(), 1);
  inhex << hex << getMarkSet().to_ullong();
  printFormLine("White marking hex.: 0x", inhex.str(), 1);
  printFormLine("White marking coat: ", "Undefined", 1);
  printBottomBorder();
}