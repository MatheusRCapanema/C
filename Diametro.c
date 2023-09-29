#include <stdio.h>
#include <stdbool.h>

#define MAX_NOS 1000

int grafo[MAX_NOS][MAX_NOS];
bool visitado[MAX_NOS];
int distancias[MAX_NOS];
int fila[MAX_NOS];
int inicio, fim;

int bfs(int partida, int n) {
    for (int i = 0; i < n; i++) visitado[i] = false;
    inicio = 0; fim = -1;

    fila[++fim] = partida;
    visitado[partida] = true;
    int maxDist = 0;

    while (inicio <= fim) {
        int atual = fila[inicio++];
        for (int i = 0; i < n; i++) {
            if (grafo[atual][i] && !visitado[i]) {
                visitado[i] = true;
                distancias[i] = distancias[atual] + 1;
                fila[++fim] = i;
                if (distancias[i] > maxDist) maxDist = distancias[i];
            }
        }
    }
    return maxDist;
}

int main() {
    int n, e, a, b;
    printf("Digite o número de nós: ");
    scanf("%d", &n);
    printf("Digite o número de arestas: ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);
        grafo[a][b] = grafo[b][a] = 1;
    }
    printf("Diâmetro da árvore: %d\n", bfs(bfs(0, n), n));
    return 0;
}
