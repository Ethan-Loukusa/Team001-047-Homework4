#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

#include "IEntityFactory.h"

/**
 * @brief this class inherits from the IEntityFactory
 * class and creates many different types of IEntities,
 * whose own factories are stored in a vector (componentFactories)
 */

class CompositeFactory : public IEntityFactory {
 public:
  IEntity* CreateEntity(JsonObject& entity);

  void AddFactory(IEntityFactory* factoryEntity);

  virtual ~CompositeFactory();

 private:
  std::vector<IEntityFactory*> componentFactories;
};

#endif
