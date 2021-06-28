#include "window.h"
#include <stdexcept>

void Window::registerKeyboardCallback(GLFWkeyfun callback) {
    // Set the required callback functions
    glfwSetKeyCallback(window, callback);
}

Window::Window(const int WIDTH,
               const int HEIGHT,
               const string& WINDOW_NAME,
               Scene& initScene) {
    window = glfwCreateWindow(WIDTH,
                              HEIGHT,
                              WINDOW_NAME.c_str(),
                              nullptr,
                              nullptr);
    glfwMakeContextCurrent(window);
    if (window == nullptr) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    registerKeyboardCallback(initScene.keyboardCallback);
}

void Window::mainLoop() {
    // Check if any events have been activated (key pressed, mouse moved
    // etc.) and call corresponding response functions
    glfwPollEvents();

    // draw the scene
    scene.draw();

    // Swap the screen buffers
    glfwSwapBuffers(window);
}

bool Window::shouldClose() {
    return !glfwWindowShouldClose(window);
}
