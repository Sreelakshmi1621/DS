#include <stdio.h>
#include <stdlib.h>

// Function to compare two edges based on their weights (used for sorting)
void sortEdges(int edges[][3], int E) {
    int temp[3];
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                // Swap edges[j] and edges[j + 1]
                for (int k = 0; k < 3; k++) {
                    temp[k] = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp[k];
                }
            }
        }
    }
}

// Function to find the parent of a vertex (using array indexing, no pointers)
int find(int parent[], int i) {
    while (parent[i] != i) {
        i = parent[i];  // Traverse up to find the root
    }
    return i;
}

// Function to do union of two subsets (using array indexing, no pointers)
void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskal(int edges[][3], int V, int E) {
    int parent[V], rank[V];
    
    // Initialize parent and rank arrays
    for (int i = 0; i < V; i++) {
        parent[i] = i;  // Initially, each vertex is its own parent
        rank[i] = 0;    // Initially, the rank is 0
    }

    // Sort edges based on weight
    sortEdges(edges, E);

    printf("Edge : Weight\n");

    int mstEdges = 0;  // Counter for edges in the MST
    for (int i = 0; i < E && mstEdges < V - 1; i++) {
        int u = edges[i][0];   // Start vertex of the edge
        int v = edges[i][1];   // End vertex of the edge
        int weight = edges[i][2];  // Weight of the edge

        // Find the root of the vertices u and v
        int rootU = find(parent, u);
        int rootV = find(parent, v);

        // If they are in different sets, include this edge in the MST
        if (rootU != rootV) {
            printf("%d - %d : %d\n", u, v, weight);
            unionSets(parent, rank, rootU, rootV);  // Union the sets
            mstEdges++;  // Increment MST edge count
        }
    }
}

int main() {
    // Number of vertices and edges
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges

    // Array to store edges: each edge is represented as {u, v, weight}
    int edges[5][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Call Kruskal's algorithm to find the MST
    kruskal(edges, V, E);

    return 0;
}

