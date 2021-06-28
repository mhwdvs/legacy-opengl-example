#include "object.h"

Object::Vertex::Vertex(float incX, float incY, float incZ)
    : x(incX),
      y(incY),
      z(incZ) {}

void Object::addFace(const Face& incVertices) {
    faces.push_back(incVertices);
}

void Object::addVertex(const Vertex& incV) {
    vertices.push_back(incV);
}
