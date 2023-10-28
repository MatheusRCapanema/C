#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10001

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v);
void addEdge(Node* adjList[], int u, int v);
int DFS(Node* adjList[], int v, bool visited[]);

int main() {
    int n, u, v, i;
    scanf("%d", &n);

    Node* adjList[MAX_NODES] = {NULL};

    for (i = 0; i < n - 1; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adjList, u, v);
    }

    bool visited[MAX_NODES] = {false};
    int farthestNode = DFS(adjList, 1, visited);

    for (i = 1; i <= n; i++) {
        visited[i] = false;
    }

    int longestPath = DFS(adjList, farthestNode, visited) - 1;
    printf("%d\n", longestPath);

    return 0;
}

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjList[], int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

int DFS(Node* adjList[], int v, bool visited[]) {
    visited[v] = true;
    int maxDist = 0;
    int currentDist;
    Node* temp = adjList[v];

    while (temp) {
        if (!visited[temp->vertex]) {
            currentDist = DFS(adjList, temp->vertex, visited);
            if (currentDist > maxDist) {
                maxDist = currentDist;
            }
        }
        temp = temp->next;
    }

    return maxDist + 1;
}
