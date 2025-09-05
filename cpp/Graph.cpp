#include "Graph.h"
#include <queue>
#include <unordered_map>
#include <set>

void Graph::addEdge(const string& src, const string& dest, double weight) {
    adj[src].push_back({dest, weight});
    adj[dest].push_back({src, weight}); // undirected
}

PathResult Graph::dijkstra(const string& src, const string& dest) {
    unordered_map<string, double> dist;
    unordered_map<string, string> parent;
    set<pair<double, string>> pq;

    for (auto& node : adj) {
        dist[node.first] = numeric_limits<double>::infinity();
    }

    dist[src] = 0;
    pq.insert({0, src});

    while (!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());

        if (u == dest) break;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                pq.erase({dist[v], v});
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.insert({dist[v], v});
            }
        }
    }

    PathResult result;
    result.cost = dist[dest];

    if (result.cost == numeric_limits<double>::infinity()) {
        return result; // no path
    }

    // Reconstruct path
    vector<string> path;
    for (string at = dest; !at.empty(); at = parent[at]) {
        path.push_back(at);
        if (at == src) break;
    }
    reverse(path.begin(), path.end());

    result.path = path;
    return result;
}
