#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/*----------------------------------------COMUMENTE UTILIZADOS----------------------------------------*/



void trocaChvL(tipoLD * no1, tipoLD * no2)
{
    assert(no1);
    assert(no2);

    tipoChave aux = no1 -> chave;

    no1 -> chave = no2 -> chave;

    no2 -> chave = aux;

    return;
}

tipoLS * criaNoLS()
{
    return (tipoLS *) malloc(sizeof(tipoLS *));
}

tipoLS * criaNoLD()
{
    return (tipoLD *) malloc(sizeof(tipoLD *));
}

/*----------------------------------------LISTA SIMPLESMENTE ENCADEADA COM CABEÇA----------------------------------------*/

 tipoLS * criaLScc()
 {
    tipoLS * ptr;

    ptr = criaNoLS();
    if(!ptr) return NULL;              // Verifica se malloc retornou NULL, se sim, então criaLScc retorna NULL

    ptr -> chave = -1;                        // Inicializa o nó cabeça
    ptr -> prox = NULL;

    return ptr;
 }



 tipoLS * insereIniLScc(tipoLS *cabeca, tipoChave chave)
 {
    assert(cabeca);

    tipoLS * ptr;

    ptr = criaNoLS();
    if(!ptr) return NULL;

    ptr -> chave = chave;
    ptr -> prox = cabeca -> prox;
    cabeca -> prox = ptr;

    return ptr;
 }




 tipoLS * insereFimLScc(tipoLS *cabeca, tipoChave chave)
 {
    assert(cabeca);
    
    tipoLS * ptr, * ult = cabeca;

    ptr = criaNoLS();
    if(!ptr) return NULL;

    while(ult -> prox)
    {
        ult = ult -> prox;
    }

    ptr -> chave = chave;
    ptr -> prox = ult -> prox;
    ult -> prox = ptr;

    return ptr;
 }


 tipoLS * insereDepoisLScc(tipoLS *cabeca, tipoChave chave, tipoChave ref)
 {
    assert(cabeca);

    tipoLS * ptr, * ptrRef;

    ptr = criaNoLS();
    if(!ptr) return NULL;

    ptrRef = pesquisaNoLScc(cabeca, ref);
    if(!ptrRef) return NULL;

    ptr -> chave = chave;
    ptr -> prox = ptrRef -> prox;
    ptrRef -> prox = ptr;

    return ptr;
 }

//CUIDAR COM A INSERSÃO ANTES DO CABECA!!!!!!!!!!!!!!!!!!!!!!!!1 ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
 tipoLS * insereAntesLScc(tipoLS *cabeca, tipoChave chave, tipoChave ref)
 {
    assert(cabeca);

    tipoLS * ptr, * antRef;

    ptr = criaNoLS();
    if(!ptr) return NULL;

    antRef = pesquisaPtrNoLScc(cabeca, ref);
    if(!antRef) return NULL;

    ptr -> chave = chave;
    ptr -> prox = antRef -> prox;
    antRef -> prox = ptr;

    return ptr;
 }



void removeIniLScc(tipoLS *cabeca)
{
    assert(cabeca);

    tipoLS * aux;

    aux = (cabeca -> prox) -> prox;

    free(cabeca -> prox);
    cabeca -> prox = aux;
    return;
}

void removeFimLScc(tipoLS *cabeca)
{
    assert(cabeca);

    tipoLS * ult = cabeca;

    while((ult -> prox) -> prox)
    {
        ult = ult -> prox;
    }

    free(ult -> prox);
    ult -> prox = NULL;

    return;
}

void removeNoLScc(tipoLS *cabeca, tipoChave chave)
{
    assert(cabeca);

    tipoLS * ant, * aux;
    ant = pesquisaPtrNoLScc(cabeca, chave);
    if(!ant) return;

    aux = (ant -> prox) -> prox;
    free(ant -> prox);
    ant -> prox = aux;

    return;
}

void removeLScc(tipoLS *cabeca)
{
    assert(cabeca);

    tipoLS * aux, * no;

    no = cabeca -> prox;

    while(no)
    {
        aux = no -> prox;

        free(no);
        no = aux;
    }

    return;
}


//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
tipoLS * pesquisaNoLScc(tipoLS *cabeca, tipoChave chave)
{
    assert(cabeca);

    cabeca = cabeca ->prox;

    while(cabeca)
    {
        if(cabeca -> chave == chave)
        {
            break;
        }
        cabeca = cabeca -> prox;

    }

    return cabeca;
}

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO  com o CABECA

tipoLS * pesquisaPtrNoLScc(tipoLS *cabeca, tipoChave chave)
{
    assert(cabeca);

	cabeca = cabeca -> prox;

	while(cabeca)
	{
		if((cabeca -> prox) -> chave == chave)
			break;

		cabeca = cabeca -> prox;
	}

	return cabeca;
}


//FUNCIONA APENAS COM TIPOCHAVE = INT
void imprimeLScc(tipoLS *cabeca)
{
    assert(cabeca);

	cabeca = cabeca -> prox;
	while(cabeca)
	{
		printf("%d", cabeca -> chave );

		if(!cabeca -> prox)
			printf(".\n");
		else
			printf(", ");

		cabeca = cabeca -> prox;
	}
	return;
}

void imprimeInversoLScc(tipoLS *cabeca)
{
    assert(cabeca);

	int i = 0, j = 0;
	tipoLS * aux = cabeca;

	while(cabeca)
	{
		i++;
		cabeca = cabeca -> prox;
	}


	for(--i; i; i--)
	{
		cabeca = aux;
		j = 0;
		for(j = 0; j < i; j++)
		{
			cabeca = cabeca -> prox;
		}

		printf("%d", cabeca -> chave);

		if(0 == i-1)
			printf(".\n");
		else
			printf(", ");
	}

	return;
}



/*----------------------------------------LISTA SIMPLESMENTE ENCADEADA SEM CABEÇA----------------------------------------*/


tipoLS * criaLSsc()
{
    return NULL;
}



tipoLS * insereIniLSsc(tipoLS ** list, tipoChave chave)
{
    assert(list);
    assert(*list);


    tipoLS * ptr = criaNoLS();
    if(!ptr) return NULL;


    ptr -> prox = *list;
    *list = ptr;

    return ptr;
}

tipoLS * insereFimLSsc(tipoLS * list, tipoChave chave)
{
    assert(list);

    ptr = criaNoLS();
    if(!ptr) return NULL;
// FAZER IF PARA LIST == NULL


    while(list -> prox)
    {
        list = list -> prox;
    }

    list -> prox

}

tipoLS * insereDepoisLSsc(tipoLS * list, tipoChave chave);

tipoLS * insereAntesLSsc(tipoLS * list, tipoChave chave);



void removeIniLSsc(tipoLS ** list);

void removeFimLSsc(tipoLS * list);

void removeNoLSsc(tipoLS ** list, tipoChave chave);

void removeLSsc(tipoLS ** list);



tipoLS * pesquisaNoLSsc(tipoLS * list, tipoChave chave);

tipoLS * pesquisaPtrNoLSsc(tipoLS * list, tipoChave chave);


tipoLS * imprimeLSsc(tipoLS * list);

tipoLS * imprimeInversoLSsc(tipoLS * list);














/*----------------------------------------LISTA DUPLAMENTE ENCADEADA COM CABEÇA----------------------------------------*/

/*----------------------------------------LISTA DUPLAMENTE ENCADEADA SEM CABEÇA----------------------------------------*/

/*----------------------------------------LISTA CIRCULAR SIMPLESMENTE ENCADEADA COM CABEÇA----------------------------------------*/

/*----------------------------------------LISTA CIRCULAR SIMPLESMENTE ENCADEADA SEM CABEÇA----------------------------------------*/

/*----------------------------------------LISTA CIRCULAR DUPLAMENTE ENCADEADA COM CABEÇA----------------------------------------*/

/*----------------------------------------LISTA CIRCULAR DUPLAMENTE ENCADEADA SEM CABEÇA----------------------------------------*/



































































































/*----------------------------------------LISTA DUPLAMENTE ENCADEADA COM CABEÇA----------------------------------------

tipoLDcc * criaLDcc()
{
    tipoLDcc * p;
    p = (tipoLDcc *) malloc(sizeof(tipoLDcc));
    if (p == NULL) return NULL;

    p -> chave = -1;
    p -> prox = NULL;
    p -> ant = p;

    return p;
}



tipoLDcc * insereIniLDcc(tipoLDcc *cabeca, int chave)
{

    assert (cabeca);

    tipoLDcc * aux, * p = (tipoLDcc *) malloc(sizeof(tipoLDcc));
    if (!p) return NULL;


    p -> chave = chave;
    p -> prox = cabeca -> prox;
    p -> ant = cabeca;

    if(cabeca -> prox != NULL)
        cabeca -> prox -> ant = p;

    cabeca -> prox = p;

    return p;
}


void removeIniLDcc(tipoLDcc *cabeca)
{
    assert (cabeca);
    if (cabeca -> prox == NULL) return;

    tipoLDcc * aux = cabeca -> prox -> prox;

    free (cabeca -> prox);

    cabeca -> prox = aux;
    cabeca -> prox -> ant = cabeca;

    return;
}

void imprimeLDcc (tipoLDcc * cabeca)
{
    assert (cabeca);
    tipoLDcc * p = cabeca -> prox;

    while(1)
    {
        printf("%d ", p -> chave);

        p = p -> prox;

        if (p == NULL)
        {
            printf("\n");
            return;
        }
    }
}

void imprimeInversoLDcc (tipoLDcc * cabeca)
{
    assert (cabeca);
    tipoLDcc * p = cabeca;

    while(p -> prox != NULL)
    {
        p = p -> prox;
    }


    while(1)
    {
        printf("%d ", p -> chave);

        p = p -> ant;

        if (p == cabeca)
        {
            printf("\n");
            return;
        }
    }
}









*----------------------------------------LISTA CIRCULAR SIMPLES COM CABEÇA----------------------------------------*


tipoLScc * criaLCScc()
{

    tipoLScc * p;
    p = (tipoLScc *) malloc(sizeof(tipoLScc));
    if (p == NULL) return NULL;

    p -> chave = -1;
    p -> prox = p;

    return p;

}



tipoLScc *insereIniLCScc(tipoLScc **ult, int chave)
{

    assert(ult);
    assert(*ult);

    tipoLScc * cabeca = (*ult) -> prox;

    tipoLScc * aux, * p = (tipoLScc *) malloc(sizeof(tipoLScc));
    if (!p) return NULL;

    if ( cabeca -> prox == cabeca)
    {

        cabeca -> prox = p;
        p -> chave = chave;
        p -> prox = cabeca;

        (*ult) = p;

        return p;
    }


    aux = cabeca -> prox;
    cabeca -> prox = p;
    p -> chave = chave;
    p -> prox = aux;

    return p;
}


void removeIniLCScc(tipoLScc **ult)
{
    assert(ult);
    assert(*ult);
    tipoLScc * cabeca = (*ult) -> prox;

    if (cabeca -> prox == cabeca) return;

    tipoLScc * aux = cabeca -> prox;

    free (cabeca);

    cabeca -> prox = aux;

    return;
}

void imprimeLCScc (tipoLScc * ult)
{
    assert (ult);
    tipoLScc * p = ult -> prox -> prox;

    while(1)
    {
        printf("%d ", p -> chave);

        p = p -> prox;
        if (p == ult -> prox)
        {
            printf("\n");
            return;

        }
        getchar();
    }
}















*----------------------------------------LISTA CIRCULAR DUPLAMENTE ENCADEADA SEM CABEÇA----------------------------------------*


tipoLDsc * criaLCDsc()
{
    tipoLDsc * p = NULL;


    return p;
}



tipoLDsc *insereIniLCDsc(tipoLDsc **ult, int chave)
{


    assert(ult);

    tipoLDsc * aux, * p = (tipoLDsc *) malloc(sizeof(tipoLDsc));
    if (!p) return NULL;

    if (!(*ult))
    {

        (*ult) = p;

        (*ult) -> chave = chave;
        (*ult) -> prox = p;
        (*ult) -> ant = (*ult);

        return p;
    }

    p -> chave = chave;
    p -> prox = (*ult) -> prox;
    p -> ant = (*ult);
    (*ult) -> prox -> ant = p;

    (*ult) -> prox = p;

    return p;
}


void removeIniLCDsc(tipoLDsc **ult)
{
    if ((*ult) -> prox == NULL) return;

    tipoLDsc * aux = (*ult) -> prox -> prox;

    free ((*ult) -> prox);

    (*ult) -> prox = aux;
    (*ult) -> prox -> ant = (*ult);

    return;
}

void imprimeLCDsc (tipoLDsc * ult)
{
    assert (ult);
    tipoLDsc * p = ult -> prox;

    while(1)
    {
        printf("%d ", p -> chave);

        if (p == ult)
        {
            printf("\n");
            return;
        }
        p = p -> prox;
    }
}

void imprimeInversoLCDsc (tipoLDsc * ult)
{
    assert (ult);
    tipoLDsc * p = ult;

    while(1)
    {
        printf("%d ", p -> chave);

        if (p -> ant == ult)
        {
            printf("\n");
            return;
        }
        p = p -> ant;
    }
}
*/
