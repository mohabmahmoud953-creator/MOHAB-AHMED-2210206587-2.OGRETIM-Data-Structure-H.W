#include <stdio.h>
#include <stdlib.h>

int adj[5][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0}
};
int visited[5];

void DFS(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}

void BFS(int start, int n) {
    int queue[5], front = 0, rear = 0;
    int visited_bfs[5] = {0};

    visited_bfs[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited_bfs[i]) {
                visited_bfs[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    for(int i=0; i<5; i++) visited[i] = 0;
    printf("DFS Traversal: ");
    DFS(0, 5);

    printf("\nBFS Traversal: ");
    BFS(0, 5);

    return 0;
}
