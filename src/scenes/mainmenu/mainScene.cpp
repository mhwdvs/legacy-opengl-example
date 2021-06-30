#include "mainScene.h"
#include <memory>
#include "keyboard.h"

void draw() {
    // Clear the colorbuffer
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

Scene* constructMainScene() {
    return new Scene(draw, key_callback);
}
