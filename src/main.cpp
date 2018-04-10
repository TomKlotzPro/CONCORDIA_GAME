/* File: main.cpp
 * Author: Klotz Tom
 */
#include <string>
/*
 * Object Game Created
 * Use methods Game start with object "TestScene"(FirstsceneCreate)
 * For the menu we will create the Object "Menu" same as "TestScene" with different methodes
 * that's why "Test" herited from abstract Class call Scenez
 */
#include "Concordia_Game/concrete/game.hpp"
#include "instance/testscene.hpp"

int main() {
  /*
   * object game created with three variables (size of the window) width / height and the name of the frame
   * then the methods game start need an Scene object 
   */
  Game game(512, 256, std::string("Concordia_Game"));
  game.gameStart(new TestScene());
  return 0;
}
