#include "offLoader.h"
#include <fstream>

using std::getline;
using std::ifstream;

// TODO: handle blank lines
// TODO: handle comments (# ....,
//                        5, 10, 1 # this is a vert)
// TODO: handle face colours
Object readOFFFile(ifstream& file) {
    // confirm file is OFF format
    string line, discard;

    getline(file, line);  // "OFF"
    if (line != "OFF") {
        throw std::invalid_argument(
            "File doesn't fit OFF format: first line does not read \"OFF\"");
    }

    // allocate new object
    Object res;

    // read in off details: nvert nfaces nedges
    size_t numVerts = 0, numFaces = 0;
    file >> numVerts >> numFaces >> discard;  // discard edges

    // read in vertices
    for (size_t i = 0; i < numVerts; ++i) {
        float x = 0, y = 0, z = 0;
        file >> x >> y >> z;
        res.addVertex(Object::Vertex(x, y, z));
    }

    // read in faces
    for (size_t i = 0; i < numFaces; ++i) {
        Object::Face face;

        // read number of verts in this face
        size_t numVertsinFace = 0;
        file >> numVertsinFace;

        // read in the index of each vertex (a dynamic number of indices)
        for (size_t j = 0; j < numVertsinFace; ++j) {
            size_t vertIndex = 0;
            file >> vertIndex;
            face.vertexNums.push_back(vertIndex);
        }
    }
    file.close();

    return res;
}