#include "PersonFactory.h"

IEntity* PersonFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("person") == 0) {
    std::cout << "Person Created" << std::endl;
    return new Person(entity);
  }
  return nullptr;
}
