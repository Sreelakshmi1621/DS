#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INF 9999999
#define V 5

// Adjacency matrix representation of the graph
int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}
};

int main() {
    int no_edge = 0;  // number of edges in MST
    int selected[V];  // Array to track selected vertices
    memset(selected, false, sizeof(selected));  // Initialize selected array to false

    selected[0] = true;  // Start with the first vertex
    int x, y;            // Variables to store the selected vertices for the edge

    printf("Edge : Weight\n");

    // While the MST doesn't contain V-1 edges
    while (no_edge < V - 1) {
        int min = INF;  // Initialize minimum weight to a large value
        x = y = 0;      // Initialize vertices for the edge

        // Traverse all the vertices to find the smallest edge connecting
        // a selected vertex to a non-selected one
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    // Only consider non-selected vertices with an edge between them
                    if (!selected[j] && G[i][j] && G[i][j] < min) {
                        min = G[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        // Print the selected edge and its weight
        printf("%d - %d : %d\n", x, y, G[x][y]);

        // Mark vertex y as selected
        selected[y] = true;

        // Increment the number of edges in the MST
        no_edge++;
    }

    return 0;
}

