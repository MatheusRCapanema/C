#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TAMANHO 10000

bool grafo[TAMANHO][TAMANHO];
int distancia[TAMANHO];
int n, t, m, x, y;

int fila[TAMANHO];
int inicio = -1, fim = -1;

void bfs(int start) {
    fila[++fim] = start;
    distancia[start] = 0;

    while (inicio != fim) {
        inicio = (inicio + 1) % TAMANHO;
        int nodo = fila[inicio];
        for (int i = 1; i <= n; i++) {
            if (grafo[nodo][i] && distancia[i] == -1) {
                distancia[i] = distancia[nodo] + 1;
                fim = (fim + 1) % TAMANHO;
                fila[fim] = i;
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
            grafo[x][y] = grafo[y][x] = 1;
        }

        bfs(1);

        int maximo = 0;
        for (int j = 1; j <= n; j++) {
            maximo = (distancia[j] > maximo) ? distancia[j] : maximo;
        }

        printf("%d\n", maximo);
    }
    return 0;
}
