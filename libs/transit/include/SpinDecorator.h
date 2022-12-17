#ifndef SPIN_DECORATOR_H_
#define SPIN_DECORATOR_H_
#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

/**
 * @brief Wrapper for entities to make them celebrate. Inherits
 * from CelebrationDectorator interface
 */

class SpinDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief Constructor
   * @param strategy_ IStrategy* strategy to wrap
   */
  SpinDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}

  /**
   * @brief Returns true if strategy is completed
   * @return State of the strategy - completed (true) or not (false)
   */
  bool IsCompleted();

  /**
   * @brief Moves the given entity - with a spin
   * @param entity Entity to move
   * @param dt double representing delta time
   */
  void Move(IEntity* entity, double dt);
};

#endif
