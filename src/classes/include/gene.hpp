/**
 * @file gene.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 19/Jul/2022
 *
 */

#include <string>
using namespace std;
class Gene
{
private:
  char allele1;
  char allele2;
  string name;
  string al1Alias;
  string al2Alias;

protected:
public:
  Gene(char allele1, char allele2, const char *name = "Unnamed Gene", const char *al1Alias = "Allele 1", const char *al2alias = "Allele 2")
  {
    this->allele1 = allele1;
    this->allele2 = allele2;
    this->name = name;
    this->al1Alias = al1Alias;
    this->al2Alias = al2Alias;
  }

  Gene(const Gene *src)
  {
    if (this == src)
    {
      return;
    }
    allele1 = src->allele1;
    allele2 = src->allele2;
    name = src->name;
    al1Alias = src->al1Alias;
    al2Alias = src->al2Alias;
    return;
  }

  Gene &operator=(const Gene *src)
  {
    if (this == src)
    {
      return *this;
    }
    allele1 = src->allele1;
    allele2 = src->allele2;
    name = src->name;
    al1Alias = src->al1Alias;
    al2Alias = src->al2Alias;
    return *this;
  }

  friend ostream &operator<<(ostream
                                 &out,
                             const Gene &src);

  string getName() const;
  char getAllele1() const;
  char getAllele2() const;
  string getAl1Alias() const;
  string getAl2Alias() const;
};
