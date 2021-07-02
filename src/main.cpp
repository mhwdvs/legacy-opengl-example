#include "scenes/mainmenu/mainScene.h"
#include "window.h"

// Window dimensions
const int WIDTH = 800, HEIGHT = 600;

// The MAIN function, from here we start the application and run the game loop
int main() {
    Window window(WIDTH, HEIGHT, "Legacy OpenGL Example", new MainScene());
    // window.setScene(new Scene(nullptr, nullptr));

    // Game loop
    while (window.shouldClose()) {
        window.mainLoop();
    }

    return 0;
}
