#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 9  // Number of vertices

// Function to find the vertex with the minimum distance
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the shortest distance from source to all vertices
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    int i;
    for ( i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

// Function implementing Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];  // Store the shortest distance to each vertex
    bool sptSet[V] = {false};  // Boolean array to track processed vertices
  int i;
    // Initialize all distances to infinity and source to 0
    for ( i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
int count;
    // Find the shortest path for all vertices
    for ( count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);  // Get the vertex with the minimum distance
        sptSet[u] = true;  // Mark it as processed
           int v;
        // Update the distance values of the adjacent vertices
        for ( v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);  // Print the result
}

// Driver code to test the algorithm
int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);  // Call Dijkstra's algorithm with source vertex 0
    return 0;
}

