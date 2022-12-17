#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;


/// @brief Abstract class for an entity within the simulation. Moving objects within
/// the simulation inherit from this class
class IEntity {
 public:
 /// @brief Constructor
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }
  /// @brief Destructor
  virtual ~IEntity() {}

  /// @brief returns id of entity
  /// @return int id
  virtual int GetId() const { return id; }

  /// @brief Returns the position of the entity
  /// @return Vector3 representing the entity's position
  virtual Vector3 GetPosition() const = 0;

  /**
    * @brief Gets the entity's direction
    * @return Vector3 representing the entity's direction
  */
  virtual Vector3 GetDirection() const = 0;

  /**
    * @brief Gets the entity's direction
    * @return Float representing the entity's speed
  */
  virtual Vector3 GetDestination() const = 0;

  /**
    * @brief Gets the entity's details
    * @return JsonObject representing the entity's details
  */
  virtual JsonObject GetDetails() const = 0;

  /// @brief Returns the speed of the entity
  /// @return float representing the speed of the entity
  virtual float GetSpeed() const = 0;

  /**
  * @brief Gets the entity's availability
  * @return bool representing the entity's availability
  */
  virtual bool GetAvailability() const = 0;

  /**
    * @brief Returns the name of the strategy
    * @return Name of the strategy
  */
  virtual std::string GetStrategyName(){}

  /**
    * @brief Set the availablity of the entity
    * @param choice availablility - true or false
  */
  virtual void SetAvailability(bool choice) {}

  /**
    * @brief Updates the entity's position
    * @param dt double representing delta time
    * @param scheduler Vector with entities on the scheduler
  */
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}
  
  /**
    * @brief Set the entity's graph
    * @param graph IGraph* new graph
  */
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  
  /**
    * @brief Set position of the entity
    * @param pos_ Vector3 representing new position
  */
  virtual void SetPosition(Vector3 pos_) {}

  /**
    * @brief Set direction of the entity
    * @param pos_ Vector3 representing new direction
  */
  virtual void SetDirection(Vector3 dir_) {}

  /**
    * @brief Set destination of the entity
    * @param pos_ Vector3 representing new destination
  */
  virtual void SetDestination(Vector3 des_) {}


  /**
    * @brief Sets the strategy name of the entity
    * @param strategyName_ Name of new strategy
  */
  virtual void SetStrategyName(std::string strategyName_){}
  
  /**
    * @brief Rotate the entity by a given angle
    * @param angle double angle by which to rotate
  */

  virtual void Rotate(double angle) {}

  /**
    * @brief Jump a given height
    * @param height double height which to jump
  */
  virtual void Jump(double height) {}

  /**
    * @brief Returns true if entity is ready for pickup
    * @return Ready for pickup (true) or not (false)
    */
  virtual bool ReadyForPickup() { return false; }

  /**
    * @brief Sets an entity's atms to the given set of atms
    * @param atms Vector of atm objects
    */
  virtual void SetAtms( std::vector<IEntity*> atms ) {}

 protected:
  int id;
  const IGraph* graph;
};

#endif
