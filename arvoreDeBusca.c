#include <stdio.h>
#include <stdlib.h>
typedef struct arvore
{
    int valor;
    struct arvore* dir;
    struct arvore* esq;
}tipoA;

void iniciar(tipoA **raiz)
{
    *raiz = NULL;
}

void inserir(tipoA **raiz, int x)
{
    tipoA *novo = (tipoA*)malloc(sizeof(tipoA));
    if(*raiz == NULL)
    {
        (*raiz) = novo;
        novo -> dir = NULL;
        novo -> esq = NULL;
        novo -> valor = x;
    }else
        {
           if(x <= (*raiz)-> valor)
           {
               inserir(&((*raiz)->esq), x);
           }
           if(x > (*raiz)-> valor)
           {
               inserir(&((*raiz)-> dir), x);
           }
        }
}
void imprimirpre(tipoA *raiz)
{
    // R-E-D
    if(raiz != NULL){
        printf("%d \n", raiz->valor);
        imprimirpre(raiz->esq);
        imprimirpre(raiz->dir);
    }
}

void imprimirpos(tipoA *raiz)
{
    //E-D-R
    if(raiz != NULL)
    {
        imprimirpos(raiz->esq);
        imprimirpos(raiz->dir);
        printf ("%d \n", raiz->valor);
    }
}

void imprimirordem(tipoA *raiz)
{
    //E-D-R
    if(raiz != NULL)
    {
        imprimirordem(raiz->esq);
        printf("%d \n", raiz -> valor);
        imprimirordem(raiz->dir);
    }
}

int busca(tipoA *raiz, int n)
{
    if(raiz != NULL)
    {
        if (raiz -> valor == n)
        {
           return 1;
        }
        busca(raiz -> esq,n);
        busca(raiz -> dir,n);
    }
}

int remover (tipoA *raiz, int v)
{
 	if (raiz == NULL) 
	 	return NULL;
	else if (raiz -> valor > v)
			raiz -> esq = remover(raiz -> esq,v);
	else if (raiz -> valor < v)
			raiz -> dir = remover(raiz -> dir,v);
	else {
		if (raiz -> esq == NULL && raiz -> dir == NULL)
		{
			free(raiz);
			raiz = NULL;
		}
		else if (raiz -> esq == NULL) 
		{
			tipoA* t = raiz;
			raiz = raiz -> dir;
			free(t);
		}
		else if (raiz -> dir == NULL)
		{
			tipoA* t = raiz;
			raiz = raiz -> esq;
			free(t);
		}
		else {
			//pegar o maior da esquerda
			tipoA* f = raiz -> esq;
			while(f -> dir != NULL)
				f = f -> dir;
			raiz -> valor = f -> valor;
			f -> valor = v;
			raiz -> esq = remover(raiz -> esq, v);
		}
	}  
	return raiz;
}
int main()
{
    int i,x,v;
    tipoA *raiz;
    iniciar(&raiz);
    for(i = 0; i < 4; i++)
    {
        printf("\n Digite um numero:\n");
        scanf("%d",&x);
        inserir(&raiz,x);
    }

   /* printf("Digite o valor:");
    scanf("%d",&n);
    if(busca(raiz,n) == 1)
    {
        printf("\n Ta na arvore!! \n");
    }else printf("\n Nao ta \n");
    */
    imprimirordem(raiz);
    printf("Digite o numero para remover:");
    scanf("%d",&v);
    remover(raiz,v);
    imprimirordem(raiz);

    return 0;
}

