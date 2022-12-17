#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @brief Represents a robot in a simulation. Inherits from
 * IEntity. Robots move via drone transport.
 */

class Robot : public IEntity {
 public:
  /// @brief Robots are created with a name
  /// @param obj JsonObject& that the Robot is built with
  Robot(JsonObject& obj);

  /// @brief Destructor
  ~Robot() override = default;

  /// @brief Returns the position of the Robot
  /// @return Vector3 representing the Robot's position
  Vector3 GetPosition() const { return position; }

  /**
    * @brief Gets the Robot's direction
    * @return Vector3 representing the Robot's direction
  */
  Vector3 GetDirection() const { return direction; }

  /**
    * @brief Gets the Robot's direction
    * @return Vector3 representing the Robot's destination
  */
  Vector3 GetDestination() const { return destination; }

  /**
    * @brief Gets the Robot's availability
    * @return bool representing the Robot's availability
  */
  bool GetAvailability() const { return available; }

  /**
    * @brief Gets the Robot's details
    * @return JsonObject representing the Robot's details
  */
  JsonObject GetDetails() const override;

  /// @brief Returns the speed of the Robot
  /// @return float representing the speed of the Robot
  float GetSpeed() const { return speed; }

  /**
    * @brief Returns the name of the strategy
    * @return Name of the strategy
  */
  std::string GetStrategyName() {return strategyName;}

  /**
    * @brief Set the availablity of the Robot
    * @param choice availablility - true or false
  */
  void SetAvailability(bool choice);

  /**
    * @brief Set position of the Robot
    * @param pos_ Vector3 representing new position
  */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
    * @brief Set direction of the Robot
    * @param pos_ Vector3 representing new direction
  */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
    * @brief Set destination of the Robot
    * @param pos_ Vector3 representing new destination
  */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
    * @brief Sets the strategy name of the Robot
    * @param strategyName_ Name of new strategy
  */
  void SetStrategyName(std::string strategyName_) { strategyName = strategyName_;}

  /**
    * @brief Rotate the Robot by a given angle
    * @param angle double angle by which to rotate
  */
  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
};

#endif  // ROBOT_H
