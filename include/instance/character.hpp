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
  TimeHandler animationTimeHandler;
  FacingPosition lastFacingPosition;

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
