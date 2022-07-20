/**
 * @file baseCoat.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 19/Jul/2022
 *
 */

#include "./include/baseCoat.hpp"
#include <string>
#include <iostream>
using namespace std;

string BaseCoat::calculateBaseCoatColour(bool redFactor1Dom, bool redFactor2Dom, bool agouti1Dom, bool agouti2Dom)
{
  if (!(redFactor1Dom || redFactor2Dom)) // Both recessive red
  {
    return "Red";
  }

  if (!(agouti1Dom || agouti2Dom)) // Black all over
  {
    return "Black";
  }
  else // Black points
  {
    return "Bay";
  }
}

string BaseCoat::calculateBaseCoat(char rf1, char rf2, char ag1, char ag2)
{
  if (toupper(rf1) != 'E' || toupper(rf2) != 'E' || toupper(ag1) != 'A' || toupper(ag2) != 'A')
  {
    return "Undetermined";
  }
  return BaseCoat::calculateBaseCoatColour((rf1 == 'E'), (rf2 == 'E'), (ag1 == 'A'), (ag2 == 'A'));
}
