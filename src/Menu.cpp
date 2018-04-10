/* File: testscene.cpp
 * Author: Klotz Tom
 */

#include "instance/menu.hpp"

Menu::~Menu(){
    std::cout << "My destructor have been called. Yay!" << std::endl;
}
/*
 * Load Texture for background then texture for Character
 *
 */
void Menu::start() {
  textureLoader.setTextureFromFile(
      this->bgTexture, std::string("images/play.png"), 512, 256);
  bg = SpritedEntity(this->bgTexture, 0, 0, 512, 256);
}

void Menu::update() { }

void Menu::handleEvent(sf::Event event, sf::RenderWindow &screen) {
  switch (event.type) {
  /*case sf::Event::KeyReleased:
    switch (event.key.code) {
    case sf::Keyboard::Return:
      changeScene(new TestScene(this->sceneManager));
      break;
    }
    break;
  */
  case sf::Event::MouseButtonPressed:
   switch(event.mouseButton.button){
   case sf::Mouse::Left:
   /*
   std::cout << "the left button was pressed" << std::endl;
   std::cout << "mouse x: " << event.mouseButton.x << std::endl;
   std::cout << "mouse y: " << event.mouseButton.y << std::endl;
   */
    changeScene(new TestScene(this->sceneManager));
    break;
   }
  break;
  }
}
//Draw it in the windows
void Menu::drawEntities(sf::RenderWindow &window) {
  window.draw(bg.getSprite());
}
//Animate the character
void Menu::doInternalTimedActions() {}

void Menu::resetTimeHandlers(ClockHandler &clockHandler) {}

void Menu::onExit() {

}

void Menu::resumeScene() {}
