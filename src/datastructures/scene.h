#pragma once
#include <string>
#include "../keyboard.h"
#include "object.h"

using std::string;

class Scene {
   public:
    Scene();
    vector<Object> objects;
    GLFWkeyfun keyboardCallback;
    void draw();

   private:
};
