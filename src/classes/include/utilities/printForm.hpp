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

string addLine(string &baseString, int indentLevel = 0, string addString1 = "", string addString2 = "");
void printFormLine(string string1 = "", string string2 = "", int indentLevel = 0);
string getTopBorder();
string getInnerBorder();
string getThickInnerBorder();
string getBottomBorder();
void printTopBorder();
void printInnerBorder();
void printThickInnerBorder();
void printBottomBorder();

void clearFullScreen();
void clearRestofScreen();
void gotoLine(int lineFromTop);
void clearFullLine();
void clearRestOfLine();
void gotoColumn(int colFromLeft);
int getIntSelect();
