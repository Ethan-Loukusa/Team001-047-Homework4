#ifndef ATM_H_
#define ATM_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a Atm in a physical system.
// People move either to the nearest ATM or
// via car if they have enough money
class Atm : public IEntity {
 public:
  /// @brief Constructor
  Atm(JsonObject& obj);
  /// @brief Destructor
  ~Atm();

  /// @brief Returns the position of the Atm
  /// @return Vector3 representing the Atm's position
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the Atm's direction
   * @return Vector3 representing the Atm's direction
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the Atm's direction
   * @return Vector3 representing the Atm's destination
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the Atm's details
   * @return JsonObject representing the Atm's details
   */
  JsonObject GetDetails() const { return details; }

  /// @brief Returns the speed of the Atm
  /// @return float representing the speed of the Atm
  float GetSpeed() const { return -1.0; }

  /**
   * @brief Gets the person's availability - not the same as readiness
   * @return bool representing the Atm's availability
   */
  bool GetAvailability() const { return false; }

  /**
   * @brief Set position of the Atm
   * @param pos_ Vector3 representing new position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Set direction of the car
   * @param pos_ Vector3 representing new direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Set destination of the car
   * @param pos_ Vector3 representing new destination
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Removing the copy constructor
   */
  Atm(const Atm& Atm) = delete;

  /**
   * @brief Removing the assignment operator
   */
  Atm& operator=(const Atm& Atm) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
};

#endif
