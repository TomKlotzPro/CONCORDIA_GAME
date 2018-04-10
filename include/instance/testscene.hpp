/* File: testscene.hpp
 * Author: Klotz Tom
 */
#ifndef TESTSCENE_HPP
#define TESTSCENE_HPP

#include <iostream>

#include "Concordia_Game/abstract/scene.hpp"
#include "Concordia_Game/components/spritedentity.hpp"
#include "instance/character.hpp"
#include "instance/secondscene.hpp"
/*
 * Object Herited from Scene class
 * Use same methods
 */
class TestScene : public Scene {
private:
  //Background and character texture
  sf::Texture charTexture;
  sf::Texture bgTexture;
  //sf::Texture badGuyTexture;

  //BadGuy badGuy;
  Character character;
  SpritedEntity bg;

public:
  TestScene(SceneManager *sceneManager);
  ~TestScene();

  void start();
  void update();

  void handleEvent(sf::Event event, sf::RenderWindow &screen);
  void drawEntities(sf::RenderWindow &window);

  void doInternalTimedActions();
  void resetTimeHandlers(ClockHandler &clockHandler);

  void onExit();
  void resumeScene();
};

#endif
