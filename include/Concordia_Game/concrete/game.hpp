/* File: main.hpp
 * Author: Klotz Tom
 */

#ifndef GAME_HPP
#define GAME_HPP

// # External
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

// # Internal
#include "Concordia_Game/concrete/clockhandler.hpp"
#include "Concordia_Game/concrete/timehandler.hpp"
#include "Concordia_Game/concrete/scenemanager.hpp"
#include "Concordia_Game/abstract/scene.hpp"

// The entity that maintains the game cycle. It is responsable for
// delegating actions for its scene managers, which repasses it
// to its current scene. It also keeps the game to the framerate.

class Game {

private:
  // The frame of the application.
  sf::RenderWindow gameScreen;

  // The width and the height of the frame
  int gameWidth;
  int gameHeight;

  // The clock of the game.
  ClockHandler clockHandler;

  // The timehandler to define the framerate of the game.
  TimeHandler gameFrequency;

  // The scene manager to delegate actions for the scene.
  SceneManager sceneManager;

public:
  /*
   * Constructor / Requires the width and height of the game window and its
   * title too.
   */

  Game(int gameWidth, int gameHeight, std::string gameTitle, float frameratePerSecond = 60.f);

  /*
   * Start the game. This begins the game cycle, verifying if the
   * window is still open to do the operations. It requires the first
   * scene to be played and the bool to use vsync.
   */

  void gameStart(Scene* firstScene, bool vsync = true);

  // This will handle the actions inside the framerate
  void handleTimeActions();

  // This will process the events.
  void processEvents();

  /*
   * This will clear the screen, draw and display the entities of
   * the current scene. It calls for the drawEntities method from the
   * scene.
   */
  void clearNDraw();

  // Getters for the game width and height.
  int getGameWidth() const;
  int getGameHeight() const;

  // Getter for the scene manager.
  SceneManager* getSceneManager();
};

#endif
