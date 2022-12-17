#ifndef PERSON_H
#define PERSON_H

#include <vector>

#include "Atm.h"
#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @brief Represents a person in the simulation. Inherits from
 * IEntity. People move by walking or waiting for a car
 */

class Person : public IEntity {
 public:
  /// @brief Persons are created with a name
  /// @param obj JsonObject& that the Person is built with
  Person(JsonObject& obj);

  /// @brief Destructor
  ~Person() override = default;

  /// @brief Returns the position of the Person
  /// @return Vector3 representing the Person's position
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the Person's direction
   * @return Vector3 representing the Person's direction
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the Person's direction
   * @return Vector3 representing the Person's destination
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the Person's availability
   * @return bool representing the Person's availability
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief Gets the Person's details
   * @return JsonObject representing the Person's details
   */
  JsonObject GetDetails() const override;

  /// @brief Returns the speed of the Person
  /// @return float representing the speed of the Person
  float GetSpeed() const { return speed; }

  /**
   * @brief Returns the name of the strategy
   * @return Name of the strategy
   */
  std::string GetStrategyName() { return strategyName; }

  /**
   * @brief Set the availablity of the Person
   * @param choice availablility - true or false
   */
  void SetAvailability(bool choice);

  /**
   * @brief Set position of the Person
   * @param pos_ Vector3 representing new position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Set direction of the Person
   * @param pos_ Vector3 representing new direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Set destination of the Person
   * @param pos_ Vector3 representing new destination
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Sets the strategy name of the Person
   * @param strategyName_ Name of new strategy
   */
  void SetStrategyName(std::string strategyName_) {
    strategyName = strategyName_;
  }

  /**
   * @brief Rotate the Person by a given angle
   * @param angle double angle by which to rotate
   */
  void Rotate(double angle);

  /**
   * @brief Returns true if person is ready for pickup
   * @return Ready for pickup (true) or not (false)
   */
  bool ReadyForPickup();

  /**
   * @brief Updates the position of the Person. Moves
   * to nearest Atm, or if already at Atm does nothing.
   * @param dt Delta time
   * @param scheduler Schedule of entities
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Sets Atm.nearestAtm to the nearest atm
   */
  void GetNearestAtm();

  /**
   * @brief Sets a Person.atms to the given set of atms
   * @param atms Vector of atm objects
   */
  void SetAtms(std::vector<IEntity*> atms) {
    this->atms = atms;
    std::cout << "PERSON ATMS SET. NUM ATMS: " << atms.size() << std::endl;
  }

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
  bool hasMoney = false;
  IEntity* nearestAtm = NULL;
  std::vector<IEntity*> atms;
  IStrategy* toAtmStrategy;
};

#endif  // Person_H
