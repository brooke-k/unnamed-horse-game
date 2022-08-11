/**
 * @file fadeCoat.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 24/Jul/2022
 *
 */

#include "./include/fadeCoat.hpp"
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
  os << fc.fadeToString();
  os << fc.getBottomBorder() << endl;
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