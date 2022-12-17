#ifndef ATM_FACTORY_H_
#define ATM_FACTORY_H_

#include <vector>

#include "Atm.h"
#include "IEntity.h"
#include "IEntityFactory.h"

class AtmFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor
   */
  virtual ~AtmFactory() {}

  /**
   * @brief Returns an Atm pointer
   * @param entity Object with characteristics for Atm
   * @return Atm object with given characteristics
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
