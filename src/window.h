#pragma once
#include <string>
#include "glFuncs.h"
#include "scene.h"

using std::string;

class Window {
   public:
    Window(const int WIDTH,
           const int HEIGHT,
           const string& WINDOW_NAME,
           Scene* incScene);
    ~Window();
    void setScene(Scene* incScene);
    void mainLoop();
    bool shouldClose();

   private:
    Scene* scene;
    GLFWwindow* window;

    void registerKeyboardCallback(GLFWkeyfun callback);
};
