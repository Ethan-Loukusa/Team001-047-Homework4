#ifndef I_ENTITY_FACTORY_H_
#define I_ENTITY_FACTORY_H_

#include "Car.h"
#include "IEntity.h"
#include "IEntityFactory.h"
#include "util/json.h"

/**
 * @brief Abstract class for all factories in factory pattern
 * in simulation
 */

class IEntityFactory {
 public:
  /**
   * @brief Destructor
   */
  virtual ~IEntityFactory() {}

  /**
   * @brief Returns an entity pointer
   * @param entity Object with characteristics for the entity
   * @return Entity pointer with given characteristics
   */
  virtual IEntity* CreateEntity(JsonObject& entity) = 0;
};

#endif
