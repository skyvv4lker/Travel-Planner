#include <iostream>
#include "Parser.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " <source> <destination> <preference>\n";
        return 1;
    }

    string source = argv[1];
    string destination = argv[2];
    string preference = argv[3]; // for now ignored, but can extend for cost/time

    Parser parser("edges.csv");  // load from edges file
    Graph graph = parser.parseGraph();

    PathResult result = graph.dijkstra(source, destination);

    if (result.path.empty()) {
        cout << "No route found between " << source << " and " << destination << endl;
        return 0;
    }

    cout << "Source: " << source << endl;
    cout << "Destination: " << destination << endl;
    cout << "Preference: " << preference << endl;
    cout << "Optimal Route: ";
    for (size_t i = 0; i < result.path.size(); i++) {
        cout << result.path[i];
        if (i < result.path.size() - 1) cout << " -> ";
    }
    cout << endl;
    cout << "Total Cost: " << result.cost << endl;
    return 0;
}

