/*
1) Utilizando como base o programa lista_ligada.c, construa um programa que disponibilize ao usuario as seguintes opcoes
    a) Incluir na lista: O usuário irá informar um número que será incluído na lista
    b) Mostrar lista: deverá ser mostrado na tela a lista completa.
    c) Mostrar pares da lista: deverá ser mostrado na tela apenas os números pares
2) Faça um programa que leia do usuário 10 números inteiros e armazene os números pares em uma lista ligada
e os números ímpares em uma segunda lista ligada. Mostre o conteúdo das 2 listas;
3) Faça um programa que leia do usuário um número N inteiro positivo e solicite ao usuário N números para serem armazenados.
    a primeira metade dos N números, deverá ser armazenada em uma lista ligada e a segunda metade dos N números deverá ser 
    armazenado em uma segunda lista.
    Mostre na tela quais valores são comuns entre as 2 listas ligadas.
*/

// 1

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct registro *inicio;
}lista;

typedef struct registro{
    int valor;
    struct registro *prox;
}registro;

lista *alocalista(){
    lista *novo;
    novo = (lista *)calloc(1,sizeof(lista));
    return novo;
}
registro *alocaregistro(){
    registro *novo;
    novo=(registro *)calloc(1,sizeof(lista));
    return novo;
}


void push(lista *l, int numero){
    registro *novo, *aux;

    novo=alocaregistro();
    novo->valor = numero;
    if(l->inicio==NULL){
        l->inicio = novo;

    }else{
        aux=l->inicio;
        while(aux->prox!=NULL){
            aux = aux->prox;

        }
        aux->prox = novo;
    }
    printf("\n Numero %d adicionado com sucesso \n",numero);
    l->qtd++;
}
    void mostrar_lista(lista *l){
    registro *aux;
    if(l->inicio == NULL){
        printf("\n Lista Vazia \n");
    }else {
        printf("\n Numeros da lista: \n");
        aux = l->inicio;
        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
    }
}
    void mostrar_par(lista *l){
    registro *aux;
    if(l->inicio==NULL){
        printf("\n Lista Vazia \n");
    }else{
        printf("Numeros pares:\n");
        aux=l->inicio;
        while(aux !=NULL){
            if(aux->valor % 2 == 0){
                printf("%d ",aux->valor);
                aux=aux->prox;
            }else{
                aux = aux->prox;
            }
        }
    }
}
void menu(lista *l)
{
    int opcao, numero;

    do
    {
        printf("\n 1 - Inserir na lista");
        printf("\n 2 - Mostrar lista");
        printf("\n 3 - Mostrar pares\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("\n Digite o numero que deseja incluir na lista: ");
                scanf("%d", &numero);
                push(l,numero);
                break;
            case 2:
                mostrar_lista(l);
                break;
            case 3:
                mostrar_par(l);
                break;
            case 5:
                printf("\n Saindo do programa");
                break;
            default:
                printf("\n opcao invalida");
                break;
        }
    } while (opcao != 5);
}

int main(){
    lista *l1;
    l1=alocalista();
    menu(l1);
    printf("\n");
    return 0;
}

//2

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    struct registro *inicio;
}lista;

typedef struct registro{
    int valor;
    struct registro *prox;
}registro;

lista *alocalista(){
    lista *novo;
    novo = (lista *)calloc(1,sizeof(lista));
    return novo;
}
registro *alocaregistro(){
    registro *novo;
    novo=(registro *)calloc(1,sizeof(lista));
    return novo;
}


void push(lista *l) {
    registro *novo, *aux;
    int numero;
    for (int i = 0; i <= 10; i++) {
        novo = alocaregistro();
        printf("Digite o valor do %d elemento:",i);
        scanf("%d",&numero);
        novo->valor = numero;
        if (numero % 2 == 0) {
            if (l->inicio == NULL) {
                l->inicio = novo;
            }else {
                aux = l->inicio;
                while (aux->prox != NULL) {
                    aux = aux->prox;
                }
                aux->prox = novo;
            }
        }
    }
}
    void mostrar_lista(lista *l){
    registro *aux;
    if(l->inicio == NULL){
        printf("\n Lista Vazia \n");
    }else {
        printf("\n Numeros da lista: \n");
        aux = l->inicio;
        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
    }
}
int main(){
    lista *l1;
    l1=alocalista();
    push(l1);
    mostrar_lista(l1);
    printf("\n");
    return 0;
}

//3
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct lista{
    struct registro *inicio;
}lista;

typedef struct registro{
    int valor;
    struct registro *prox;
}registro;

lista *alocalista(){
    lista *novo;
    novo = (lista *)calloc(1,sizeof(lista));
    return novo;
}
registro *alocaregistro(){
    registro *novo;
    novo=(registro *)calloc(1,sizeof(lista));
    return novo;
}


void push(lista *l, int numero) {
    registro *novo, *aux;

    novo=alocaregistro();
    novo->valor = numero;
    if(l->inicio==NULL){
        l->inicio = novo;

    }else{
        aux=l->inicio;
        while(aux->prox!=NULL){
            aux = aux->prox;

        }
        aux->prox = novo;
    }
    printf("\n Numero %d adicionado com sucesso \n",numero);
}
    void mostrar_lista(lista *l){
    registro *aux;
    if(l->inicio == NULL){
        printf("\n Lista Vazia \n");
    }else {
        printf("\n Numeros da lista: \n");
        aux = l->inicio;
        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
    }
}

int buscar_elemento(lista *l, int x){

    if(l->inicio==NULL){
        return 0;
    }else{
        registro *aux;
        aux = l->inicio;
        while(aux!=NULL){
            if(aux->valor==x){
                return 1;
            }else{
                aux=aux->prox;
            }
        }
        return 0;
    }
}
void elementos_comum(lista *l1,lista *l2){
    if(l1->inicio==NULL || l2->inicio==NULL){
        printf("Sem valores correspondentes\n");
        return;
    }else{
        registro *aux;
        aux= l1 ->inicio;
        while(aux!=NULL){
            if(buscar_elemento(l2,aux->valor)) {
                printf("%d ", aux->valor);
            }
                aux= aux->prox;

        }
    }
}

int main(){
    lista *l1;
    l1=alocalista();
    lista *l2;
    l2=alocalista();
    int x,j,k;
    printf("Digite o tanto de numeros que deseja inserir n a lista:\n");
    scanf("%d",&x,"\n");
    if(x==1 || x==2){
        printf("Digite valores maiores");
        return 0;
    }
    int numero;

    if(x%2==0){
        printf("Lista 1:\n");
        j = x/2;
        for (int i = 0; i < j; i++) {
            printf("Digite o valor do %d elemento:",i);
            scanf("%d",&numero);
            push(l1,numero);
        }
        printf("\nLista 2:\n");
        for (int i = 0; i < j; i++) {
            printf("Digite o valor do %d elemento:",i);
            scanf("%d",&numero);
            push(l2,numero);
        }
    }

    if(x % 2!=0){
        printf("\nLista 1:\n");
        j = round(x/2);
        for (int i = 0; i < j; i++) {
            printf("Digite o valor do %d elemento:",i);
            scanf("%d",&numero);
            push(l1,numero);
        }
        printf("\nLista 2:\n");
        k=(x % 2) + round(x/2) ;
        for (int i = 0; i < k; i++) {
            printf("Digite o valor do %d elemento:",i);
            scanf("%d",&numero);
            push(l2,numero);
        }
    }
    mostrar_lista(l1);
    printf("\n");
    mostrar_lista(l2);
    printf("\n");
    printf("Numero em comum:\n");
    elementos_comum(l1,l2);
    printf("\n");
    return 0;
}

