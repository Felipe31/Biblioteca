#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/*----------------------------------------COMUMENTE UTILIZADOS----------------------------------------*/



void trocaChvL(TipoLD * no1, TipoLD * no2)
{
    assert(no1);
    assert(no2);

    TipoChave aux = no1 -> chave;

    no1 -> chave = no2 -> chave;

    no2 -> chave = aux;

    return;
}

TipoLS * criaNoLS()
{
    return (TipoLS *) malloc(sizeof(TipoLS));
}

TipoLS * criaNoLD()
{
    return (TipoLD *) malloc(sizeof(TipoLD));
}

/*----------------------------------------LISTA SIMPLESMENTE ENCADEADA COM CABEÇA----------------------------------------*/

 TipoLS * criaLScc()
 {
    TipoLS * ptr;

    ptr = criaNoLS();
    if(!ptr) return NULL;              // Verifica se malloc retornou NULL, se sim, então criaLScc retorna NULL

    ptr -> chave = -1;                        // Inicializa o nó cabeça
    ptr -> prox = NULL;

    return ptr;
 }



 TipoLS * insereIniLScc(TipoLS *cabeca, TipoChave chave)
 {
    assert(cabeca);

    TipoLS * ptr;

    ptr = criaNoLS();
    if(!ptr) return NULL;

    ptr -> chave = chave;
    ptr -> prox = cabeca -> prox;
    cabeca -> prox = ptr;

    return ptr;
 }




 TipoLS * insereFimLScc(TipoLS *cabeca, TipoChave chave)
 {
    assert(cabeca);

    TipoLS * ptr, * ult = cabeca;

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


 TipoLS * insereDepoisLScc(TipoLS *cabeca, TipoChave chave, TipoChave ref)
 {
    assert(cabeca);

    TipoLS * ptr, * ptrRef;

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
 TipoLS * insereAntesLScc(TipoLS *cabeca, TipoChave chave, TipoChave ref)
 {
    assert(cabeca);

    TipoLS * ptr, * antRef;

    ptr = criaNoLS();
    if(!ptr) return NULL;

    antRef = pesquisaPtrNoLScc(cabeca, ref);
    if(!antRef) return NULL;

    ptr -> chave = chave;
    ptr -> prox = antRef -> prox;
    antRef -> prox = ptr;

    return ptr;
 }



void removeIniLScc(TipoLS *cabeca)
{
    assert(cabeca);

    TipoLS * aux;

    aux = (cabeca -> prox) -> prox;

    free(cabeca -> prox);
    cabeca -> prox = aux;
    return;
}

void removeFimLScc(TipoLS *cabeca)
{
    assert(cabeca);

    TipoLS * ult = cabeca;

    while((ult -> prox) -> prox)
    {
        ult = ult -> prox;
    }

    free(ult -> prox);
    ult -> prox = NULL;

    return;
}

void removeNoLScc(TipoLS *cabeca, TipoChave chave)
{
    assert(cabeca);

    TipoLS * ant, * aux;
    ant = pesquisaPtrNoLScc(cabeca, chave);
    if(!ant) return;

    aux = (ant -> prox) -> prox;
    free(ant -> prox);
    ant -> prox = aux;

    return;
}

void removeLScc(TipoLS *cabeca)
{
    assert(cabeca);

    TipoLS * aux, * no;

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
TipoLS * pesquisaNoLScc(TipoLS *cabeca, TipoChave chave)
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

TipoLS * pesquisaPtrNoLScc(TipoLS *cabeca, TipoChave chave)
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
void imprimeLScc(TipoLS *cabeca)
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

void imprimeInversoLScc(TipoLS *cabeca)
{
    assert(cabeca);

	int i = 0, j = 0;
	TipoLS * aux = cabeca;

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


TipoLS * criaLSsc()
{
    return NULL;
}



TipoLS * insereIniLSsc(TipoLS ** list, TipoChave chave)
{
    assert(list);


    TipoLS * ptr = criaNoLS();
    if(!ptr) return NULL;

    ptr -> prox = *list

    *list = ptr;

    return ptr;
}

TipoLS * insereFimLSsc(TipoLS ** list, TipoChave chave)
{
    assert(list);

    TipoLS * ptr = criaNoLS();
    if(!ptr) return NULL;

    ptr -> chave = chave;
    ptr -> prox = NULL;


    if(!(*list))
    {
        return (*list) = ptr;
    }

    TipoLS * no = *list;

    while(no -> prox)
    {
    no = no -> prox;
    }

    no -> prox = ptr;

    return ptr;
}

TipoLS * insereDepoisLSsc(TipoLS * list, TipoChave chave, TipoChave ref)
{
    assert(list);
    assert(*list);

    TipoLS * ptr = criaNoLS();
    if(!ptr) return NULL;

    ptr -> chave = chave;



    while(list -> chave != ref)
    {
        if(!(list -> prox))
            return NULL;

        list = list -> prox;
    }

    ptr -> prox = list -> prox;
    list -> prox = ptr;


    return ptr;
}

TipoLS * insereAntesLSsc(TipoLS * list, TipoChave chave, TipoChave ref)
{
    assert(list);
    assert(*list);

    TipoLS * ptr = criaNoLS();
    if(!ptr) return NULL;


    while((list -> prox) -> chave != ref)
    {
        if(!(list -> prox))
            return NULL;

        list = list -> prox;
    }

    ptr -> chave = chave;
    ptr -> prox = list -> prox;

    list -> prox = ptr;

    return ptr;

}


void removeIniLSsc(TipoLS ** list)
{
    assert(list);
    assert(*list);

    TipoLS ptr = (*list) -> prox;

    free(*list);

    *list = ptr;

}

void removeFimLSsc(TipoLS * list);

void removeNoLSsc(TipoLS ** list, TipoChave chave);

void removeLSsc(TipoLS ** list);



TipoLS * pesquisaNoLSsc(TipoLS * list, TipoChave chave);

TipoLS * pesquisaPtrNoLSsc(TipoLS * list, TipoChave chave);


TipoLS * imprimeLSsc(TipoLS * list);

TipoLS * imprimeInversoLSsc(TipoLS * list);














/*----------------------------------------LISTA DUPLAMENTE ENCADEADA COM CABEÇA----------------------------------------*/

/*----------------------------------------LISTA DUPLAMENTE ENCADEADA SEM CABEÇA----------------------------------------*/

/*----------------------------------------LISTA CIRCULAR SIMPLESMENTE ENCADEADA COM CABEÇA----------------------------------------*/

/*----------------------------------------LISTA CIRCULAR SIMPLESMENTE ENCADEADA SEM CABEÇA----------------------------------------*/

/*----------------------------------------LISTA CIRCULAR DUPLAMENTE ENCADEADA COM CABEÇA----------------------------------------*/

/*----------------------------------------LISTA CIRCULAR DUPLAMENTE ENCADEADA SEM CABEÇA----------------------------------------*/



































































































/*----------------------------------------LISTA DUPLAMENTE ENCADEADA COM CABEÇA----------------------------------------

TipoLDcc * criaLDcc()
{
    TipoLDcc * p;
    p = (TipoLDcc *) malloc(sizeof(TipoLDcc));
    if (p == NULL) return NULL;

    p -> chave = -1;
    p -> prox = NULL;
    p -> ant = p;

    return p;
}



TipoLDcc * insereIniLDcc(TipoLDcc *cabeca, int chave)
{

    assert (cabeca);

    TipoLDcc * aux, * p = (TipoLDcc *) malloc(sizeof(TipoLDcc));
    if (!p) return NULL;


    p -> chave = chave;
    p -> prox = cabeca -> prox;
    p -> ant = cabeca;

    if(cabeca -> prox != NULL)
        cabeca -> prox -> ant = p;

    cabeca -> prox = p;

    return p;
}


void removeIniLDcc(TipoLDcc *cabeca)
{
    assert (cabeca);
    if (cabeca -> prox == NULL) return;

    TipoLDcc * aux = cabeca -> prox -> prox;

    free (cabeca -> prox);

    cabeca -> prox = aux;
    cabeca -> prox -> ant = cabeca;

    return;
}

void imprimeLDcc (TipoLDcc * cabeca)
{
    assert (cabeca);
    TipoLDcc * p = cabeca -> prox;

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

void imprimeInversoLDcc (TipoLDcc * cabeca)
{
    assert (cabeca);
    TipoLDcc * p = cabeca;

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


TipoLScc * criaLCScc()
{

    TipoLScc * p;
    p = (TipoLScc *) malloc(sizeof(TipoLScc));
    if (p == NULL) return NULL;

    p -> chave = -1;
    p -> prox = p;

    return p;

}



TipoLScc *insereIniLCScc(TipoLScc **ult, int chave)
{

    assert(ult);
    assert(*ult);

    TipoLScc * cabeca = (*ult) -> prox;

    TipoLScc * aux, * p = (TipoLScc *) malloc(sizeof(TipoLScc));
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


void removeIniLCScc(TipoLScc **ult)
{
    assert(ult);
    assert(*ult);
    TipoLScc * cabeca = (*ult) -> prox;

    if (cabeca -> prox == cabeca) return;

    TipoLScc * aux = cabeca -> prox;

    free (cabeca);

    cabeca -> prox = aux;

    return;
}

void imprimeLCScc (TipoLScc * ult)
{
    assert (ult);
    TipoLScc * p = ult -> prox -> prox;

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


TipoLDsc * criaLCDsc()
{
    TipoLDsc * p = NULL;


    return p;
}



TipoLDsc *insereIniLCDsc(TipoLDsc **ult, int chave)
{


    assert(ult);

    TipoLDsc * aux, * p = (TipoLDsc *) malloc(sizeof(TipoLDsc));
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


void removeIniLCDsc(TipoLDsc **ult)
{
    if ((*ult) -> prox == NULL) return;

    TipoLDsc * aux = (*ult) -> prox -> prox;

    free ((*ult) -> prox);

    (*ult) -> prox = aux;
    (*ult) -> prox -> ant = (*ult);

    return;
}

void imprimeLCDsc (TipoLDsc * ult)
{
    assert (ult);
    TipoLDsc * p = ult -> prox;

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

void imprimeInversoLCDsc (TipoLDsc * ult)
{
    assert (ult);
    TipoLDsc * p = ult;

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
