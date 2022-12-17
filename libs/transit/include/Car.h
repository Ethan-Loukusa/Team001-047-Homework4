#ifndef CAR_H_
#define CAR_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief Represents a Car in a physical system.
 * Cars move using euler integration based on a specified
 * velocity and direction.
 */
class Car : public IEntity {
 public:
  /// @brief Cars are created with a name
  /// @param obj JsonObject& that the Car is built with
  Car(JsonObject& obj);

  /// @brief Destructor
  ~Car();

  /// @brief Returns the speed of the Car
  /// @return float representing the speed of the Car
  float GetSpeed() const { return speed; }

  /// @brief Returns the position of the Car
  /// @return Vector3 representing the car's position
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the car's direction
   * @return Vector3 representing the car's direction
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the car's direction
   * @return Vector3 representing the car's destination
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the car's details
   * @return JsonObject representing the car's details
   */
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Gets the car's availability
   * @return bool representing the car's availability
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief Gets the nearest entity from the scheduler
   * @param scheduler Vector with entities that are scheduled
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
   * @brief Updates the car's position
   * @param dt double representing delta time
   * @param scheduler Vector with entities on the scheduler
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Set position of the car
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
   * @brief Rotate the car by a given angle
   * @param angle double angle by which to rotate
   */
  void Rotate(double angle);

  /**
   * @brief Jump a given height
   * @param height double height which to jump
   */
  void Jump(double height);

  /**
   * @brief Removing the copy constructor
   */
  Car(const Car& Car) = delete;

  /**
   * @brief Removing the assignment operator
   */
  Car& operator=(const Car& Car) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  float jumpHeight = 0;
  bool goUp = true;  // jump helper
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
};

#endif
