#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

/**
 * @brief This class inherits from IEntityFactory.
 * It is responsible for producing Robots in a composite factory
 */

class RobotFactory : public IEntityFactory {
 public:
  /**
   * @brief Returns a Robot pointer
   * @param entity Object with characteristics for Robot
   * @return Robot object with given characteristics
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
