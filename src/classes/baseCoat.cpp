/**
 * @file baseCoat.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 19/Jul/2022
 *
 */

#include "./include/baseCoat.hpp"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int BaseCoat::inDecimal(const bool *alleles)
{
  if (alleles + 3 == nullptr)
  {
    return -1;
  }
  int geneDec = 0;

  for (int i = 3, f = 0; i > -1; i--, f++)
  {
    geneDec += ((int)*(alleles + f)) * (int)floor(pow(2, i));
  }
  return geneDec;
}

string BaseCoat::asString(int geneDecimal)
{
  string geneStr = "Invalid base coat. Code: ";
  if (geneDecimal > 15)
  {
    geneStr.append(to_string(geneDecimal));
    return geneStr;
  }

  if (geneDecimal < 4) // Codes 0-3 are Red
  {
    return "Red";
  }
  if (geneDecimal % 4 == 0) // Codes 4, 8, and 12 are Black
  {
    return "Black";
  }

  return "Bay"; // All other codes are Bay
}

string BaseCoat::asString(const bool *alleles)
{
  int geneDecimal = BaseCoat::inDecimal(alleles);
  return BaseCoat::asString(geneDecimal);
}

void BaseCoat::asArray(bool *dest, int geneDecimal)
{
  if (dest != nullptr)
  {
    delete dest;
  }
  dest = new bool[4]{0};
  int lastRemain = geneDecimal;
  int lastQuot = 0;

  for (int i = 3; i > -1; i--)
  {
    lastQuot = lastRemain % 2;
    lastRemain /= 2;
    dest[i] = (bool)lastQuot;
  }
}

void BaseCoat::setGeneDec(int geneDec)
{
  if (geneDec < 0 || geneDec > 15)
  {
    cout << "Invalid base coat decimal gene code: " << geneDec << endl;
    cout << "The base coat decimal gene code was not updated." << endl;
    return;
  }
  this->geneDec = geneDec;
  delete alleles;
  alleles = new bool[4]{0};
  BaseCoat::asArray(alleles, geneDec);
  colourName = BaseCoat::asString(alleles);
}

void BaseCoat::setAllelesArr(const bool *alleles)
{
  int tempDec = BaseCoat::inDecimal(alleles);
  if (tempDec < 0)
  {
    cout << "Invalid alleles array provided as a base coat" << endl;
    cout << "The base coat alleles array was not updated." << endl;
    return;
  }
  this->geneDec = tempDec;
  delete this->alleles;
  this->alleles = new bool[4]{0};
  for (int i = 0; i < 4; i++)
  {
    this->alleles[i] = alleles[i];
  }
  this->colourName = BaseCoat::asString(geneDec);
}

string BaseCoat::getCoatName()
{
  return colourName;
}

int BaseCoat::getGeneDec()
{
  return geneDec;
}

string BaseCoat::getAllelesAlpha()
{
  string asAlpha = "";
  asAlpha.append(string(1, alleles[0] ? 'E' : 'e'));
  asAlpha.append(string(1, alleles[1] ? 'E' : 'e'));
  asAlpha.append(string(1, alleles[2] ? 'A' : 'a'));
  asAlpha.append(string(1, alleles[3] ? 'A' : 'a'));
  return asAlpha;
}

string BaseCoat::getAllelesBin()
{
  string asBin = "";
  for (int i = 0; i < 4; i++)
  {
    asBin.append(to_string((int)alleles[i]));
  }
  return asBin;
}

int BaseCoat::updateAllele(int pos, bool newValue)
{
  if (pos > 4 || pos < 0)
  {
    cout << "Invalid position \"" << pos << "\" provided." << endl;
    cout << "The base coat allele was not updated." << endl;
    return -1;
  }
  alleles[pos] = newValue;
  this->geneDec = BaseCoat::inDecimal(this->alleles);
  this->colourName = BaseCoat::asString(this->alleles);
  return geneDec;
}

ostream &operator<<(ostream &os, BaseCoat &bc)
{
  os << "BASE COAT";
  os << endl;
  os << "  Coat name: " << bc.getCoatName();
  os << endl;
  os << "  Dec.GeneCode: " << bc.getGeneDec();
  os << endl;
  os << "  Binary GeneCode: " << bc.getAllelesBin() << "(" << bc.getAllelesAlpha() << ")";
  os << endl;
  return os;
}