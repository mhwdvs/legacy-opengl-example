#include "scene.h"
#include "../glFuncs.h"

Scene::Scene(void (*drawFunc)(void),
             void (*keyFunc)(GLFWwindow* window,
                             int key,
                             int scancode,
                             int action,
                             int mode))
    : draw(drawFunc),
      keyboardCallback(keyFunc) {}
