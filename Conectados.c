#include <stdio.h>
#include <string.h>

#define MAXN 1000

int graph[MAXN][MAXN];
int visited[MAXN];
int n, e;

void dfs(int u) {
    visited[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (graph[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    scanf("%d %d", &n, &e);
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
    
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;  // Representação não direcionada
    }
    
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }
    
    printf("%d\n", components);
    return 0;
}