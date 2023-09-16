#include <stdio.h>
#include <stdbool.h>
#include <string.h>

# define SIZE 10000

int inp_arr[SIZE];
int Rear = - 1;
int Front = - 1;


bool graph[SIZE][SIZE], found;
int distancia[SIZE];
int n, e, t, n, m, x, y;

void bfs(int node) {
        if(distancia[node] == -1){
            distancia[node] = 0;
            for (int j = 1; j <= n ; ++j) {
                if(graph[node][j]){
                    if(distancia[j] == -1){
                        distancia[j] = distancia[node] + 1;
                    }
                }
            }
        }else{
            distancia[node] = distancia[node] + 1;

            for(int i = 1; i<=n; i++){
                if(graph[node][i]){
                    if(distancia[i] == -1){
                        distancia[i] = distancia[node];
                    }
                }
            }

        }

}


int main() {

    int maximo = 0;

    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++) {
        scanf("%d%d", &n, &m);

        memset(graph, 0, sizeof graph);
        memset(distancia, -1, sizeof distancia);

        for (int i = 0; i < m; i++) {
            scanf("%d%d", &x, &y);
            graph[x][y] = graph[y][x] = 1;  // Marcar a aresta no gráfico
        }

        for (int i = 1; i <= n; i++) {
                bfs(i);  // Iniciar DFS com a primeira cor
        }

        for (int j = 0; j <= n; ++j) {
            if(distancia[n-1] < distancia[n]){
                maximo = distancia[n];
            }
        }

        printf("%d:\n", maximo);

    }

}
/*
 3
4 3
1 2
2 3
3 4
5 4
1 2
1 3
3 4
4 5
6 7
1 2
1 3
1 4
2 5
3 6
4 6
5 6


 3
2
2
 */