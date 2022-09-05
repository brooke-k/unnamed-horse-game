/**
 * @file printForm.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 05/Sep/2022
 *
 */

#include <iostream>
#include <bitset>
#include <string>

using namespace std;

string addLine(string &baseString, int indentLevel, string addString1, string addString2)
{
  if (indentLevel < 1)
  {
    baseString.append("\n\r\u2503  ");
    if (indentLevel == -1)
    {
      baseString.append("\e[1G\e[80C\u2503");
      string copyString = baseString;

      return copyString;
    }
  }
  else if (indentLevel == 1)
  {
    baseString.append("\n\r\u2503    ");
  }
  else if (indentLevel == 2)
  {
    baseString.append("\n\r\u2503      ");
  }
  else if (indentLevel == 3)
  {
    baseString.append("\n\r\u2503          ");
  }
  else
  {
    baseString.append("\n\r\u2503              ");
  }
  baseString.append(addString1);
  baseString.append(addString2);
  baseString.append("\e[1G\e[80C\u2503");

  string copyString = baseString;

  return copyString;
}

string getTopBorder()
{
  string topBorder = "\n\r\u250F";
  for (int i = 0; i < 80; i++)
  {
    topBorder.append("\e[1D\e[1C\u2501");
  }
  topBorder.append("\e[1D\e[1C\u2513");
  return topBorder;
}

string getInnerBorder()
{
  string innerBorder = "\n\r\u2520";
  for (int i = 0; i < 80; i++)
  {
    innerBorder.append("\e[1D\e[1C\u2500");
  }
  innerBorder.append("\e[1D\e[1C\u2528");
  return innerBorder;
}

string getThickInnerBorder()
{
  string innerBorder = "\n\r\u2523";
  for (int i = 0; i < 80; i++)
  {
    innerBorder.append("\e[1D\e[1C\u2501");
  }
  innerBorder.append("\e[1D\e[1C\u252B");
  return innerBorder;
}

string getBottomBorder()
{
  string bottomBorder = "\n\r\u2517";
  for (int i = 0; i < 80; i++)
  {
    bottomBorder.append("\e[1D\e[1C\u2501");
  }
  bottomBorder.append("\e[1D\e[1C\u251B");
  return bottomBorder;
}

void printTopBorder()
{
  cout << getTopBorder();
}

void printInnerBorder()
{
  cout << getInnerBorder();
}

void printThickInnerBorder()
{
  cout << getThickInnerBorder();
}

void printBottomBorder()
{
  cout << getBottomBorder();
}

#ifndef PRINTFORM
#define PRINTFORM
string addLine(string &baseString, int indentLevel = 0, string addString1 = "", string addString2 = "");
string getTopBorder();
string getInnerBorder();
string getThickInnerBorder();
string getBottomBorder();
void printTopBorder();
void printInnerBorder();
void printThickInnerBorder();
void printBottomBorder();
#endif // PRINTFORM
