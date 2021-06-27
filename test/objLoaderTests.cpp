#include <sstream>
#include "gtest/gtest.h"
#include "loaders/offLoader.h"

using std::istringstream;

TEST(ObjLoaderTests, TestWithFile) {
    auto file = istringstream(
        "OFF\n"
        "#\n"
        "#  unitcube.off\n"
        "#  A unit cube, with RGB face information.\n"
        "#\n"
        "8 6 12\n"
        "0.0  0.0  0.0\n"
        "1.0  0.0  0.0\n"
        "1.0  1.0  0.0\n"
        "0.0  1.0  0.0\n"
        "0.0  0.0  1.0\n"
        "1.0  0.0  1.0\n"
        "1.0  1.0  1.0\n"
        "0.0  1.0  1.0\n"
        "4  0 1 2 3  0.800 0.098 0.098\n"
        "4  4 5 6 7  0.098 0.647 0.400\n"
        "4  2 3 7 6  0.098 0.098 0.800\n"
        "4  0 1 5 4  0.898 0.600 0.000\n"
        "4  0 4 7 3  0.000 0.600 0.800\n"
        "4  1 2 6 5  0.498 0.000 0.898\n");
    auto obj = readOFFFile(file);

    ASSERT_EQ(obj.faces.size(), 6);
    ASSERT_EQ(obj.vertices.size(), 8);
}