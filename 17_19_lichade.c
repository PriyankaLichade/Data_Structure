#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node *next;
};

struct Node *adj[50];
int visited[50], disc[50], low[50], parent[50];
int timeCount, cutFound;

void addEdge(int u, int v) {
    struct Node *t1 = (struct Node*)malloc(sizeof(struct Node));
    t1->v = v; t1->next = adj[u]; adj[u] = t1;

    struct Node *t2 = (struct Node*)malloc(sizeof(struct Node));
    t2->v = u; t2->next = adj[v]; adj[v] = t2;
}

void dfs(int u) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCount;
    int childCount = 0;

    struct Node *ptr = adj[u];
    while (ptr != NULL) {
        int v = ptr->v;

        if (!visited[v]) {
            parent[v] = u;
            childCount++;

            dfs(v);

            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            if (parent[u] == -1 && childCount > 1)
                cutFound = 1;

            if (parent[u] != -1 && low[v] >= disc[u])
                cutFound = 1;
        }
        else if (v != parent[u]) {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
        ptr = ptr->next;
    }
}


int isBiconnected(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    timeCount = 0;
    cutFound = 0;

    dfs(0);  

    for (int i = 0; i < n; i++)
        if (!visited[i]) return 0;

    return !cutFound;
}

int main() {
    int n, choice, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    while (1) {
        printf("\n--- GRAPH MENU ---\n");
        printf("1. Add Edge\n");
        printf("2. Check Biconnected\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter edge (u v): ");
                scanf("%d %d", &u, &v);
                if (u >= 0 && v >= 0 && u < n && v < n) {
                    addEdge(u, v);
                    printf("Edge inserted.\n");
                } else {
                    printf("Invalid vertices.\n");
                }
                break;

            case 2:
                if (isBiconnected(n))
                    printf("Graph IS Biconnected.\n");
                else
                    printf("Graph is NOT Biconnected.\n");
                break;

            case 3:
                return 0;

            default:
                printf("Invalid option.\n");
        }
    }
}
