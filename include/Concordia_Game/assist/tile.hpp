/* File: tile.hpp
 * Author: Klotz Tom
 */

 //Write commentary ! task
#ifndef TILE_HPP
#define TILE_HPP

// # External
#include <SFML/Graphics.hpp>

class Tile{
private:

  sf::Vector2f tilePosition;

  sf::FloatRect tileRect;

public:

  Tile(sf::Vector2f tilePosition, float tileWidth, float timeHeight);


  sf::Vector2f getPosition() const;


  float getPositionX() const;


  float getPositionY() const;


  sf::FloatRect getTileRect() const;
};

#endif
