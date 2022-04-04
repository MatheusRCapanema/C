#include <stdio.h>
#include <stdlib.h>

typedef struct registro{

    int valor;
    struct registro *prox;

}registro;


typedef struct lista{
    int qtd;
    struct registro *inicio;
}lista;

lista *aloca_lista(){
    lista *novo;
    novo=(lista *)malloc(sizeof(lista));
    novo->inicio=NULL;
    novo->qtd=0;
    return novo;
}
registro *aloca_registro(){
    registro *novo;
    novo=(registro *)malloc(sizeof(registro));
    novo->valor=0;
    novo->prox=NULL;
    return novo;
}
void push(lista *l, int numero){
    registro *novo,*aux;
    novo=aloca_registro();
    novo->valor =numero;
    if(l->inicio==NULL){
        l->inicio =novo;
    }else{
        aux =l->inicio;
        while(aux->prox != NULL){
            aux=aux->prox;
        }
        aux->prox =novo;
    }
    l->qtd++;
}
/*
void mostrar_lista(lista *l){
    registro *aux;
    if(l->inicio==NULL){
        printf("\n Lista Vazia \n");
    }else{
        aux = l->inicio;
        while(aux!=NULL){
            printf("%d ",aux->valor);
            aux=aux->prox;
        }
    }
}*/
/*int buscar(lista *l,int numero){
    if(l->inicio==NULL) {
        return 0;
    }else{
        registro *aux;
        aux=l->inicio;
        while(aux!=NULL){
            if(aux->valor==numero){
                return 1;
            }
            aux=aux->prox;
        }
    }
}*/
int pop(lista *l, int numero){
    if(l->inicio==NULL) {
        return 0;
    }else{
        registro *aux=NULL, *ant=NULL;
        aux=l->inicio;
        while(aux !=NULL){
            if(aux->valor==numero){
                if(ant == NULL){
                    l->inicio = aux->prox;
                }else{
                    ant->prox=aux->prox;
                }
                free(aux);
                l->qtd--;
                return 1;
            }
            ant =aux;
            aux =aux->prox;
        }
    }
}
int empty(lista *l){
    if(l->qtd==0){
        return 0;
    }else{
        return 1;
    }
}

int stackpop(lista *l){
    if(empty(l)){
        return 0;
    }else{
        return l->inicio->valor;
    }
}

void menu(lista *l){
    int opcao;
    int numero;
    do{
        printf("\n 01 - Incluir na fila.");
        printf("\n 02 - Mostrar inicio.");
        printf("\n 03 - Remover numero na fila.");
        printf("\n 10 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("\n Digite um numero:");
                scanf("%d", &numero);
                push(l, numero);
                break;
            case 2:
                stackpop(l);
                printf("%d", l->inicio->valor);
                break;
            case 3:
                printf("\n Digite um numero: ");
                scanf("%d",&numero);
                if (pop(l, numero))
                {
                    printf("\n Numero removido ");
                }
                else
                {
                    printf("\n Numero nao removido ou pilha vazia");
                }
                break;
            case 10:
                printf("\n Saindo do programa");
                break;
            default:
                printf("\n Opcao invalida");
                break;
        }

    } while (opcao != 10);
}
int main(){
    lista *l1;
    l1=aloca_lista();
    menu(l1);
    return 0;
}
