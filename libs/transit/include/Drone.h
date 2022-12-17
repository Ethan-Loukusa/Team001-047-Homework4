#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief Represents a drone in a physical system.
    Drones move using euler integration based on a specified
    velocity and direction.
 */
class Drone : public IEntity {
 public:
  /// @brief Drones are created with a name
  /// @param obj JsonObject& that the Drone is built with
  Drone(JsonObject& obj);

  /// @brief Destructor
  ~Drone();

  /// @brief Returns the speed of the Drone
  /// @return float representing the speed of the Drone
  float GetSpeed() const { return speed; }

  /// @brief Returns the position of the Drone
  /// @return Vector3 representing the Drone's position
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the Drone's direction
   * @return Vector3 representing the Drone's direction
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the Drone's direction
   * @return Float representing the Drone's speed
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the Drone's details
   * @return JsonObject representing the Drone's details
   */
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Gets the Drone's availability
   * @return bool representing the Drone's availability
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief Gets the nearest entity from the scheduler
   * @param scheduler Vector with entities that are scheduled
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
   * @brief Updates the Drone's position
   * @param dt double representing delta time
   * @param scheduler Vector with entities on the scheduler
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Set position of the Drone
   * @param pos_ Vector3 representing new position
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Set direction of the Drone
   * @param pos_ Vector3 representing new direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Set destination of the Drone
   * @param pos_ Vector3 representing new destination
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Rotate the Drone by a given angle
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
  Drone(const Drone& drone) = delete;
  /**
   * @brief Removing the assignment operator
   */
  Drone& operator=(const Drone& drone) = delete;

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
