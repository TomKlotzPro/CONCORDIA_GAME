/* File: testscene.hpp
 * Author: Klotz Tom
 */
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

#include "Concordia_Game/abstract/scene.hpp"
#include "Concordia_Game/components/spritedentity.hpp"
#include "instance/testscene.hpp"
/*
 * Object Herited from Scene class
 * Use same methods
 */
class Menu : public Scene {
private:
  //Background and character texture

  sf::Texture bgTexture;


  SpritedEntity bg;

public:
  ~Menu();

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
