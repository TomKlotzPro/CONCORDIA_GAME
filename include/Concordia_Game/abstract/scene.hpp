/* File: scene.hpp
 * Author: Klotz Tom
 */

//Write commentary ! task
#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/Graphics.hpp>

#include "Concordia_Game/concrete/clockhandler.hpp"
#include "Concordia_Game/concrete/scenemanager.hpp"
#include "Concordia_Game/concrete/textureloader.hpp"

class Scene {
protected:

  SceneManager *sceneManager;

  TextureLoader textureLoader;

public:
  Scene(SceneManager *sceneManager);

  Scene();

  virtual ~Scene();

  virtual void start() = 0;

  virtual void update() = 0;

  virtual void handleEvent(sf::Event event, sf::RenderWindow &screen) = 0;

  virtual void drawEntities(sf::RenderWindow &window) = 0;

  virtual void doInternalTimedActions() = 0;

  virtual void resetTimeHandlers(ClockHandler &clockHandler) = 0;

  virtual void onExit() = 0;

  virtual void resumeScene() = 0;

  void changeScene(Scene *nextScene);

  void setSceneManager(SceneManager *sceneManager);

  SceneManager *getSceneManager();
};

#endif
