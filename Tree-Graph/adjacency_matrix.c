#include <stdio.h>

#define MAX_VERTICES 100

int main() {
    int num_vertices, num_edges, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the edges (vertex1 vertex2):\n");
    for (int k = 0; k < num_edges; ++k) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        if (vertex1 >= num_vertices || vertex2 >= num_vertices || vertex1 < 0 || vertex2 < 0) {
            printf("Invalid input: vertex out of range.\n");
            return 1;
        }
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1; // If the graph is undirected
    }

    // Printing the adjacency matrix
    printf("Adjacency Matrix:\n");
    for (i = 0; i < num_vertices; ++i) {
        for (j = 0; j < num_vertices; ++j) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
