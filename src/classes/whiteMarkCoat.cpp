/**
 * @file whiteMarkCoat.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 09/Aug/2022
 *
 */

#include "./include/coats/whiteMarkCoat.hpp"
#ifndef PRINTFORM
#define PRINTFORM
#include "./include/utilities/printForm.hpp"
#endif // PRINTFORM
#include <ostream>
#include <string>
#include <bitset>

using namespace std;

void WhiteMarkCoat::setMarkCoatName(string markCoatName)
{
  this->markCoatName = markCoatName;
  this->setCoatName(markCoatName);
}

string WhiteMarkCoat::calculateMarkCoatName(bitset<10> mset)
{
  int paintCount = 0;
  string mcoat = getFadeCoatName();

  if (mcoat.compare("White") == 0) // If already white, more white won't change that
  {
    return mcoat;
  }
  string whiteMark = "";

  if (mset[5] || mset[4]) // Check overo first, in case it is fatal.
  {
    if (mset[5] && mset[4]) // Return if overo is fatal
    {
      whiteMark = " Overo (fatal)";
      mcoat.append(whiteMark);
      return mcoat;
    }
    else
    {
      whiteMark = " Overo";
      paintCount++;
    }
  }
  if (mset[7] || mset[6]) // Check for splashed white
  {
    whiteMark = " Splashed White";
    paintCount++;
  }
  if (paintCount < 2 && (mset[3] || mset[2]))
  {
    if (mset[3] && mset[2])
    {
      whiteMark = " Sabino White";
    }
    else
    {
      whiteMark = " Sabino";
    }
    paintCount++;
  }
  if (paintCount < 2 && (mset[1] || mset[0]))
  {
    whiteMark = " Tobiano";
    paintCount++;
  }

  if (paintCount > 1)
  {
    whiteMark = " Paint";
  }

  if (mset[9] || mset[8])
  {
    if (whiteMark.compare("") == 0)
    {
      whiteMark = " Appaloosa";
    }
    else
    {
      whiteMark.append("-Appaloosa");
    }
  }

  mcoat.append(whiteMark);

  return mcoat;
}

string WhiteMarkCoat::getMarkCoatName()
{
  return this->markCoatName;
}

string WhiteMarkCoat::calculateMarkCoatName()
{
  return calculateMarkCoatName(this->getMarkSet());
}

string WhiteMarkCoat::getMarkAlleles()
{
  string temp[] = {"G", "Rn", "LP", "SW", "O", "SB1", "TO"};
  string alleles = "";
  bitset<10> mset = this->getMarkSet();
  for (int i = 0; i < 10; i++)
  {
    if ((mset[9 - i]))
    {
      alleles.append(temp[i / 2]);
    }
    else
    {
      alleles.append("N");
    }
    if (i % 2 == 0)
    {
      alleles.append("/");
    }
    else if (i != 9)
    {
      alleles.append("-");
    }
  }

  return alleles;
}

/** BNOTE deprecated to be removed */
string WhiteMarkCoat::markToString()
{
  string infoStr = fadeToString();
  infoStr.append(getPrintSection());
  infoStr = addPrintLine(infoStr, "WHITE MARKING DATA", 0);
  infoStr = addPrintLine(infoStr, "White marking coat: ", getMarkCoatName());
  infoStr = addPrintLine(infoStr, "Code segment: ", getMarkSet().to_string(), 1);
  infoStr = addPrintLine(infoStr, "     Alleles: ", getMarkAlleles(), 1);
  return infoStr;
}

ostream &operator<<(ostream &os, WhiteMarkCoat &mc)
{
  os << mc.getMarkCoatName() << endl;
  return os;
}

void WhiteMarkCoat::fullPrint()
{
  printTopBorder();
  printFormLine("           COAT CODE DATA: White Marking Coat", "", 3);
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
  printFormLine("Base coat alleles: ", getBaseAlleles(), 1);
  printFormLine("Base coat colour: ", getBaseCoatName(), 1);
  printFormLine("", "");
  printFormLine("Dilution coat bin.: ", getDiluteSet().to_string(), 1);
  printFormLine("Dilution coat colour: ", getDilutionCoatName(), 1);
  printFormLine("Dilution coat alleles: ", getDiluteAlleles(), 1);
  printFormLine("", "");

  printFormLine("Fade coat bin.: ", getFadeSet().to_string(), 1);
  printFormLine("Fade coat alleles: ", getFadeAlleles(), 1);
  printFormLine("Fade coat colour: ", getFadeCoatName(), 1);
  printFormLine("", "");
  printFormLine("White marking bin.: ", getMarkSet().to_string(), 1);
  printFormLine("White marking alleles: ", getMarkAlleles(), 1);
  printFormLine("White marking coat: ", getMarkCoatName(), 1);
  printBottomBorder();
}