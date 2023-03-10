#ifndef ASTAR_STRATEGY_H_
#define ASTAR_STRATEGY_H_

/**
 * include
 */
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief this class inherits from the IStrategy 
 * class and is responsible for generating the Astar route
 * that the Drone and Car will take.
 */
class AstarStrategy : public IStrategy {
public:

    /**
     * @brief Constructor.
     * @param position Vector3 object representing the starting position
     * @param destination Vector3 object representing the destination
     * @param graph Igraph* object representing the graph
     */
    AstarStrategy(Vector3 position, Vector3 destination, const IGraph* graph);

    /**
     * @brief Destructor
     */
    ~AstarStrategy();

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
}; //end class
#endif // ASTAR_STRATEGY_H_
