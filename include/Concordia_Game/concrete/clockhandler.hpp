/* File: clockhandler.hpp
 * Author: Klotz Tom
 */

#ifndef CLOCKHANDLER_HPP
#define CLOCKHANDLER_HPP

#include "Concordia_Game/concrete/timehandler.hpp"

 /*
  * Handles the clock of the game. It serves to make the game only
  * have a single clock, which every entity can use to syncronize their
  * time handlers
  */

class ClockHandler {
private:
  // The SFML clock.
  sf::Clock clock;

  // The elapsed time of the clock.
  sf::Time elapsedTime;

public:
  // Constructor
  ClockHandler();

  // Restart the clock and register the elapsed time.
  void restartClock();

  // Restart the given time handler to the clock's elapsed time.
  void restartTimeHandler(TimeHandler *genericTimeHandler);
};

#endif
