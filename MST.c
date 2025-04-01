#include <stdio.h>
#include <stdlib.h>

// Comparator function to sort edges based on weight
int comparator(const void* p1, const void* p2) {
    int (*x)[3] = (int (*)[3])p1;
    int (*y)[3] = (int (*)[3])p2;
    return (*x)[2] - (*y)[2];
}

// Function to initialize the disjoint set (union-find)
void makeSet(int parent[], int rank[], int n) {
	int i;
    for ( i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find the representative of the set that contains 'component'
int findParent(int parent[], int component) {
    if (parent[component] == component)
        return component;
    return findParent(parent, parent[component]);
}

// Union of two sets containing 'u' and 'v'
void unionSet(int u, int v, int parent[], int rank[]) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    
    if (u != v) {
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

// Kruskal's Algorithm to find Minimum Spanning Tree
void kruskalAlgo(int n, int edge[n][3]) {
    qsort(edge, n, sizeof(edge[0]), comparator); // Sort edges based on weight
    
    int parent[n], rank[n];
    makeSet(parent, rank, n); // Initialize disjoint set
    
    int minCost = 0;
    printf("Following are the edges in the constructed MST:\n");
    int i;
    for ( i = 0; i < n; i++) {
        int v1 = findParent(parent, edge[i][0]);
        int v2 = findParent(parent, edge[i][1]);
        int wt = edge[i][2];
        
        // If adding this edge doesn't form a cycle
        if (v1 != v2) {
            unionSet(v1, v2, parent, rank); // Union the sets
            minCost += wt; // Add the weight of this edge to minCost
            printf("%d -- %d == %d\n", edge[i][0], edge[i][1], wt);
        }
    }
    printf("Minimum Cost Spanning Tree: %d\n", minCost);
}

int main() {
    int edge[5][3] = { {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4} };
    kruskalAlgo(5, edge); // Call Kruskal's Algorithm
    return 0;
}

