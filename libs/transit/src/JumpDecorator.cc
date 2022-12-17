#include "JumpDecorator.h"

bool JumpDecorator::IsCompleted() { return jumpTime >= 1.5; }

void JumpDecorator::Move(IEntity* entity, double dt) {
  if (strategy->IsCompleted() && !IsCompleted()) {
    jumpTime = jumpTime + dt;
    entity->Rotate(dt * 10);
  } else {
    strategy->Move(entity, dt);
  }
}
