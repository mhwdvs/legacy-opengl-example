#include "fileIO.h"

ifstream openFile(const string& INPUT_FILE_NAME) {
    ifstream is(INPUT_FILE_NAME);
    if (is) {
        return is;
    }
    else {
        throw std::runtime_error("Failed to open file!");
    }
}
