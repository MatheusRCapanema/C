#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TAMANHO 10000

int adj[TAMANHO][TAMANHO];
bool visitado[TAMANHO];
int m,n;

bool dfs(int inicio, int i) {
    visitado[i] = true;
    for (int j = 1; j <= n; ++j) {
        if(adj[inicio][j]){
            if(!visitado[j]){
                if(!dfs(j,inicio))
                    return false;
            }else if(j != i){
                return false;
            }
        }
    }
    return true;
}

bool isThree(int l) {
    int inicio = l;

    if(!dfs(inicio,-1))
        return false;


    for (int i = 0; i <=n; ++i) {
        if(!visitado[i])
            return false;
    }

    return true;
}

int main() {

    scanf("%d %d",&n,&m);

    if(m != n-1){
        printf("Não é árvore");
        return 0;
    }

    for (int i = 0; i < m; ++i) {
        int x,y;
        scanf("%d %d",&x,&y);
        adj[x][y] = adj[y][x] = 1;
    }

    int l = 0;
    scanf("%d",&l);

    if(isThree(l)){
        printf("É árvore");
    }else{
        printf("Não é árvore");
    }

}


