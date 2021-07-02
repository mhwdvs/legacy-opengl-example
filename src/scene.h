#pragma once
#include <string>

#include "camera.h"
#include "glFuncs.h"
#include "object.h"

using std::string;

class Scene {
   public:
    virtual void draw() = 0;
    virtual void keyboardCallback(GLFWwindow* window,
                                  int key,
                                  int scancode,
                                  int action,
                                  int mode) = 0;

   protected:
    vector<Object> objects;
    Camera camera;

   private:
    void loadObjFromFile(const string& FILE_NAME);
};
