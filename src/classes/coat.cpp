/**
 * @file coat.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 25/Jul/2022
 *
 */

#include "./include/coat.hpp"
#include <iostream>
#include <string>
#include <bitset>
#include <sstream>

string Coat::minPrint()
{
  string printString = "";
  printString.append(getPrintTopBorder());
  printString = addPrintLine(printString, "         \u2605 HORSE \u2605 COAT \u2605 INFO \u2605", 3);
  printString.append(getPrintSection());
  printString = addPrintLine(printString, "BINARY CODE:", "", 1);
  printString = addPrintLine(printString, getSectionedBin(), 2);

  stringstream inhex;
  inhex << hex << getCodeAsULong();

  string hexVal = "0x";
  hexVal.append(inhex.str());
  printString = addPrintLine(printString, "HEX CODE", "", 1);
  printString = addPrintLine(printString, hexVal, "", 2);
  printString.append(getPrintSection());
  printString = addPrintLine(printString, "ALLELES", "", 0);
  printString = addPrintLine(printString, getBaseAlleles().append(getDiluteAlleles().append(getFadeAlleles())), "", 1);
  printString.append(getBottomBorder());
  cout << printString << endl;

  return printString;
}
