#pragma once
#include <vector>

using std::vector;

class Object {
   public:
    struct Vertex {
        Vertex(float inxX, float incY, float incZ);
        float x;
        float y;
        float z;
    };

    struct Face {
        vector<size_t> vertexNums;
    };

    void addFace(const Face& incVertices);
    void addVertex(const Vertex& incV);

    vector<Face> faces;
    vector<Vertex> vertices;
};
