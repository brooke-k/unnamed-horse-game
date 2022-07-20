/**
 * @file gene.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 19/Jul/2022
 *
 */

#include "./include/gene.hpp"

#include <iostream>

using namespace std;

string Gene::getName() const
{
  return this->name;
}

string Gene::getAl1Alias() const
{
  return this->al1Alias;
}

string Gene::getAl2Alias() const
{
  return this->al2Alias;
}

char Gene::getAllele1() const
{
  return this->allele1;
}

char Gene::getAllele2() const
{
  return this->allele2;
}

void Gene::setName(string name)
{
  this->name = name;
}
void Gene::setAllele1(char allele)
{
  if (allele2 < allele)
  {
    this->allele1 = this->allele2;
    this->allele2 = allele;
    return;
  }
  this->allele1 = allele;
}
void Gene::setAllele1(char allele, string alleleName)
{
  if (allele > allele2)
  {
    char tempAllele = allele2;
    string tempAlias = al2Alias;
    this->setAllele2(allele);
    this->setAllele2(alleleName);
    this->setAllele1(tempAllele);
    this->setAllele1(tempAlias);
    return;
  }
  this->setAllele1(allele);
  this->setAllele1(alleleName);
}
void Gene::setAllele1(string alleleName)
{
  this->al1Alias = alleleName;
}
void Gene::setAllele2(char allele)
{
  if (this->allele1 > allele)
  {
    this->allele2 = this->allele1;
    this->allele1 = allele;
    return;
  }
  this->allele2 = allele;
}

void Gene::setAllele2(string alleleName)
{
  this->al2Alias = alleleName;
}
void Gene::setAllele2(char allele, string alleleName)
{
  if (allele > allele1)
  {
    char tempAllele = allele1;
    string tempAlias = al1Alias;
    this->setAllele1(allele);
    this->setAllele1(alleleName);
    this->setAllele2(tempAllele);
    this->setAllele2(tempAlias);
    return;
  }
  this->setAllele1(allele);
  this->setAllele1(alleleName);
}

void Gene::setAlleles(char allele1, char allele2)
{
  if (allele1 > allele2)
  {
    this->setAllele1(allele2);
    this->setAllele2(allele1);
    return;
  }
  this->setAllele1(allele1);
  this->setAllele2(allele2);
}

void Gene::setAlleles(char allele1, string alias1, char allele2, string alias2)
{
  setAllele1(allele1, alias1);
  setAllele2(allele2, alias2);
}

ostream &operator<<(ostream &out, const Gene &src)
{
  out << "GENE DATA";
  out << endl;
  out << "  Codes for: " << src.getName();
  out << endl;
  out << "  Alleles: " << src.getAllele1() << src.getAllele2() << " [" << src.getAl1Alias() << "][" << src.getAl2Alias() << "]";
  out << endl;

  return out;
}