#include "window.h"

#include <iostream>
#include <stdexcept>
#include "scenes/mainmenu/mainScene.h"

void Window::registerKeyboardCallback(GLFWkeyfun callback) {
    // Set the required callback functions
    glfwSetKeyCallback(window, callback);
}

Window::Window(const int WIDTH,
               const int HEIGHT,
               const string& WINDOW_NAME,
               Scene* incScene) {
    // Init GLFW
    glfwInit();

    // Window context needed before OpenGL is loaded
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

    // Load OpenGL functions, gladLoadGL returns the loaded version, 0 on error.
    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0) {
        throw std::runtime_error("Failed to initialize OpenGL context");
    }

    // Define the viewport dimensions (must be done after OpenGL is loaded)
    glViewport(0, 0, WIDTH, HEIGHT);

    setScene(incScene);
}

void Window::mainLoop() {
    // Check if any events have been activated (key pressed, mouse moved
    // etc.) and call corresponding response functions
    glfwPollEvents();

    // draw the scene
    scene->draw();

    // Swap the screen buffers
    glfwSwapBuffers(window);
}

void Window::setScene(Scene* incScene) {
    scene = incScene;
}

Window::~Window() {
    // Terminates GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
}

bool Window::shouldClose() {
    return !glfwWindowShouldClose(window);
}
