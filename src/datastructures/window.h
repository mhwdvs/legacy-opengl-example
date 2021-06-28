#pragma once
#include <string>
#include "scene.h"

using std::string;

class Window {
   public:
    Window(const int WIDTH,
           const int HEIGHT,
           const string& WINDOW_NAME,
           Scene& initScene);
    void setScene(const Scene& incScene);
    void mainLoop();
    bool shouldClose();

   private:
    Scene scene;
    GLFWwindow* window;
    void registerKeyboardCallback(GLFWkeyfun callback);
};
