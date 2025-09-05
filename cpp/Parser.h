#pragma once
#include "Graph.h"
#include <string>

class Parser {
private:
    std::string edgeFile;
public:
    Parser(const std::string& edgeFile);
    Graph parseGraph();
};
