#include "mainScene.h"

#include <memory>

#include "../../glFuncs.h"
#include "../../loaders/fileIO.h"
#include "../../loaders/offLoader.h"
#include "keyboard.h"

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
    objects.push_back(readOFFFile(openFile("res/off/unitcube.off")));
}
