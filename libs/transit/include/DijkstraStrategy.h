#ifndef Dijkstra_STRATEGY_H_
#define Dijkstra_STRATEGY_H_

/**
 * include
 */
#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/**
 * @brief this class inherits from the IStrategy class
 * and is responsible for generating the Dijkstra route
 * that the drone and car will take.
 */
class DijkstraStrategy : public IStrategy {
 public:
  /**
   * @brief Constructor.
   * @param position Vector3 object representing the starting position
   * @param destination Vector3 object representing the destination
   * @param graph Igraph* object representing the graph
   */
  DijkstraStrategy(Vector3 position, Vector3 destination, const IGraph* graph);

  /**
   * @brief Destructor
   */
  ~DijkstraStrategy();

  /**
   * @brief Moves a given entity with a path generated by an astar strategy
   * @param entity IEntity* - entity to be moved
   * @param dt double delta time
   */
  void Move(IEntity* entity, double dt);

  /**
   * @brief Returns true if path is completed
   */
  bool IsCompleted();

 private:
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // Dijkstra_STRATEGY_H_