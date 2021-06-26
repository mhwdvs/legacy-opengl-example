#include "gtest/gtest.h"
#include "loaders/fileIO.h"
#include "loaders/offLoader.h"

TEST(ObjLoaderTests, TestWithFile) {
    auto file = openFile("../res/unitcube.off");
    auto obj = readOFFFile(file);

    ASSERT_EQ(obj.faces.size(), 6);
    ASSERT_EQ(obj.vertices.size(), 8);
}