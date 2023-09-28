#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TAMANHO 10000

bool grafo[TAMANHO][TAMANHO];
int distancia[TAMANHO];
int n, e, t, m, x, y;

int fila[TAMANHO];
int inicio = -1, fim = -1;

void enfileirar(int nodo) {
    if (fim == TAMANHO - 1)
        return;
    if (inicio == -1)
        inicio = 0;
    fila[++fim] = nodo;
}

int desenfileirar() {
    if (inicio == -1)
        return -1;
    int val = fila[inicio];
    if (inicio == fim)
        inicio = fim = -1;
    else
        inicio++;
    return val;
}

void bfs(int inicio) {
    enfileirar(inicio);
    distancia[inicio] = 0;
    while (fim != -1) { 
        int nodo = desenfileirar();
        for (int i = 1; i <= n; i++) {
            if (grafo[nodo][i] && distancia[i] == -1) {
                distancia[i] = distancia[nodo] + 1;
                enfileirar(i);
            }
        }
    }
}

int main() {
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++) {
        scanf("%d%d", &n, &m);

        memset(grafo, 0, sizeof grafo);
        memset(distancia, -1, sizeof distancia);

        for (int i = 0; i < m; i++) {
            scanf("%d%d", &x, &y);
            grafo[x][y] = grafo[y][x] = 1;  // Marcar a aresta no grafo
        }

        int maximo = 0;
        bfs(1);  // Iniciar BFS pelo primeiro nodo

        for (int j = 1; j <= n; j++) {
            if (distancia[j] > maximo) {
                maximo = distancia[j];
            }
        }

        printf("%d\n", maximo);
    }

    return 0;
}
