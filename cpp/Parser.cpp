#include "Parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

Parser::Parser(const std::string& edgeFile) : edgeFile(edgeFile) {}

Graph Parser::parseGraph() {
    Graph g;
    std::ifstream file(edgeFile);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string src, dest;
        double weight;
        getline(ss, src, ',');
        getline(ss, dest, ',');
        ss >> weight;
        g.addEdge(src, dest, weight);
    }

    return g;
}
