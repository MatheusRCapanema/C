#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    struct pilha *topo;
}pilha;

typedef struct Registro{
    int valor;
    struct registro *prox;
}registro;


lista *alocapilha(){
    pilha *novo;
    novo=(pilha *)malloc(sizeof(pilha));
    novo->topo=NULL;
    return novo;
};
registro *alocaregistro(){
    registro *novo;
    novo=(registro *)malloc(sizeof(registro));
    novo->topo=NULL;
    return novo;
}

void push(lista *l, int numero){
    registro *novo;
    novo=alocaregistro();
    novo->valor=numero;
    if(l->inicio==NULL){
        l->inicio =novo;
    }else{
        novo->prox=l->inicio;
        l->inicio=novo;
}
    
int desempilha(pilha *p){
    NO* ptr = p->topo;
    int dado;
    if(ptr == NULL){
        printf("\n Pilha Vazia\n");
    }else{
        p->topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
}
void imprimir_pilha(pilha *p){
    NO* ptr= p->topo;
    if(ptr == NULL){
        printf("\n Pilha Vazia\n");
    }else{
        while(ptr != NULL){
            printf("\n %d \n",ptr->dado);
            ptr = ptr->prox;
        }
    }

}
int main(){
    pilha *p1;
    p1 = alocalista();
    menu(p1);
}
