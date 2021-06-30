#pragma once
#include <string>
#include "../glFuncs.h"
#include "../object.h"

using std::string;

struct Scene {
    Scene(void (*drawFunc)(void),
          void (*keyFunc)(GLFWwindow* window,
                          int key,
                          int scancode,
                          int action,
                          int mode));

    vector<Object> objects;
    GLFWkeyfun keyboardCallback;
    void (*draw)(void);
};
