#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 2005

int t, n, m, x, y, cor[MAX];
bool graph[MAX][MAX], found;

// Função de DFS para colorir o gráfico
bool dfs(int node, int c) {
    cor[node] = c;  // Atribui a cor ao nó

    for (int i = 1; i <= n; i++) {
        if (graph[node][i]) {  // Se os nós são adjacentes
            if (cor[i] == -1) {  // Se o nó adjacente ainda não foi visitado
                if (!dfs(i, 1-c)) return false;  // Tente colorir com a cor oposta
            }
            else if (cor[i] == cor[node]) return false;  // Se eles já foram visitados e têm a mesma cor
        }
    }
    return true;
}

int main() {
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++) {
        scanf("%d%d", &n, &m);
        
        // Limpar as variáveis
        memset(graph, 0, sizeof graph);
        memset(cor, -1, sizeof cor);
        
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &x, &y);
            graph[x][y] = graph[y][x] = 1;  // Marcar a aresta no gráfico
        }
        
        bool is_bipartite = true;
        for (int i = 1; i <= n && is_bipartite; i++) {
            if (cor[i] == -1) {
                is_bipartite &= dfs(i, 0);  // Iniciar DFS com a primeira cor
            }
        }

        // Imprimir a saída
        printf("Scenario #%d:\n", cs);
        if (is_bipartite) {
            printf("No suspicious bugs found!\n");
        } else {
            printf("Suspicious bugs found!\n");
        }
    }
    return 0;
}
