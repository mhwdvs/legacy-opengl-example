#include "offLoader.h"
#include <sstream>
#include <string>

using std::getline;
using std::string;
using std::stringstream;

// TODO: handle blank lines
// TODO: handle face colours
Object readOFFFile(istream& file) {
    // allocate new object
    Object res;
    string line, discard;

    getline(file, line);  // "OFF"
    if (line == "OFF") {
        getline(file, line);
    }

    // keep reading lines until one that isnt a comment
    while (line[0] == '#') {
        getline(file, line);
    }
    // read in off details: nvert nfaces nedges
    size_t numVerts = 0, numFaces = 0;
    stringstream detailsline(line);
    detailsline >> numVerts >> numFaces >> discard;  // discard edges

    // read in vertices
    for (size_t i = 0; i < numVerts; ++i) {
        getline(file, line);
        // keep reading lines until one that isnt a comment
        while (line[0] == '#') {
            getline(file, line);
        }

        stringstream linestream(line);

        float x = 0, y = 0, z = 0;
        linestream >> x >> y >> z;
        res.addVertex(Object::Vertex(x, y, z));
    }

    // read in faces
    for (size_t i = 0; i < numFaces; ++i) {
        Object::Face face;
        getline(file, line);
        // keep reading lines until one that isnt a comment
        while (line[0] == '#') {
            getline(file, line);
        }
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