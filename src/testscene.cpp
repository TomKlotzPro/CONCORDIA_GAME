/* File: testscene.cpp
 * Author: Klotz Tom
 */

#include "instance/testscene.hpp"
TestScene::TestScene(SceneManager *sceneManager)
    : Scene::Scene(sceneManager) {}
TestScene::~TestScene(){
    std::cout << "My destructor have been called. Yay!" << std::endl;
}
/*
 * Load Texture for background then texture for Character
 *
 */
void TestScene::start() {
  textureLoader.setTextureFromFile(
      this->charTexture, std::string("images/linkEdit.png"), 1200, 1040);
  character = Character(this->charTexture, 0, 0, 120, 130, 0, 1200, 520, 910, 20);
  character.setSpriteScale(0.4, 0.4);

  textureLoader.setTextureFromFile(
      this->bgTexture, std::string("images/mainBg.png"), 512, 256);
  bg = SpritedEntity(this->bgTexture, 0, 0, 512, 256);

  character.setSpritePosition(sf::Vector2f(0, 0));
  bg.setSpritePosition(sf::Vector2f(0, 0));
}

void TestScene::update() { character.moveCharacter(); }

void TestScene::handleEvent(sf::Event event, sf::RenderWindow &screen) {
  switch (event.type) {
  case sf::Event::KeyReleased:
    character.controlEntity(event.key.code, true);
    if(event.key.code == sf::Keyboard::Return){
        changeScene(new SecondScene(this->sceneManager));
    }
    break;
  case sf::Event::KeyPressed:
    character.controlEntity(event.key.code, false);
    break;
  }
}
//Draw it in the windows
void TestScene::drawEntities(sf::RenderWindow &window) {
  window.draw(bg.getSprite());
  window.draw(character.getSprite());
}
//Animate the character
void TestScene::doInternalTimedActions() {
  while (character.getAnimationTimeHandler().timeToUpdate())
    character.animate();
}

void TestScene::resetTimeHandlers(ClockHandler &clockHandler) {
    clockHandler.restartTimeHandler(&character.getAnimationTimeHandler());
}

void TestScene::onExit() {

}

void TestScene::resumeScene() {}
