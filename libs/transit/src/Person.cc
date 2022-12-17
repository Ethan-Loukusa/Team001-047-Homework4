#include "Person.h"

#include "BeelineStrategy.h"
#include "IStrategy.h"

Person::Person(JsonObject &obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];
  available = true;
}

JsonObject Person::GetDetails() const { return details; }

void Person::SetAvailability(bool choice) { available = choice; }

bool Person::ReadyForPickup() { return hasMoney; }

void Person::Rotate(double angle) {
  direction.x = direction.x * std::cos(angle) - direction.z * std::sin(angle);
  direction.z = direction.x * std::sin(angle) + direction.z * std::cos(angle);
}

void Person::GetNearestAtm() {
  float minDis = std::numeric_limits<float>::max();
  for (auto atm : atms) {
    float disToEntity = this->position.Distance(atm->GetPosition());
    if (disToEntity <= minDis) {
      minDis = disToEntity;
      nearestAtm = atm;
    }
  }

  if (nearestAtm) {
    std::cout << "NearestAtm set. Commencing with strategy \n";
    toAtmStrategy = new BeelineStrategy(position, nearestAtm->GetPosition());
  } else {
    std::cout << "Error: NearestAtm not set. \n";
  }
}

void Person::Update(double dt, std::vector<IEntity *> scheduler) {
  if (hasMoney) {
    // do nothing
  } else {
    if (nearestAtm) {
      toAtmStrategy->Move(this, dt);
      if (toAtmStrategy->IsCompleted()) {
        hasMoney = true;
        delete toAtmStrategy;
        toAtmStrategy = NULL;
      }
    } else {
      GetNearestAtm();
    }
  }
}
