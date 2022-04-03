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
void adicionar(lista *l,int numero){
    registro *novo;
    novo=aloca_registro();
    novo->valor =numero;
    if(l->inicio==NULL){
        l->inicio =novo;
    }else{
        novo->prox =l->inicio;
        l->inicio = novo;
    }
    l->qtd++;
}
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
}
int buscar(lista *l,int numero){
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
}
int remover(lista *l,int numero){
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

void menu(lista *l){
    int opcao;
    int numero;
    do{
        printf("\n 01 - Incluir no inicio");
        printf("\n 02 - Mostrar lista");
        printf("\n 03 - Buscar numero");
        printf("\n 04 - Remover numero");
        printf("\n 10 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("\n Digite um numero:");
                scanf("%d", &numero);
                adicionar(l, numero);
                break;
            case 2:
                mostrar_lista(l);
                break;
            case 3:
                printf("\n Digite um numero: ");
                scanf("%d", &numero);

                if (buscar(l, numero))
                {
                    printf("\n Numero encontrado");
                }
                else
                {
                    printf("\n Numero nao esta na lista");
                }
                break;
            case 4:
                printf("\n Digite um numero: ");
                scanf("%d",&numero);
                if (remover(l,numero))
                {
                    printf("\n Numero removido ");
                }
                else
                {
                    printf("\n Numero nao removido ou lista vazia");
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

