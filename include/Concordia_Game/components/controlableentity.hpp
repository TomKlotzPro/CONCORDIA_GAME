/* File: controlableentity.hpp
 * Author: Klotz Tom
 */

#ifndef CONTROLABLEENTITY_HPP
#define CONTROLABLEENTITY_HPP


class ControlableEntity {
public:
  /*
   * Defines how the entity will respond to the given key when it is
   * either pressed or released.
   * The bool release is true if the key is released and false if
   * the key is pressed.
   */
  virtual void controlEntity(sf::Keyboard::Key key, bool release) = 0;
};

#endif
