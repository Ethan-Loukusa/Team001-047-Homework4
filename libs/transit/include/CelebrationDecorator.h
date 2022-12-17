#ifndef CELEBRATION_DECORATOR_H_
#define CELEBRATION_DECORATOR_H_
#include <vector>

#include "IStrategy.h"

/**
 * @brief this class inherits from the IStrategy
 * class and is a decorator for entities to make them
 * move in a way where it seems like they are celebrating
 */
class CelebrationDecorator : public IStrategy {
 public:
  /**
   * @brief Constructor
   * @param strategy_ IStrategy* strategy to wrap
   */
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    spinTime = 0;
    jumpTime = 0;
  }

  /**
   * @brief Moves the given entity
   * @param entity Entity to move
   * @param dt double representing delta time
   */
  void Move(IEntity *entity, double dt);

  /**
   * @brief Returns true if strategy is completed
   * @return State of the strategy - completed (true) or not (false)
   */
  bool IsCompleted();

 protected:
  IStrategy *strategy;
  float spinTime;
  float jumpTime;
};

#endif
