/* File: secondscene.cpp
 * Author: Klotz Tom
 */

#include "instance/secondscene.hpp"

SecondScene::SecondScene(SceneManager *sceneManager)
    : Scene::Scene(sceneManager) {}

SecondScene::SecondScene() : Scene::Scene() {}

void SecondScene::start() {
  /* TEST
   * shape = sf::CircleShape(100.f);
   * shape.setFillColor(sf::Color::Green);
   */
  textureLoader.setTextureFromFile(
      this->bgTexture, std::string("images/gameover.png"), 512, 256);
  bg = SpritedEntity(this->bgTexture, 0, 0, 512, 256);
}

void SecondScene::update() {}

void SecondScene::handleEvent(sf::Event event, sf::RenderWindow &screen) {
  switch (event.type) {
  case sf::Event::KeyReleased:
    switch (event.key.code) {
    case sf::Keyboard::Return:
      screen.close();
      break;
    }
    break;
  }
}

void SecondScene::drawEntities(sf::RenderWindow &window) { window.draw(bg.getSprite()); }

void SecondScene::doInternalTimedActions() {}
void SecondScene::resetTimeHandlers(ClockHandler &clockHandler) {}
void SecondScene::onExit() {}
void SecondScene::resumeScene() {}
