#pragma once
#include <string>
#include <vector>
#include <map>
#include <limits>
using namespace std;

struct PathResult {
    vector<string> path;
    double cost;
};

class Graph {
private:
    map<string, vector<pair<string, double>>> adj;

public:
    void addEdge(const string& src, const string& dest, double weight);
    PathResult dijkstra(const string& src, const string& dest);
};
