/* File: textureloader.hpp
 * Author: Klotz Tom
 */

#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

// # External
#include <SFML/Graphics.hpp>
#include <string>

#include "external/collision.h"

// Texture loader is a tool to ease the loading of textures.

class TextureLoader {
private:
  // The texture.
  sf::Texture texture;

  // Load the given texture by the path to its corresponding image.
  void loadTexture(sf::Texture &texture, std::string pathToImage);

  // Create the given texture with the given width and height.
  void createTexture(sf::Texture &texture, int w, int h);

public:
  // Constructor.
  TextureLoader();

  /*
   * Set the given texture with the image from the given path, with
   * the given width and height, also defining if the texture is repeated
   * or if has bitmask.
   */
  void setTextureFromFile(sf::Texture &textureToBeLoaded,
                          std::string pathToImage, int w, int h,
                          bool isRepeated = false, bool hasBitmask = false);
};

#endif
