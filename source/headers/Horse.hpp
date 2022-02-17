/**
 * File: Horse.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com)
 * Date: 27/Jan/2022
 *
 */

#include <cstring>
#include <ostream>
#include "Health.hpp"

#define VARIANT_SIZE 4

/**
 * @brief Class for Horses of all kinds, provides basic functionality for horses and inherits from Health, Equipment(not yet implemented), and Lineage(not yet implemented)
 *
 */
class Horse : public Health
{
protected:
  char *variant;
  char *name;
  int age;  // Value < 0 signifies an unknown age
  char sex; // To be uppercase only
  int nameLength;
  // NOT IMPLEMENTED YET
  // HorseVariant variant;
  // Lineage lineage;

public:
  /**
   * @brief ostream insertion operator overload
   *
   * @param os
   * @param horse
   * @return std::ostream&
   */
  friend std::ostream &operator<<(std::ostream &os, Horse &horse);
  /**
   * @brief Get the Name
   *
   * @return char*
   */
  char *getName() const;
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
  void setName(char *name, int length);
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

  virtual void setVariant(const char *);
  virtual void setVariant(char *);
  virtual char *getVariant() const;

  /**
   * @brief Construct a new Horse
   *
   * @param name
   * @param length
   * @param sex
   * @param age
   * @param variant
   */
  Horse(char *name, int length, char sex, int age = -1, const char *variant = "N/A");
  /**
   * @brief Add Horse object information to referenced ostream
   *
   * @param os
   */
  void addHorseStream(std::ostream &os);

  /**
   * @brief Destroy the Horse
   *
   */
  virtual ~Horse();
  /**
   * @brief Assignment operator overload for the Horse
   *
   * @param src
   * @return Horse&
   */
  Horse &operator=(Horse &src);
  /**
   * @brief Construct a new Horse
   *
   * @param src
   */
  Horse(Horse &src);
};