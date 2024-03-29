/**
 * @file equid.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 05/Sep/2022
 *
 */

#include "./include/equines/equid.hpp"
#ifndef PRINTFORM
#define PRINTFORM
#include "./include/utilities/printForm.hpp"
#endif // PRINTFORM
#include <string>
#include <iostream>

using namespace std;

void Equid::fullPrint()
{
  string printString = getTopBorder();
  addLine(printString, 0, "EQUID DATA");
  printString.append(getThickInnerBorder());
  addLine(printString, 1, "Full name: ", this->fullName);
  addLine(printString, 1, "Barn name: ", this->barnName);
  addLine(printString, 1, "Sex: ", string(1, this->sex));
  addLine(printString, 1, "Age: ", to_string(this->age));
  addLine(printString, 1, "Height: ", to_string(this->height));
  addLine(printString, 1, "Coat: ", this->coat.getCoatName());
  printString.append(getBottomBorder());
  cout << printString;
  return;
}

ostream &operator<<(ostream &os, Equid &eq)
{
  string printString = getTopBorder();
  addLine(printString, 0, "EQUID DATA");
  printString.append(getThickInnerBorder());
  addLine(printString, 1, "Full name: ", eq.fullName);
  addLine(printString, 1, "Barn name: ", eq.barnName);
  addLine(printString, 1, "Sex: ", string(1, eq.sex));
  addLine(printString, 1, "Age: ", to_string(eq.age));
  addLine(printString, 1, "Height: ", to_string(eq.height));
  addLine(printString, 1, "Coat: ", eq.coat.getCoatName());
  printString.append(getBottomBorder());
  os << printString;
  return os;
}

// Getters and Setters

string Equid::getFullName() const
{
  return fullName;
}

string Equid::getBarnName() const
{
  return barnName;
}

int Equid::getAge() const
{
  return age;
}

char Equid::getSex() const
{
  return sex;
}

Coat Equid::getCoat()
{
  Coat retCoat(this->coat);
  return retCoat;
}

string Equid::getCoatName() const
{
  return this->coat.getCoatName();
}

void Equid::setFullName(string name)
{
  this->fullName = name;
  return;
}

void Equid::setBarnName(string name)
{
  this->fullName = name;
  return;
}

void Equid::setAge(int age)
{
  this->age = age;
  return;
}

void Equid::setSex(char sex)
{
  this->sex = sex;
  return;
}

void Equid::setCoat(Coat &coat)
{
  this->coat = Coat(coat);
  return;
}

void Equid::setCoat(unsigned long int coatCode)
{
  this->coat = Coat(coatCode);
  return;
}

void Equid::createCustomEquid()
{

  int inputVal = 0;
  while (true)
  {
    clearFullScreen();
    printTopBorder();
    printFormLine("MODIFY EQUID COAT: \"", this->getBarnName().append("\""), 2);
    printBottomBorder();
    this->fullPrint();
    cout << endl;
    cout << "What would you like to change? " << endl;
    cout << "    1. Change base coat (Currently \"" << this->getCoat().getBaseCoatName() << "\")" << endl;
    cout << "    2. Modify dilutions (current dilution coat is \"" << this->getCoat().getDilutionCoatName() << "\")" << endl;
    cout << "    3. Modify fades (current fade coat is \"" << this->getCoat().getFadeCoatName() << "\")" << endl;
    cout << "    4. Modify white markings (current white marks coat is \"" << this->getCoat().getMarkCoatName() << "\")" << endl;
    cout << "    5. Exit customization " << endl;
    cout << endl;
    inputVal = getIntSelect();

    if (inputVal > 5 || inputVal < 1)
    {
      cout << "Sorry, that input could not be understood. Please enter one of the provided options." << endl;
      cout << endl;
    }
    else
    {
      switch (inputVal)
      {
      case 1:
        chooseBaseCoat();
        break;
      case 2:
        modifyDilutions();
        break;
      case 3:
        modifyFades();
        break;
      case 4:
        cout << "Modify white markings not implemented yet. " << endl;
        break;
      case 5:
        cout << "Exiting customization." << endl;
        cout << endl;
        return;
      default:
        break;
      }
      break;
    }
  }

  cout << "Current equine is: " << endl;
  this->fullPrint();
  return;
}

void Equid::chooseBaseCoat()
{
  int inputVal = 0;
  while (true)
  {
    clearFullScreen();
    printTopBorder();
    printFormLine("MODIFY DILUTIONS", "", 2);
    printBottomBorder();
    gotoLine(6);
    cout << "Choose new base coat: " << endl;
    cout << "    1. Chestnut" << endl;
    cout << "    2. Bay" << endl;
    cout << "    3. Black" << endl;
    cout << "    4. White" << endl;
    cout << endl;
    inputVal = getIntSelect();
    if (inputVal > 4 || inputVal < 1)
    {
      cout << "Sorry, that selection could not be understood. Please choose from the listed options." << endl;
    }
    else
    {
      bitset<32> newBase(chestnut);
      switch (inputVal)
      {
      case 1:
        newBase = bitset<32>(chestnut);
        break;
      case 2:
        newBase = bitset<32>(bay);
        break;
      case 3:
        newBase = bitset<32>(black);
        break;
      case 4:
        newBase = bitset<32>(white);
        break;
      default:
        break;
      }
      bitset<32> currentCoat(this->getCoat().getCodeAsULong());
      for (int i = 31; i > 25; i--)
      {
        currentCoat[i] = newBase[i];
      }
      gotoLine(6);
      clearRestofScreen();
      this->setCoat(currentCoat.to_ulong());
      cout << "Current base coat is: " << this->getCoat().getCoatName() << endl;
      cout << "Current overall coat is: " << this->getCoatName() << endl;
      pressEnterToCont();
      return;
      break;
    }
  }
}

void Equid::modifyDilutions()
{

  int inputVal;
  while (true)
  {
    clearFullScreen();
    printTopBorder();
    printFormLine("MODIFY DILUTIONS", "", 2);
    printBottomBorder();
    gotoLine(6);
    cout << "Choose how to modify dilutions: " << endl;
    cout << "    1. Add dilution(s)" << endl;
    cout << "    2. Remove dilution(s)" << endl;
    cout << "    3. Cancel modifications" << endl;
    cout << endl;
    inputVal = getIntSelect();

    if (inputVal > 3 || inputVal < 1)
    {
      cout << "Sorry, that input was not understood. Please enter one of the available options. " << endl;
      cout << endl;
      pressEnterToCont();
    }
    else
    {
      switch (inputVal)
      {
      case 1:
        this->addDilution();
        break;
      case 2:
        this->removeDilution();
        break;
      case 3:
        cout << "Cancelling dilution modifications." << endl;

        return;
      default:
        break;
      }
    }
  }
}

void Equid::addDilution()
{

  int inputVal = 0;
  string chosenDilute = "?";

  while (true)
  {
    clearFullScreen();
    printTopBorder();
    printFormLine("MODIFY DILUTIONS: ADD DILUTIONS", "", 2);
    printBottomBorder();
    gotoLine(6);
    cout << "Possible dilutions: " << endl;
    cout << "    0. Keep current dilution. " << endl;
    cout << "    1. Single cream" << endl;
    cout << "    2. Double cream" << endl;
    cout << "    3. Single champagne" << endl;
    cout << "    4. Double champagne" << endl;
    cout << "    5. Single pearl" << endl;
    cout << "    6. Double pearl" << endl;
    cout << "    7. Pseudo pearlino" << endl;
    cout << "    9. Single silver" << endl;
    cout << "    10. Double silver" << endl;
    cout << "    11. Wild dun" << endl;
    cout << "    12. Wild markings" << endl;
    cout << endl;
    inputVal = getIntSelect();
    if (inputVal > 12 || inputVal < 0)
    {
      cout << "Sorry, that selection could not be understood. Please enter a value from the list provided." << endl;
      cout << endl;
    }
    else
    {
      Coat removalVal = this->getCoat();
      switch (inputVal)
      {
      case 1:
        removalVal += singleCream;
        chosenDilute = "\"single cream\"";
        break;
      case 2:
        removalVal += doubleCream;
        chosenDilute = "\"double cream\"";
        break;
      case 3:
        removalVal += champagne;
        chosenDilute = "\"champagne\"";
        break;
      case 4:
        removalVal += doubleChampagne;
        chosenDilute = "\"double champagne\"";
        break;
      case 5:
        removalVal += heterPearl;
        chosenDilute = "\"single pearl\"";

        break;
      case 6:
        removalVal += homoPearl;
        chosenDilute = "\"double pearl\"";

        break;
      case 7:
        removalVal += pseudoPearl;
        chosenDilute = "\"pseudo pearl\"";

        break;
      case 8:
        removalVal += heterSilver;
        chosenDilute = "\"single silver\"";

        break;
      case 9:
        removalVal += homoSilver;
        chosenDilute = "\"double silver\"";
        break;
      case 10:
        removalVal += wildDun;
        chosenDilute = "\"wild dun\"";

        break;
      case 11:
        removalVal += wild;
        chosenDilute = "\"wild\"";

        break;
      case 0:
        break;
      }
      this->setCoat(removalVal);
      gotoLine(6);
      clearRestofScreen();
      cout << "Dilution " << chosenDilute << " added." << endl;
      cout << "Current diluted coat is \"" << this->getCoat().getDilutionCoatName() << "\"" << endl;
      cout << "Current overall coat is: " << this->getCoatName() << endl;
      cout << endl;
      while (true)
      {
        cout << endl;
        cout << "Add another dilution?" << endl;
        cout << "    1. Yes" << endl;
        cout << "    2. No" << endl;
        cout << endl;
        inputVal = getIntSelect();
        if (inputVal > 2 || inputVal < 1)
        {
          cout << "Sorry, that input could not be understood. Please choose an input from the provided selection." << endl;
        }
        else
        {
          if (inputVal == 1)
          {
            this->addDilution();
            break;
          }
          else
          {
            return;
            break;
          }
        }
      }
      break;
    }
  }
}

void Equid::removeDilution()

{

  int inputVal = 0;

  while (true)
  {
    clearFullScreen();
    printTopBorder();
    printFormLine("MODIFY DILUTIONS: REMOVE DILUTIONS", "", 2);
    printBottomBorder();
    gotoLine(6);
    cout << "Possible dilutions: " << endl;
    cout << "    0. Keep current dilution. " << endl;
    cout << "    1. Single cream" << endl;
    cout << "    2. Double cream" << endl;
    cout << "    3. Single champagne" << endl;
    cout << "    4. Double champagne" << endl;
    cout << "    5. Single pearl" << endl;
    cout << "    6. Double pearl" << endl;
    cout << "    7. Pseudo pearlino" << endl;
    cout << "    9. Single silver" << endl;
    cout << "    10. Double silver" << endl;
    cout << "    11. Wild dun" << endl;
    cout << "    12. Wild markings" << endl;
    cout << endl;
    inputVal = getIntSelect();
    string chosenDilute = "?";
    if (inputVal > 12 || inputVal < 0)
    {
      cout << "Sorry, that selection could not be understood. Please enter a value from the list provided." << endl;
      this->removeDilution();
      return;
      break;
    }
    else
    {
      bitset<32> tempCode = this->getCoat().getFullSet();

      unsigned long int removalVal = 0;
      switch (inputVal)
      {
      case 1:
        removalVal += singleCream;
        chosenDilute = "\"single cream\"";
        break;
      case 2:
        removalVal += doubleCream;
        chosenDilute = "\"double cream\"";
        break;
      case 3:
        removalVal += champagne;
        chosenDilute = "\"champagne\"";
        break;
      case 4:
        removalVal += doubleChampagne;
        chosenDilute = "\"double champagne\"";
        break;
      case 5:
        removalVal += heterPearl;
        chosenDilute = "\"single pearl\"";

        break;
      case 6:
        removalVal += homoPearl;
        chosenDilute = "\"double pearl\"";

        break;
      case 7:
        removalVal += pseudoPearl;
        chosenDilute = "\"pseudo pearl\"";

        break;
      case 8:
        removalVal += heterSilver;
        chosenDilute = "\"single silver\"";

        break;
      case 9:
        removalVal += homoSilver;
        chosenDilute = "\"double silver\"";
        break;
      case 10:
        removalVal += wildDun;
        chosenDilute = "\"wild dun\"";

        break;
      case 11:
        removalVal += wild;
        chosenDilute = "\"wild\"";

        break;
      case 0:
        break;
      }
      Coat tempCoat = this->getCoat();
      tempCoat -= removalVal;
      this->setCoat(tempCoat);
      gotoLine(6);
      clearRestofScreen();
      cout << "Dilution " << chosenDilute << " removed." << endl;
      cout << endl;

      cout << "Current diluted coat is \"" << this->getCoat().getDilutionCoatName() << "\"" << endl;
      cout << "Current overall coat is: " << this->getCoatName() << endl;
      cout << endl;
      while (true)
      {
        cout << endl;
        cout << "Remove another dilution?" << endl;
        cout << "    1. Yes" << endl;
        cout << "    2. No" << endl;
        cout << endl;
        inputVal = getIntSelect();
        if (inputVal > 2 || inputVal < 1)
        {
          cout << "Sorry, that input could not be understood. Please choose an input from the provided selection." << endl;
          pressEnterToCont();
        }
        else
        {
          if (inputVal == 1)
          {
            removeDilution();
            return;
          }
          else
          {
            return;
            break;
          }
        }
      }
      break;
    }
  }
}

void Equid::modifyFades()
{

  int inputVal;
  while (true)
  {
    clearFullScreen();
    printTopBorder();
    printFormLine("MODIFY FADEs", "", 2);
    printBottomBorder();
    gotoLine(6);
    cout << "Choose how to modify fades: " << endl;
    cout << "    1. Add fades(s)" << endl;
    cout << "    2. Remove fades(s)" << endl;
    cout << "    3. Cancel fade modification" << endl;
    cout << endl;
    inputVal = getIntSelect();

    if (inputVal > 3 || inputVal < 1)
    {
      cout << "Sorry, that input was not understood. Please enter one of the available options. " << endl;
      cout << endl;
      pressEnterToCont();
    }
    else
    {
      switch (inputVal)
      {
      case 1:
        this->addFade();
        break;
      case 2:
        this->removeFade();
        break;
      case 3:
        cout << "Cancelling fade modifications." << endl;

        return;
      default:
        break;
      }
    }
  }
}

void Equid::addFade()
{
  int inputVal = 0;
  string chosenFade = "?";
  while (true)
  {
    clearFullScreen();
    printTopBorder();
    printFormLine("MODIFY FADES: ADD FADE", "", 2);
    printBottomBorder();
    gotoLine(6);
    cout << "Possible fades: " << endl;
    cout << "    0. Keep current fades. " << endl;
    cout << "    1. Single grey" << endl;
    cout << "    2. Double grey" << endl;
    cout << "    3. Single roan" << endl;
    cout << "    4. Double roan" << endl;
    cout << endl;
    inputVal = getIntSelect();
    if (inputVal > 4 || inputVal < 0)
    {
      cout << "Sorry, that selection could not be understood. Please enter a value from the list provided." << endl;
      cout << endl;
    }
    else
    {
      Coat addVal = this->getCoat();
      switch (inputVal)
      {
      case 1:
        addVal += heterGrey;
        chosenFade = "\"single grey\"";
        break;
      case 2:
        addVal += homoGrey;
        chosenFade = "\"double grey\"";
        break;
      case 3:
        addVal += heterRoan;
        chosenFade = "\"single roan\"";
        break;
      case 4:
        addVal += homoRoan;
        chosenFade = "\"double roan\"";
        break;
      case 0:
        break;
      }
      this->setCoat(addVal);
      gotoLine(6);
      clearRestofScreen();
      cout << "Fade " << chosenFade << " added." << endl;
      cout << "Current faded coat is \"" << this->getCoat().getFadeCoatName() << "\"" << endl;
      cout << "Current overall coat is: " << this->getCoatName() << endl;
      cout << endl;
      while (true)
      {
        cout << endl;
        cout << "Add another fade?" << endl;
        cout << "    1. Yes" << endl;
        cout << "    2. No" << endl;
        cout << endl;
        inputVal = getIntSelect();
        if (inputVal > 2 || inputVal < 1)
        {
          cout << "Sorry, that input could not be understood. Please choose an input from the provided selection." << endl;
        }
        else
        {
          if (inputVal == 1)
          {
            this->addFade();
            break;
          }
          else
          {
            return;
            break;
          }
        }
      }
      break;
    }
  }
}

void Equid::removeFade()
{
  int inputVal = 0;
  while (true)
  {
    clearFullScreen();
    printTopBorder();
    printFormLine("MODIFY FADES: REMOVE FADE", "", 2);
    printBottomBorder();
    gotoLine(6);
    cout << "Possible fades: " << endl;
    cout << "    0. Keep current fade. " << endl;
    cout << "    1. Single grey" << endl;
    cout << "    2. Double grey" << endl;
    cout << "    3. Single roan" << endl;
    cout << "    4. Double roan" << endl;
    cout << endl;
    inputVal = getIntSelect();
    string chosenFade = "?";
    if (inputVal > 12 || inputVal < 0)
    {
      cout << "Sorry, that selection could not be understood. Please enter a value from the list provided." << endl;
      this->removeFade();
      return;
      break;
    }
    else
    {
      bitset<32> tempCode = this->getCoat().getFullSet();
      unsigned long int removalVal = 0;
      switch (inputVal)
      {
      case 1:
        removalVal += heterGrey;
        chosenFade = "\"single grey\"";
        break;
      case 2:
        removalVal += homoGrey;
        chosenFade = "\"double grey\"";
        break;
      case 3:
        removalVal += heterRoan;
        chosenFade = "\"single roan\"";
        break;
      case 4:
        removalVal += homoRoan;
        chosenFade = "\"double roan\"";
        break;
      case 0:
        break;
      default:
        break;
      }
      Coat tempCoat = this->getCoat();
      tempCoat -= removalVal;
      this->setCoat(tempCoat);
      gotoLine(6);
      clearRestofScreen();
      cout << "Fade " << chosenFade << " removed." << endl;
      cout << endl;

      cout << "Current faded coat is \"" << this->getCoat().getFadeCoatName() << "\"" << endl;
      cout << "Current overall coat is: " << this->getCoatName() << endl;
      cout << endl;
      while (true)
      {
        cout << endl;
        cout << "Remove another fade?" << endl;
        cout << "    1. Yes" << endl;
        cout << "    2. No" << endl;
        cout << endl;
        inputVal = getIntSelect();
        if (inputVal > 2 || inputVal < 1)
        {
          cout << "Sorry, that input could not be understood. Please choose an input from the provided selection." << endl;
          pressEnterToCont();
        }
        else
        {
          if (inputVal == 1)
          {
            removeFade();
            return;
          }
          else
          {
            return;
            break;
          }
        }
      }
      break;
    }
  }
}