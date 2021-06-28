#include "scene.h"

Scene::Scene() : keyboardCallback(key_callback) {}

void Scene::draw() {
    // Clear the colorbuffer
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    for (auto object : objects) {
    }
}
