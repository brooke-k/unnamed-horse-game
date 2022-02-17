/**
 * @file Health.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 16/Feb/2022
 *
 */

#include <iostream>

/**
 * @brief class Health is a concrete base class intended to be used to gauge the health of all equine types.
 *
 */
class Health
{
private:
  float handsHeight;
  float weightKg;
  int fitnessRating;
  int happinessRating;
  int hungerRating;
  int thirstRating;
  int groomingRating;
  int energyRating;
  int boredomRating;
  bool gestating;

protected:
  void addHealthStream(std::ostream &os);

public:
  /**
   * @brief Construct a new Health object
   *
   */
  Health()
  {
    handsHeight = -1;
    weightKg = -1;
    fitnessRating = 1;
    happinessRating = 1;
    hungerRating = 1;
    thirstRating = 1;
    groomingRating = 1;
    energyRating = 1;
    boredomRating = 1;
    gestating = false;
  }

  /**
   * @brief Construct a new Health object
   *
   * @param handsHeight Float equine height in hands
   * @param weightKg Float equine weight in kilograms
   * @param fitnessRating Integer equine fitness on a scale of 1 to 10, with 10 being the most satisfactory
   * @param happinessRating Integer equine happiness on a scale of 1 to 10, with 10 being the most satisfactory
   * @param hungerRating Integer equine hunger on a scale of 1 to 10, with 10 being the most satisfactory
   * @param thirstRating Integer equine thirst on a scale of 1 to 10, with 10 being the most satisfactory
   * @param groomingRating Integer equine grooming quality on a scale of 1 to 10, with 10 being the most satisfactory
   * @param groomingRating Integer equine grooming quality on a scale of 1 to 10, with 10 being the most satisfactory
   * @param energyRating Integer equine sleep rating on a scale of 1 to 10
   * @param groomingRating Integer equine grooming quality on a scale of 1 to 10, with 10 being the most satisfactory
   * @param boredomRating Integer equine boredom rating on a scale of 1 to 10
   * @param gestating If the equine is gestating (pregnant). Boolean value.
   */
  Health(float handsHeight, float weightKg, int fitnessRating, int happinessRating, int hungerRating, int thirstRating, int groomingRating, int energyRating, int boredomRating, bool gestating)
  {
    this->handsHeight = handsHeight;
    this->weightKg = weightKg;
    this->happinessRating = happinessRating;
    this->hungerRating = hungerRating;
    this->thirstRating = thirstRating;
    this->groomingRating = groomingRating;
    this->energyRating = energyRating;
    this->boredomRating = boredomRating;
    this->gestating = gestating;
  }

  Health &operator=(Health &src)
  {
    if (this != &src)
    {
      this->handsHeight = src.handsHeight;
      this->weightKg = src.weightKg;
      this->happinessRating = src.happinessRating;
      this->hungerRating = src.hungerRating;
      this->thirstRating = src.thirstRating;
      this->groomingRating = src.groomingRating;
      this->energyRating = src.energyRating;
      this->boredomRating = src.boredomRating;
      this->gestating = src.gestating;
    }
    return *this;
  }

  Health(Health &src)
  {
    this->handsHeight = src.handsHeight;
    this->weightKg = src.weightKg;
    this->happinessRating = src.happinessRating;
    this->hungerRating = src.hungerRating;
    this->thirstRating = src.thirstRating;
    this->groomingRating = src.groomingRating;
    this->energyRating = src.energyRating;
    this->boredomRating = src.boredomRating;
    this->gestating = src.gestating;
  }

  /**
   * @brief Get the Height object
   *
   * @return float
   */
  float getHeight()
  {
    return handsHeight;
  }

  /**
   * @brief Get the Weight object
   *
   * @return float
   */
  float getWeight()
  {
    return weightKg;
  }
  /**
   * @brief Get the Fitness rating
   *
   * @return int
   */
  int getFitness()
  {
    return fitnessRating;
  }
  /**
   * @brief Get the Happiness rating
   *
   * @return int
   */
  int getHappiness()
  {
    return happinessRating;
  }
  /**
   * @brief Get the Hunger rating
   *
   * @return int
   */
  int getHunger()
  {
    return hungerRating;
  }
  /**
   * @brief Get the Thirst rating
   *
   * @return int
   */
  int getThirst()
  {
    return thirstRating;
  }
  /**
   * @brief Get the Grooming rating
   *
   * @return int
   */
  int getGrooming()
  {
    return groomingRating;
  }
  /**
   * @brief Get the Sleep rating
   *
   * @return int
   */
  int getSleep()
  {
    return energyRating;
  }
  /**
   * @brief Get the Boredom rating
   *
   * @return int
   */
  int getBoredom()
  {
    return boredomRating;
  }
  /**
   * @brief Get boolean of whether equine is gestating.
   *
   * @return true
   * @return false
   */
  bool isGestating()
  {
    return gestating;
  }

  /**
   * @brief Set the Height in hands
   *
   * @param handsHeight
   */
  void setHeight(float handsHeight)
  {
    this->handsHeight = handsHeight;
  }

  /**
   * @brief Set the Weight in kg
   *
   * @param weightKg
   */
  void setWeight(float weightKg)
  {
    this->weightKg = weightKg;
  }
  /**
   * @brief Set the Fitness rating
   *
   * @param rating
   */
  void setFitness(int rating)
  {
    fitnessRating = rating;
  }
  /**
   * @brief Set the Happiness rating
   *
   * @param rating
   */
  void setHappiness(int rating)
  {
    happinessRating = rating;
  }
  /**
   * @brief Set the Hunger rating
   *
   * @param rating
   */
  void setHunger(int rating)
  {
    hungerRating = rating;
  }
  /**
   * @brief Set the Thirst rating
   *
   * @param rating
   */
  void setThirst(int rating)
  {
    thirstRating = rating;
  }
  /**
   * @brief Set the Sleep rating
   *
   * @param rating
   */
  void setSleep(int rating)
  {
    energyRating = rating;
  }
  /**
   * @brief Set the Boredom rating
   *
   * @param rating
   */
  void setBoredom(int rating)
  {
    boredomRating = rating;
  }
  /**
   * @brief Set the gestating status as a bool
   *
   * @param isGestating
   */
  void setGestating(bool isGestating)
  {
    gestating = isGestating;
  }

  friend std::ostream &operator>>(std::ostream &os, Health &h);
};
