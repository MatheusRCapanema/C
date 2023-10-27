#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 10005

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

Vector adj[MAX_NODES];
bool visited[MAX_NODES];
int nodes, edges;

void initVector(Vector* v) {
    v->data = malloc(10 * sizeof(int));
    v->size = 0;
    v->capacity = 10;
}

void push_back(Vector* v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < adj[node].size; i++) {
        if (!visited[adj[node].data[i]]) {
            dfs(adj[node].data[i]);
        }
    }
}

int main() {
    scanf("%d %d", &nodes, &edges);

    for (int i = 1; i <= nodes; i++) {
        initVector(&adj[i]);
    }

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        push_back(&adj[u], v);
        push_back(&adj[v], u);
    }

    int connectedComponents = 0;
    for (int i = 1; i <= nodes; i++) {
        if (!visited[i]) {
            dfs(i);
            connectedComponents++;
        }
    }

    if (connectedComponents == 1 && edges == nodes - 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    for (int i = 1; i <= nodes; i++) {
        free(adj[i].data);
    }

    return 0;
}
