/**
 * @file baseCoat.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 19/Jul/2022
 *
 */

#include "./gene.hpp"
#include <string>
class BaseCoat
{
private:
  Gene agouti;
  Gene redFactor;
  string colourName;
  string calculateBaseCoat(char rf1, char rf2, char ag1, char ag2);

public:
  // BaseCoat()
  // {
  //   redFactor = Gene('E', 'e', "Red Factor", "MC1R_1", "MC1R_2");
  //   agouti = Gene('A', 'a', "Agouti (black points)", "ASIP_1", "ASIP_2");
  //   colourName = this->calculateBaseCoat(redFactor.getAllele1(), redFactor.getAllele2(), agouti.getAllele1(), agouti.getAllele2());
  // }

  BaseCoat(bool allRed = false, bool allBlack = false, bool blackHetero = true, bool redHetero = true)
  {
    redFactor = Gene('E', 'e', "RedFactor", "MC1R_1", "MC1R_2");
    agouti = Gene('A', 'a', "Agouti (black points)", "ASIP_1", "ASIP_2");
    if (allRed)
    {
      redFactor.setAlleles('e', 'e');
    }
    else
    {
      if (!redHetero)
      {
        redFactor.setAlleles('E', 'E');
      }
    }
    if (allBlack)
    {
      agouti.setAlleles('a', 'a');
    }
    else
    {
      if (!blackHetero)
      {
        agouti.setAlleles('A', 'A');
      }
    }
    colourName = this->calculateBaseCoat(redFactor.getAllele1(), redFactor.getAllele2(), agouti.getAllele1(), agouti.getAllele2());
  }

  static string calculateBaseCoatColour(bool redFactor1Dom, bool redFactor2Dom, bool agouti1Dom, bool agouti2Dom);

  string getBaseCoatColour()
  {
    return colourName;
  }
};