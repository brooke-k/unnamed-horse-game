/**
 * File: Equine.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com)
 * Date: 27/Jan/2022
 *
 */

#include <cstring>
#include <ostream>
#include "Health.hpp"

#define VARIANT_SIZE 4

/**
 * @brief Class for Equines of all kinds, provides basic functionality for horses and inherits from Health, Equipment(not yet implemented), and Lineage(not yet implemented)
 *
 */

class Equine : public Health
{

protected:
  char variant;
  std::string name;
  int age;  // Value < 0 signifies an unknown age
  char sex; // To be uppercase only
  // NOT IMPLEMENTED YET
  // Lineage lineage;

public:
  /**
   * @brief ostream insertion operator overload
   *
   * @param os
   * @param horse
   * @return std::ostream&
   */
  friend std::ostream &operator<<(std::ostream &os, Equine &horse);
  /**
   * @brief Get the Name
   *
   * @return char*
   */
  std::string getName() const;
  /**
   * @brief Get the Age
   *
   * @return int
   */
  int getAge();
  /**
   * @brief Get the Sex
   *
   * @return char
   */
  char getSex();
  /**
   * @brief Set the Name
   *
   * @param name
   * @param length
   */
  void setName(std::string name);
  /**
   * @brief Set the Age
   *
   * @param age
   */
  void setAge(int age);
  /**
   * @brief Set the Sex
   *
   * @param sex
   */
  void setSex(char sex);

  void setVariant(char variant);
  char getVariant() const;

  /**
   * @brief Construct a new Equine
   *
   * @param name
   * @param length
   * @param sex
   * @param age
   * @param variant
   */
  Equine(std::string name, char sex = 'X', int age = -1, char variant = 'X');
  /**
   * @brief Add Equine object information to referenced ostream
   *
   * @param os
   */
  void horseStream(std::ostream &os);

  /**
   * @brief Destroy the Equine
   *
   */
  virtual ~Equine();
  /**
   * @brief Assignment operator overload for the Equine
   *
   * @param src
   * @return Equine&
   */
  Equine &operator=(Equine &src);
  /**
   * @brief Construct a new Equine
   *
   * @param src
   */
  Equine(Equine &src);
};