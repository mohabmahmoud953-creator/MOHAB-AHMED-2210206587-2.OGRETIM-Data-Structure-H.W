#include <stdio.h>

int visited[5] = {0};
int adj[5][5] = {
    {0, 1, 1, 0, 0}, // Cluster 1 (Nodes 0, 1, 2)
    {1, 0, 1, 0, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1}, // Cluster 2 (Nodes 3, 4)
    {0, 0, 0, 1, 0}
};

void findCluster(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            findCluster(i, n);
        }
    }
}

int main() {
    printf("Extracted Clusters:\n");
    for (int i = 0; i < 5; i++) {
        if (!visited[i]) {
            printf("Cluster: ");
            findCluster(i, 5);
            printf("\n");
        }
    }
    return 0;
}
------------------------------------------------------------

//1. How we do cluster in graph? We perform clustering by grouping nodes that have a high density of edges between them. This is done using two main strategies:

//Agglomerative (Bottom-Up): Starting with each node as a separate cluster and merging them based on similarity.

//Divisive (Top-Down): Starting with the entire graph as one cluster and recursively splitting it into smaller groups.

//2. How are they separated? Clusters are separated by identifying and removing the edges that connect different communities (bridge edges). The main methods are:

//Edge Betweenness: Removing edges that lie on the highest number of shortest paths between nodes.

//Modularity Maximization: Partitioning the graph to maximize the density of internal connections versus external ones.


//Normalized Cuts: Using mathematical matrices (Laplacian Matrix) to split the graph into balanced segments.
