#pragma once
#include "../scene.h"
#include "keyboard.h"

struct MainScene : public Scene {
   public:
    MainScene();

    void draw() override;
    void keyboardCallback(GLFWwindow* window,
                          int key,
                          int scancode,
                          int action,
                          int mode) override;
};
