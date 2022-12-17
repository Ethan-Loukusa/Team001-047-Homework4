#ifndef CAR_FACTORY_H_
#define CAR_FACTORY_H_

#include <vector>

#include "Car.h"
#include "IEntity.h"
#include "IEntityFactory.h"

/**
 * @brief This class inherits from IEntityFactory.
 * It is responsible for producing cars in a composite factory
 */

class CarFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor
   */
  virtual ~CarFactory() {}

  /**
   * @brief Returns a Car pointer
   * @param entity Object with characteristics for car
   * @return Car object with given characteristics
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
