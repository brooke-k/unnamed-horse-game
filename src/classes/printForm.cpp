/**
 * @file printForm.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 07/Sep/2022
 *
 */

#ifndef PRINTFORM
#define PRINTFORM
#include "./include/utilities/printForm.hpp"
#endif // PRINTFORM

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

void printFormLine(string string1, string string2, int indentLevel)
{
  string emptString = "";
  string toPrint = addLine(emptString, indentLevel, string1, string2);
  cout << toPrint;
  return;
}

string getTopBorder()
{
  string topBorder = "\n\r\u250F";
  for (int i = 0; i < 79; i++)
  {
    topBorder.append("\e[1D\e[1C\u2501");
  }
  topBorder.append("\e[1D\e[1C\u2513");
  return topBorder;
}

string getInnerBorder()
{
  string innerBorder = "\n\r\u2520";
  for (int i = 0; i < 79; i++)
  {
    innerBorder.append("\e[1D\e[1C\u2500");
  }
  innerBorder.append("\e[1D\e[1C\u2528");
  return innerBorder;
}

string getThickInnerBorder()
{
  string innerBorder = "\n\r\u2523";
  for (int i = 0; i < 79; i++)
  {
    innerBorder.append("\e[1D\e[1C\u2501");
  }
  innerBorder.append("\e[1D\e[1C\u252B");
  return innerBorder;
}

string getBottomBorder()
{
  string bottomBorder = "\n\r\u2517";
  for (int i = 0; i < 79; i++)
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

void clearFullScreen()
{
  cout << "\e[1;1H";
  cout << "\e[0J";
  return;
}

void clearRestofScreen()
{
  cout << "\e[0J";
  return;
}

void gotoLine(int lineFromTop)
{
  string commandStr = "\e[";
  commandStr.append(to_string(lineFromTop));
  commandStr.append(";1H");
  cout << commandStr;
  return;
}

void clearFullLine()
{
  cout << "\e[1G";
  cout << "\e[1K";
  return;
}

void clearRestOfLine()
{
  cout << "\e[1K";
  return;
}

void gotoColumn(int colFromLeft)
{
  string cmdLine = "\e[";
  cmdLine.append(to_string(colFromLeft));
  cmdLine.append("G");
  cout << cmdLine;
  return;
}

int getIntSelect()
{
  int readVal = 0;
  cout << "Enter selection: ";
  cin >> readVal;
  return readVal;
}
