/* File: scene.cpp
 * Author: Klotz Tom
 */
#include "Concordia_Game/abstract/scene.hpp"

Scene::Scene(SceneManager *sceneManager) { this->sceneManager = sceneManager; }

Scene::Scene() {}

Scene::~Scene() {}

void Scene::changeScene(Scene *nextScene) {
  this->sceneManager->changeScene(nextScene);
  // here is where i free the memory
  delete this;
}
// !! CAUTION !! Explain in /Concordia_Game/concrete/scenemanager.hpp !!
void Scene::setSceneManager(SceneManager *sceneManager) {
  this->sceneManager = sceneManager;
}

SceneManager *Scene::getSceneManager() {
  return this->sceneManager;
}
