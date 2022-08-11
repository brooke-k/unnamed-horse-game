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
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>

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

Coat &Coat::operator+=(const Coat &rhs)
{
  bitset<32> orBits = (this->getFullSet() | rhs.getFullSet());
  *this = Coat(orBits.to_ulong());
  return *this;
}

Coat &operator+(Coat &lhs, const Coat &rhs)
{
  bitset<32> orBits = (lhs.getFullSet() | rhs.getFullSet());
  lhs = Coat(orBits.to_ulong());
  return lhs;
}

Coat &Coat::operator+=(const unsigned long int &bval)
{
  bitset<32> bset(bval);
  bitset<32> orBits = (this->getFullSet() | bset);
  *this = Coat(orBits.to_ulong());
  return *this;
}

ostream &operator<<(ostream &os, Coat &coat)
{
  os << endl;
  os << "Hex Code: 0x" << setfill('0') << setw(8) << right << hex << coat.getFullSet().to_ulong() << endl;
  os << "Coat Name: " << coat.getCoatName() << endl;
  os << "Bin Code: " << coat.getFullSet().to_string() << endl;
  os << endl;
  os.unsetf(ios_base::basefield);
  return os;
}

Coat operator*(Coat &rhs, const Coat &lhs)
{
  Coat resultCoat(rhs);
  resultCoat *= lhs;
  return resultCoat;
}

Coat &Coat::operator*=(const Coat &rhs)
{
  random_device rDevice;
  mt19937 mRandGen(rDevice());
  uniform_int_distribution<> randDistro(1, 4);
  int rVal = randDistro(mRandGen);

  bitset<32> resultBits(0);
  bitset<32> lhsBits = this->getFullSet();
  bitset<32> rhsBits = rhs.getFullSet();

  int lhsTempSum;
  int rhsTempSum;
  for (int i = 31; i > 0; i -= 2)
  {
    rVal = randDistro(mRandGen);
    lhsTempSum = (int)lhsBits[i] + (int)lhsBits[i - 1];
    rhsTempSum = (int)rhsBits[i] + (int)rhsBits[i - 1];
    if (lhsTempSum != rhsTempSum)
    {
      if (abs(lhsTempSum - rhsTempSum) == 2) // Will occur if one gene is XX and the other is xx, so all possibilities could occur.
      {
        resultBits[i] = (int)(rVal % 4);
        resultBits[i] = (int)(rVal % 2);
      }
      else
      {
        if (lhsTempSum + rhsTempSum == 3) // Case of XX and Xx, so only two possibilities.
        {
          // cout << "Case 2: XX and Xx" << endl;
          resultBits[i] = 1;
          resultBits[i - 1] = (int)(rVal % 2);
        }
        else // case of xx and Xx, so only two possibilities
        {
          // cout << "Case 3: xx and Xx" << endl;
          resultBits[i] = (int)(rVal % 2);
          resultBits[i - 1] = 0;
        }
      }
    }
    else
    {
      if (lhsBits[i] == lhsBits[i - 1]) // Both lhs and rhs bits are the same. So, the only outcome is the parent's values.
      {
        // cout << "Case 4: XX and XX or xx and xx" << endl;
        resultBits[i] = rhsBits[i];
        resultBits[i - 1] = rhsBits[i - 1];
      }
      else // Both rhs and lhs bits are Xx or xX. In either case, all values are possible.
      {
        // cout << "Case 5: Xx and Xx";
        resultBits[i] = (int)(rVal % 4);
        resultBits[i] = (int)(rVal % 2);
      }
    }
  }
  cout << endl;
  *this = Coat(resultBits.to_ulong());
  return *this;
}
