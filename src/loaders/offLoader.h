#pragma once
#include <string>
#include "../datastructures/object.h"

using std::ifstream;
using std::string;

Object readOFFFile(ifstream& fileName);