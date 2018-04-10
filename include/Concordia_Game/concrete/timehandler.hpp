/* File: timehandler.hpp
 * Author: Klotz Tom
 */
#ifndef TIMEHANDLER_HPP
#define TIMEHANDLER_HPP

#include <SFML/Graphics.hpp>

/*
 * Time handler handles the time for an entity. It can be a member of
 * the entity (recommended) or of the scene containing the entity.
 */

class TimeHandler {
protected:
  // The time since the last update.
  sf::Time lastUpdate;

  // The framerate, in seconds.
  sf::Time fps;

public:
  // Constructor.
  TimeHandler();

  // Constructor. Sets the framerate.
  TimeHandler(sf::Time fps);

  /*
   *  Restart the time handler with the elapsedTime. The elapsed time is
   * known by the ClockHandler, and it is recommended that the time handler
   * restarts any time handler
   * by clockhandler.restartTimeHandler(TimeHandler*)).
   */
  void restart(sf::Time elapsedTime);

  // Update the last update to the restart of the clock;
  void resetLastUpdate();

  void setFps(sf::Time fps);
  bool timeToUpdate();
};

#endif
