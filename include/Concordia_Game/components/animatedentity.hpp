/* File: animatedentity.hpp
 * Author: Klotz Tom
 */


 //Write commentary ! task not finished
#ifndef ANIMATEDENTITY_HPP
#define ANIMATEDENTITY_HPP

#include "Concordia_Game/components/spritedentity.hpp"
#include "Concordia_Game/concrete/timehandler.hpp"

/*
 * An animated entity can be used by entities that have
 * a sprite and it requires an animation. In this class,
 * the coder can use integers delimitors to define the position of
 * the animated frames of a texture, and animate it on its own
 * by implementing the abstract method animate
 */

class AnimatedEntity : public SpritedEntity {
private:
  /*
   * The X position of the first frame of the animated sprite
   * example : if the first frame is located in the left corner of the image,
   * this field would have to have the value of 0.
   */
  int animationInitialXPosition;

  /*
   * The X position of the last frame of the animated sprite.
   * example : if the last frame of the animation is located at the end
   * of the image, with the image being 512x256 and the sprite
   * size is 12x12px, this field would have to have the value of
   * 512 - 32, which is 500.
   */
  int animationFinalXPosition;

  /*
   * The Y position of the first frame of the animated sprite.
   * This field will be used to iterate through the rows
   * of the animation. By rows, it is this initial position
   * plus the height of the sprite.
   */
  int animationInitialYPosition;

  int animationFinalYPosition;

  TimeHandler animationTimeHandler;

  int animationLoopState;

public:

  AnimatedEntity(sf::Texture const &texture, int spriteX, int spriteY,
                 int spriteW, int spriteH, int animationInitialXPosition,
                 int animationFinalXPosition, int animationInitialYPosition, int animationFinalYPosition, float animationFramesPerSecond);

  /*
   * Empty constructor. This is important so the user of the
   * animated sprite can choose to initialize it later (but it's
   * important to not forget to do so..)(same as SpritedEntity !)
   */
  AnimatedEntity();

  // Getter for the X position of the first frame of the animated sprite
  int getAnimationInitialXPosition() const;

  // Getter for the X position of the last frame of the animated sprite
  int getAnimationFinalXPosition() const;

  // Getter for the Y position of the first frame of the animated sprite
  int getAnimationInitialYPosition() const;

  // Getter for the Y position of the last frame in the Y position
  int getAnimationFinalYPosition() const;

  // Getter for the time handler of the animation
  TimeHandler &getAnimationTimeHandler();

  /*
   * Applies the animation of the row. This means it will iterate through
   * the first frame until the last frame, and go back to the first frame
   * again in a loop
   */
  void applyAnimation(int row);

  /*
   * Defines what will trigger the animation and which/how the
   * animation will happen
   */
  virtual void animate() = 0;
};

#endif
