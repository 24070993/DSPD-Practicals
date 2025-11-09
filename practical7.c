#include <stdio.h>

int graph[10][10] = {
    {0,0,0,0,0,0,0,0,0,0}, // Dummy 0
    {0,0,1,0,1,0,0,0,0,0}, // 1
    {0,1,0,1,0,1,0,0,0,0}, // 2
    {0,0,1,0,0,0,0,0,1,0}, // 3
    {0,1,0,0,0,1,0,0,0,0}, // 4
    {0,0,1,0,1,0,1,0,0,0}, // 5
    {0,0,0,0,0,1,0,0,0,1}, // 6
    {0,0,0,0,0,0,1,0,1,0}, // 7
    {0,0,0,0,0,0,0,1,0,1}, // 8
    {0,0,0,0,0,0,1,0,0,0}  // 9
};

int visited[10];

void BFS(int start) {
    int q[20], front = 0, rear = 0;
    q[rear++] = start;
    visited[start] = 1;
    printf("BFS: ");
    while (front < rear) {
        int node = q[front++];
        printf("%d ", node);
        for (int i = 1; i <= 9; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }
}

void DFS(int node) {
    printf("%d ", node);
    visited[node] = 1;
    for (int i = 1; i <= 9; i++) {
        if (graph[node][i] && !visited[i])
            DFS(i);
    }
}

int main() {
    // Reset visited array before BFS
    for (int i = 1; i <= 9; i++)
        visited[i] = 0;

    BFS(1);

    // Reset visited array before DFS
    for (int i = 1; i <= 9; i++)
        visited[i] = 0;

    printf("\nDFS: ");
    DFS(1);

    return 0;
}
