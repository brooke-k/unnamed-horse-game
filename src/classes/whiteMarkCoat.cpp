/**
 * @file whiteMarkCoat.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 09/Aug/2022
 *
 */

#include "./include/whiteMarkCoat.hpp"
#include <ostream>
#include <string>
#include <bitset>

using namespace std;

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
  return "getMarkAllelesNotImplemented";
}

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
  os << mc.markToString();
  os << mc.getBottomBorder() << endl;
  return os;
}