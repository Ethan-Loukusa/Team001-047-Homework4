#ifndef SIMULATION_MODEL_H_
#define SIMULATION_MODEL_H_

#include "CompositeFactory.h"
#include "IController.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/// @brief Simulation Model handling the transit simulation.  The model can
/// communicate with the controller.
class SimulationModel {
 public:
  /**
   * @brief Constructor
   * @param controller IController& to use as the controller
   */
  SimulationModel(IController& controller);

  /**
   * @brief Set the graph
   * @param graph IGraph* new graph
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief Create a new entity
   * @param entity Details of the new entity
   */
  void CreateEntity(JsonObject& entity);

  /**
   * @brief Schedules a trip for an entity
   * @param details Details of the entity for which to schedule the trip
   */
  void ScheduleTrip(JsonObject& details);

  /// @brief Updates the simulation
  /// @param dt Delta time
  void Update(double dt);

  /// @brief Adds a new entity type
  /// @param factory Factory of new entity type
  void AddFactory(IEntityFactory* factory);

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  const IGraph* graph;
  CompositeFactory* compFactory;
  std::vector<IEntity*> atms;
};

#endif
