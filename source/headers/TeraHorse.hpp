/**
 * @file TeraHorse.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 16/Feb/2022
 *
 */

#include <iostream>
#include "./Horse.hpp"

using namespace std;

/**
 * @brief class for Earthen horses without supernatural abilities or features
 *
 */
class TeraHorse : public Horse
{
private:
  // Discipline discipline;
  // Appearance appearance;
  // Location birthPlace;
  bool broke;

public:
  /**
   * @brief Construct a new Tera Horse object
   *
   * @param name
   * @param nameLength
   * @param sex
   * @param broke
   * @param age
   */
  TeraHorse(char *name, int nameLength, char sex, bool broke = false, int age = -1) : Horse(name, nameLength, sex, age, "TER")
  {
    this->broke = broke;
  }

  /**
   * @brief Construct a new Tera Horse
   *
   * @param src
   */
  TeraHorse(TeraHorse &src) : Horse(src.name, src.nameLength, src.sex, src.age)
  {
    this->broke = src.broke;
  }

  /**
   * @brief Assignment operator overload for TeraHorse
   *
   * @param src
   * @return TeraHorse&
   */
  TeraHorse &operator=(TeraHorse &src)
  {
    if (this != &src)
    {
      if (this->name != NULL)
      {
        delete this->name;
      }
      this->name = new char[src.nameLength + 1]{'\0'};
      strcpy(this->name, src.name);
      this->nameLength = src.nameLength;
      this->broke = src.broke;
      this->age = src.age;
      this->sex = src.sex;
    }
  }

  /**
   * @brief Set as Broke
   *
   * @param broke
   */
  void setBroke(bool isBroke);

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool isBroke();

  /**
   * @brief Add TeraHorse information to the referenced ostream
   *
   * @param os
   */
  void teraHorseStream(std::ostream &os);

  /**
   * @brief Ostream insertion operator overload
   *
   * @param os
   * @param horse
   * @return std::ostream&
   */
  friend std::ostream &operator<<(std::ostream &os, TeraHorse &horse);
};