#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

void createGraph() {
    int i, j;

    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void printGraph() {
    int i, j;

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0, i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfsUtil(int node) {
    int i;

    visited[node] = 1;
    printf("%d ", node);

    for (i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfsUtil(i);
        }
    }
}

void dfs(int start) {
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    dfsUtil(start);
    printf("\n");
}

int main() {
    int choice, start;

    while (1) {
        printf("\n--- GRAPH MENU ---\n");
        printf("1. Create Graph\n");
        printf("2. Print Graph\n");
        printf("3. BFS Traversal\n");
        printf("4. DFS Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph();
                break;

            case 2:
                printGraph();
                break;

            case 3:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                bfs(start);
                break;

            case 4:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                dfs(start);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
