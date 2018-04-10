/* File: mousecontrol.hpp
 * Author: Klotz Tom
 */

#ifndef MOUSECONTROL_HPP
#define MOUSECONTROL_HPP

#include <SFML/Graphics.hpp>

#include "Concordia_Game/components/spritedentity.hpp"
//For the menu , prepared field

class MouseControl {
public:
  /*
   * Defines the control for an entity by using the mouse.
   * It needs the event, the sprited entity to be manipulated
   * and the position of the mouse.
   */
  virtual void controlEntityByMouse(sf::Event event,
                                    SpritedEntity &spritedEntity,
                                    sf::Vector2f mousePos) = 0;
};

#endif
