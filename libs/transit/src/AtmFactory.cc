#include "AtmFactory.h"

IEntity* AtmFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("atm") == 0) {
    std::cout << "Atm Created" << std::endl;
    return new Atm(entity);
  }
  return nullptr;
}
