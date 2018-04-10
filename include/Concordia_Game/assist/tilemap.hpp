/* File: tilemap.hpp
 * Author: Klotz Tom
 */

 //Write commentary ! task
#ifndef TILEMAP_HPP
#define TILEMAP_HPP

// # External
#include <SFML/Graphics.hpp>

#include "Concordia_Game/assist/tilegrid.hpp"

class TileMap : public sf::Drawable, public sf::Transformable {
private:

   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

   sf::VertexArray m_vertices;

   sf::Texture m_tileset;

   unsigned int levelWidth;

   unsigned int levelHeight;

   TileGrid tileGrid;

public:

  TileMap();

  bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

  sf::Vector2u getLevelSize() const;
};

#endif
