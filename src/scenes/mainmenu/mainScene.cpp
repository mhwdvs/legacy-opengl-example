#include "mainScene.h"

#include <memory>

#include "../../glFuncs.h"
#include "../../loaders/fileIO.h"
#include "../../loaders/offLoader.h"
#include "keyboard.h"
#include <glm/vec3.hpp>

void MainScene::draw() {
    // Clear the colorbuffer
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // draw objects
    for (auto object : objects) {
    }

    glClear(GL_COLOR_BUFFER_BIT);
}

void MainScene::keyboardCallback(GLFWwindow* window,
                                 int key,
                                 int scancode,
                                 int action,
                                 int mode) {
    key_callback(window, key, scancode, action, mode);
}

MainScene::MainScene() {
    // construct camera
    glMatrixMode(GL_PROJECTION);

    // load objects
    auto file = openFile("res/off/unitcube.off"); // can't be inline as it needs to be a lvalue
    objects.push_back(readOFFFile(file));
}
