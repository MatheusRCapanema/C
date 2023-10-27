#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100005
#define MOD 1000000007

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

Vector adj[MAX_NODES];
bool visited[MAX_NODES];
int nodes, edges;
long long componentSize;

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
    componentSize++;
    for (int i = 0; i < adj[node].size; i++) {
        if (!visited[adj[node].data[i]]) {
            dfs(adj[node].data[i]);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &nodes, &edges);

        for (int i = 1; i <= nodes; i++) {
            initVector(&adj[i]);
            visited[i] = false;
        }

        for (int i = 0; i < edges; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            push_back(&adj[u], v);
            push_back(&adj[v], u); 
        }

        long long totalWays = 1;
        long long maxSize = 0;
        for (int i = 1; i <= nodes; i++) {
            if (!visited[i]) {
                componentSize = 0;
                dfs(i);
                maxSize = (maxSize > componentSize) ? maxSize : componentSize;
                totalWays = (totalWays * componentSize) % MOD;
            }
        }

        printf("%lld %lld\n", maxSize, totalWays);

        for (int i = 1; i <= nodes; i++) {
            free(adj[i].data);
        }
    }
    return 0;
}
