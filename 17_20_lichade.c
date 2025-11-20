#include <stdio.h>
#include <stdlib.h>

int graph[50][50];
int indeg[50];
int n;

void addEdge(int u, int v) {
    graph[u][v] = 1;
}

void computeIndegrees() {
    for (int i = 0; i < n; i++)
        indeg[i] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (graph[i][j] == 1)
                indeg[j]++;
}

void topoSort() {
    computeIndegrees();
    int queue[50], front = 0, rear = -1;
    int result[50];
    int idx = 0;

    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            queue[++rear] = i;

    while (front <= rear) {
        int node = queue[front++];
        result[idx++] = node;

        for (int j = 0; j < n; j++) {
            if (graph[node][j] == 1) {
                indeg[j]--;
                if (indeg[j] == 0)
                    queue[++rear] = j;
            }
        }
    }

    if (idx != n) {
        printf("Topological ordering NOT possible (Cycle found).\n");
        return;
    }

    printf("Topological Order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
    printf("\n");
}

int main() {
    int choice, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    while (1) {
        printf("\n--- TOPOLOGICAL SORT MENU ---\n");
        printf("1. Add Directed Edge\n");
        printf("2. Perform Topological Sort\n");
        printf("3. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter edge u v (u -> v): ");
                scanf("%d %d", &u, &v);

                if (u >= 0 && v >= 0 && u < n && v < n) {
                    addEdge(u, v);
                    printf("Edge inserted.\n");
                } else {
                    printf("Invalid vertices.\n");
                }
                break;

            case 2:
                topoSort();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
