#include <iostream>

#include "datastructures/window.h"
#include "glFuncs.h"

// Window dimensions
const int WIDTH = 800, HEIGHT = 600;

// The MAIN function, from here we start the application and run the game loop
int main() {
    // Init GLFW
    glfwInit();

    Scene mainScene;
    Window window(WIDTH, HEIGHT, "Legacy OpenGL Example", mainScene);

    // Load OpenGL functions, gladLoadGL returns the loaded version, 0 on error.
    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }

    // Game loop
    while (window.shouldClose()) {
        window.mainLoop();
    }

    // Terminates GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}
