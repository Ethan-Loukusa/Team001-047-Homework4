#define _USE_MATH_DEFINES
#include "Atm.h"

#include <cmath>
#include <limits>

#include "BeelineStrategy.h"
#include "JumpDecorator.h"
#include "SpinDecorator.h"

Atm::Atm(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};
}

Atm::~Atm() {
  // Delete dynamically allocated variables
}
