#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NO{
    int dado;
    struct NO * prox;
}NO;
typedef struct pilha{
    NO *topo;
}pilha;
int QDesempilha;

int iniciar(pilha *p){
    p->topo = NULL;
}

void empilhar(pilha *p, int c){
    NO * aux;
    aux = (NO *) malloc(sizeof(NO));

    aux->prox = p->topo;
    p->topo = aux;
    aux->dado = c;
}
void transloc(pilha *p){
    NO *aux;
    NO * inicio;
    aux = p->topo;
    inicio = p->topo;
    if(inicio->prox){
        while(inicio->prox)
            inicio = inicio ->prox;
        p->topo = p->topo->prox;
        aux->prox = inicio->prox;
        inicio->prox = aux;
    }
}

void tirar(pilha* p, int * desempilha){
    NO *aux;
    if(aux){
        if(!p->topo->prox)
        return;
        do{
            aux = p->topo;
            desempilha[QDesempilha++] = aux->dado;
            p->topo = p->topo->prox;
            free(aux);
            transloc(p);
        }while(p->topo->prox);
    }
}
 void sumidao(pilha *p)
{
	NO *aux;

	aux = p->topo;
	p->topo = NULL;
	free(aux);
}


void main ()
{

	int carta;
	pilha p;
 	int i;
    int x;
	do
	{

		scanf("%d", &carta);

		if ( carta > 50)
			return;

		iniciar(&p);
		int desempilha[carta];

		for (i = carta; i > 0; i--)
			empilhar(&p, i);

		QDesempilha = 0;
		tirar(&p, desempilha);

		printf("Discarded cards:");
		for (i = 0; i < QDesempilha; i++)
		{

			printf(" %d", desempilha[i]);
			if (i != QDesempilha - 1)
				printf(",");

		}

		printf("\nRemaining card: %d\n", p.topo->dado);
        x++;

	}while(x<5);
    sumidao(&p);


}
