#include "offLoader.h"
#include <fstream>
#include <sstream>
#include <string>

using std::getline;
using std::istream;
using std::string;
using std::stringstream;

// TODO: handle blank lines
// TODO: handle comments (# ....,
//                        5, 10, 1 # this is a vert)
// TODO: handle face colours
Object readOFFFile(istream& file) {
    string line, discard;

    getline(file, line);  // "OFF"

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
        getline(file, line);
        stringstream linestream(line);

        // read number of verts in this face
        size_t numVertsinFace = 0;
        linestream >> numVertsinFace;

        // read in the index of each vertex (a dynamic number of indices)
        for (size_t j = 0; j < numVertsinFace; ++j) {
            size_t vertIndex = 0;
            linestream >> vertIndex;
            face.vertexNums.push_back(vertIndex);
        }

        res.addFace(face);
    }

    return res;
}