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

void addLine(string &baseString, int indentLevel, string addString1, string addString2)
{
  if (indentLevel < 1)
  {
    baseString.append("\n\r\u2503  ");
    if (indentLevel == -1)
    {
      baseString.append("\e[80G\u2503");
      return;
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
  baseString.append("\e[80G\u2503");

  return;
}

// void addLine(string &baseString, int indentLevel, string addString)
// {
//   addLine(baseString, indentLevel, addString, "");
//   return;
// }

// void addLine(string &baseString, int indentLevel)
// {
//   addLine(baseString, indentLevel, "");
//   return;
// }

// void addLine(string &baseString)
// {
//   addLine(baseString, -1);
//   return;
// }

using namespace std;

void addLine(string &baseString, int indentLevel = 0, string addString1 = "", string addString2 = "");