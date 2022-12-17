#ifndef PERSON_FACTORY_H_
#define PERSON_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Person.h"

#include <vector>

/**
 * @brief This class inherits from IEntityFactory.
 * It is responsible for producing Persons in a composite factory
 */

class PersonFactory : public IEntityFactory {
  public:
    /**
    * @brief Returns a Person pointer
    * @param entity Object with characteristics for pointer
    * @return Person pointer with given characteristics
    */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif
