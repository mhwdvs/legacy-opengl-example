#pragma once
#include <fstream>
#include <string>

using std::ifstream;
using std::string;

ifstream openFile(const string& INPUT_FILE_NAME);
