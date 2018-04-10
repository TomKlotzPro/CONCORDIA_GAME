/* File: scenemanager.hpp
 * Author: Klotz Tom
 */

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <cstring>

#include "Concordia_Game/concrete/clockhandler.hpp"

// Forward declaration of the scene.

class Scene;

/*
 * The scene manager will be responsible to delegate actions to
 * its current scene. So, if a object that has a Scene Manager wants the
 * scene to draw the entities, e.g., it will be needed to just call the
 * scene manager to do so, and the scene manager will delegate it to the
 * scene. If the scene is changed, the call to the scene manager will not
 * change.
 */

class SceneManager {
private:
	/*
	 * The current scene. This will be the scene to be used on the
	 * methods of this class
	 */
	Scene* scene;

	/*
	 * If we have time it will be useful to go back on the last scene
	 * it will be like a go back on the last scene we used (pointer)
	 */
	Scene* lastScene;

public:
	// Constructor.
	SceneManager();

	// Destructor.
	~SceneManager();

	/*
	 * Change the scene to a new scene. Since the scene has a
	 * pointer to the scene manager, the scene can change to another
	 * one inside itself by calling this method.
	 */
	void changeScene(Scene* nextScene);

	 /*
	  * Change the scene to a new scene and store the last scene,
	  * so it can be returned to the last one in the future
		*/
	void changeToRuntimeScene(Scene* nextScene);

	// Delete the last scene.
	void removeLastScene();

	// The following methods will repass the call for the current scene.
	void start();
	void update();
	void handleEvent(sf::Event event, sf::RenderWindow& screen);
	void drawEntities(sf::RenderWindow& window);
	void doInternalTimedActions();
	void resetTimeHandlers(ClockHandler& clockHandler);

	/*
	 * Setter for the scene !!! CAUTION: If you are changing from inside !!!
	 * a scene, it is recommended that you use changeScene, from
	 * Scene, instead. Calling this method does not free the
	 * pointer of the last scene, making it garbage in the execution.
	 * (in Java there is no problem with de garbage collector)
	 * But here use ChangeScene if you want to Change because i do not
	 * Delete current scene
	 */
	void setScene(Scene* scene);

	// Setter for the last scene.
	void setLastScene();

	// Getter for the scene.
	Scene* getScene() const;
};

#endif
