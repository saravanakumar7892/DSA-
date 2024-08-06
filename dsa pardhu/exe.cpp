#include <bits/stdc++.h>
using namespace std;

#define V 5  // Number of vertices

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest path tree

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0; // Distance of source vertex from itself is always 0

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet); // Pick the minimum distance vertex from the set of vertices not yet processed
        sptSet[u] = true; // Mark the picked vertex as processed

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "Vertex \t\t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << endl;
}

int main() {
    int graph[V][V] = {
        {0, 3, 6, 0, 0},
        {0, 0, 2, 1, 4},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0}
    };

    dijkstra(graph, 0); // Source vertex is 0

    return 0;
}