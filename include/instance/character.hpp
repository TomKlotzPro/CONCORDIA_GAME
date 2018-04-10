/* File: character.hpp
 * Author: Klotz Tom
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>

#include "Concordia_Game/components/animatedentity.hpp"
#include "Concordia_Game/components/controlableentity.hpp"
#include "Concordia_Game/components/spritedentity.hpp"
#include "Concordia_Game/concrete/timehandler.hpp"
#include "instance/facingposition.hpp"
/*
 * Herited Object from AnimatedEntity(herited from SpritedEntity) and ControlableEntity
 *
 */
class Character : public AnimatedEntity, public ControlableEntity {
private:
  sf::Vector2f movement;
  sf::Vector2f control;
  TimeHandler animationTimeHandler;
  FacingPosition lastFacingPosition;

  float x ;
  float y ;
  //NEED TO ADD IT IN THE CONSCTUCTOR
  float static const limiteUp = 0;
  float static const limiteLeft = 0;
  float static const limiteDown = 200;
  float static const limiteRight = 455;

  bool facingUp;
  bool facingDown;
  bool facingLeft;
  bool facingRight;

public:
  //Constructor
  Character(sf::Texture const &texture, int spriteX, int spriteY, int spriteW,
            int spriteH, int animationInitialXPosition, int animationFinalXPosition, int animationInitialYPosition,
            int animationFinalYPosition, int animationFramesPerSeconds);
  Character();
  //
  void controlEntity(sf::Keyboard::Key key, bool release);
  //
  void moveCharacter();
  void animate();
};

#endif
