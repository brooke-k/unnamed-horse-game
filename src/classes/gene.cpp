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

ostream &operator<<(ostream &out, const Gene &src)
{
  out << "GENE DATA";
  out << endl;
  out << "  Name: " << src.getName();
  out << endl;
  out << "  Alleles: " << src.getAllele1() << src.getAllele2() << " [" << src.getAl1Alias() << "][" << src.getAl2Alias() << "]";
  out << endl;

  return out;
}