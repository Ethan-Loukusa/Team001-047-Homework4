#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

#include <vector>

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"

/**
 * @brief This class inherits from IEntityFactory.
 * It is responsible for producing drones in a composite factory
 */

class DroneFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor
   */
  virtual ~DroneFactory() {}

  /**
   * @brief Returns a Drone pointer
   * @param entity Object with characteristics for drone
   * @return Drone object with given characteristics
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
