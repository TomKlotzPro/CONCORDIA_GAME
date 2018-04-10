/* File: game.cpp
 * Author: Klotz Tom
 */

#include "Concordia_Game/concrete/game.hpp"

Game::Game(int gameWidth, int gameHeight, std::string gameTitle, float frameratePerSecond)
    : gameScreen(sf::VideoMode(gameWidth, gameHeight), gameTitle),
      gameFrequency(sf::seconds(1.f / frameratePerSecond)) {
  this->gameWidth = gameWidth;
  this->gameHeight = gameHeight;
}

void Game::gameStart(Scene *firstScene, bool vsync) {
  gameScreen.setVerticalSyncEnabled(vsync);
  firstScene->setSceneManager(this->getSceneManager());
  sceneManager.setScene(firstScene);
  /*
   * While the window is open we need to handle each event
   * clear, draw and display entity (only character for the moment)
   */
  while (this->gameScreen.isOpen()) {
    handleTimeActions();
    clearNDraw();
    // synchronised clock of the game and clock of the sceneManager
    this->clockHandler.restartClock();
    this->clockHandler.restartTimeHandler(&gameFrequency);
    sceneManager.resetTimeHandlers(clockHandler);
  }
}

void Game::handleTimeActions() {
  while (gameFrequency.timeToUpdate()) {
    // handle event
    processEvents();
    //update the scene current scene
    sceneManager.update();
    // update internal action (animation)
    sceneManager.doInternalTimedActions();
  }
}

void Game::processEvents() {
  sf::Event event;
  // Controle all event on the current scene
  while (this->gameScreen.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      gameScreen.close();
    }
    //handle event for the current scene
    sceneManager.handleEvent(event, gameScreen);
  }
}

void Game::clearNDraw() {
  this->gameScreen.clear();
  sceneManager.drawEntities(gameScreen);
  this->gameScreen.display();
}

int Game::getGameWidth() const {
  return this->gameWidth;
}
int Game::getGameHeight() const {
  return this->gameHeight;
}

SceneManager *Game::getSceneManager() {
  return &this->sceneManager;
}
