#include <assert.h>
#include <stdlib.h>
#include "vetores.h"



void borbulhaMaior(TipoVetor v[], unsigned int n)
{
	assert(v);
    if(!n)
      return;

    int i;
    TipoChave aux;

    for (i = 0; i+1 < n; ++i)
    {
        if(v[i].chave > v[i+1].chave )
        {
            aux = v[i].chave;
            v[i].chave = v[i+1].chave;
            v[i+1].chave = aux;
        }
    }

    return;
}



void borbulhaMenor(TipoVetor v[], unsigned int n)
{
	assert(v);
    if(!n)
      return;

    int i;
    TipoChave aux;

    for (i = n-2; i > -1; --i)
    {
        if(v[i].chave > v[i+1].chave )
        {
            aux = v[i].chave;
            v[i].chave = v[i+1].chave;
            v[i+1].chave = aux;
        }
    }

    return;
}









void selecao(TipoVetor v[], unsigned int n)
{

    assert(v);
    if(!n)
        return;

    int i = 0;
    TipoVetor * menor = &v[i];
    TipoChave aux;

    do
    {
        if(v[i].chave < menor -> chave)
            menor = &v[i];


        ++i;

    } while(i < n);

    aux = menor -> chave;
    menor -> chave = v[0].chave;
    v[0].chave = aux;

    return;

}



void selecaoMaior(TipoVetor v[], unsigned int n)
{

    assert(v);
    if(!n)
        return;

    int i = 0;
    TipoVetor * maior = &v[i];
    TipoChave aux;

    do
    {
        if(v[i].chave > maior -> chave)
            maior = &v[i];

        ++i;

    } while(i < n);

    aux = maior -> chave;
    maior -> chave = v[n-1].chave;
    v[n-1].chave = aux;

    return;

}









void insercao(TipoVetor v[], int i, unsigned int n)
{
    assert(v);
    if(!n) return;

    int j;
    TipoChave aux = v[i].chave;


    for(j = i-1; j > -1; --j)
    {
        if(v[j].chave < aux)
        {
            break;
        }
    }

    j++;
    for (; i > j; --i)
    {
        v[i].chave = v[i-1].chave;
    }

    v[j].chave = aux;

    return;
}




void insercaoFim(TipoVetor v[], int i, unsigned int n)
{
    assert(v);
    if(!n) return;

    int j;
    TipoChave aux = v[i].chave;


    for(j = i+1; j < n; ++j)
    {
        if(v[j].chave > aux)
            break;

    }

    j--;
    for (; i < j; ++i)
    {
        v[i].chave = v[i+1].chave;
    }

    v[j].chave = aux;

    return;
}




void insercaoDecrescente(TipoVetor v[], int i, unsigned int n)
{
    assert(v);
    if(!n) return;

    int j;
    TipoChave aux = v[i].chave;


    for(j = i-1; j > -1; --j)
    {
        if(v[j].chave > aux)
            break;

    }

    j++;
    for (; i > j; --i)
    {
        v[i].chave = v[i-1].chave;
    }

    v[j].chave = aux;

    return;
}




void insercaoDecrescenteFim(TipoVetor v[], int i, unsigned int n)
{
    assert(v);
    if(!n) return;

    int j;
    TipoChave aux = v[i].chave;


    for(j = i+1; j < n; ++j)
    {
        if(v[j].chave < aux)
            break;

    }

    j--;
    for (; i < j; ++i)
    {
        v[i].chave = v[i+1].chave;
    }

    v[j].chave = aux;

    return;
}









int particao(TipoVetor v[], int ini, int fim)
{
    int pivot = ini;
    int i = ini+1;
    int j = fim;

    while(i <= j)
    {
        if(v[i].chave <= v[pivot].chave)
            i++;
        else
            if(v[j].chave > v[pivot].chave)
                j--;

            else
            {
                trocaVetor(v, i, j);
                i++;
                j--;
            }

//        imprimeVetor(v, ini, fim);
  //      printf("i = %d, j = %d\n", i, j );
    }

    trocaVetor(v, pivot, j);
   
    return j;
}

int particaoAleatorio(TipoVetor v[], int ini, int fim)
{
    int pivot = rand() % (fim-ini+1) + ini;

	trocaVetor(v, ini, pivot);
	pivot = ini;
    int i = ini+1;
    int j = fim;

    while(i <= j)
    {

        if(v[i].chave <= v[pivot].chave)
            i++;
        else
            if(v[j].chave > v[pivot].chave)
                j--;

            else
            {
                trocaVetor(v, i, j);
                i++;
                j--;
            }

    }

    trocaVetor(v, pivot, j);

    return j;
}









void intercalacao(TipoVetor v[], int ini, int meio, int fim, TipoVetor aux[])
{
	assert(v);
	assert(aux);

	int i, j = ini;

	for(i = ini; i < fim+2; i++)
	{
		if(i == meio+1)
			continue;

		aux[i].chave = v[j].chave;
		j++;
	}

	aux[meio+1].chave = 9999999;
	aux[fim+2].chave = 9999999;

//puts("aux");
//	imprimeVetor(v, ini, fim);
//	imprimeVetor(aux, ini, fim+2);

	j = meio+2;
	i = ini;
	int k = ini;
//puts("dentro do for");
	while( k < fim+1)
	{
		if(aux[i].chave <= aux[j].chave)
		{
			v[k].chave = aux[i].chave;
			i++;
		}
		else
		{
			v[k].chave = aux[j].chave;
			j++;
		}
		k++;

//		imprimeVetor(v, ini, fim);
//		imprimeVetor(aux, ini, fim+2);

	}


	return;
}









void bubbleSort(TipoVetor v[], unsigned int n) /*usando borbulharMaior*/
 {
     assert(v);
    if(n == 0)
      return;

    int i;
    TipoChave aux;

    for (i = 0; i+1 < n; ++i)
    {
        if(v[i].chave > v[i+1].chave )
        {
            aux = v[i].chave;
            v[i].chave = v[i+1].chave;
            v[i+1].chave = aux;
        }
    }

    bubbleSort(v, n-1);
    return;
}


void selectionSort(TipoVetor v[], unsigned int n) /*usando selecao*/
{
    assert(v);

    if(!n)
        return;

    int i = 0;
    TipoVetor * menor = &v[i];
    TipoChave aux;

    do
    {
        if(v[i].chave < menor -> chave)
            menor = &v[i];


        ++i;

    } while(i < n);

    aux = menor -> chave;
    menor -> chave = v[0].chave;
    v[0].chave = aux;

    return;

    if(n > 1)
        selectionSort(&v[1], n-1);
    return;

}
void insertionSort(TipoVetor v[], unsigned int n)/*usando insercao*/
{

    assert(v);
    if(!n) return;

    if(n>1)
    insertionSort(v, n-1 );


    int j, i = n-1;
    TipoChave aux;


    aux = v[i].chave;
    for(j = i-1; j > -1; --j)
    {
        if(v[j].chave < aux)
        {
            break;
        }
        }

    j++;
    for (; i > j; --i)
    {
        v[i].chave = v[i-1].chave;
    }

        v[j].chave = aux;


    return;

}


//
void quickSort(TipoVetor v[], int ini, int fim)
{
    assert(v);
    if(ini < fim)
    {
        int pivot = particao(v, ini, fim);

        quickSort(v, ini, pivot-1);
        quickSort(v, pivot+1, fim);
    }

    return;
}



void quickSortAleatorio(TipoVetor v[], int ini, int fim)
{
    assert(v);
    if(ini < fim)
    {
        int pivot = particaoAleatorio(v, ini, fim);

        quickSort(v, ini, pivot-1);
        quickSort(v, pivot+1, fim);
    }

    return;
}



void mergeSort(TipoVetor v[], int ini, int fim);

void merge(TipoVetor v[], int ini, int fim, TipoVetor aux[])
{
	assert(v);
	assert(aux);

	if( ini < fim)
	{
		int meio = (ini+fim)/2;

		merge(v, ini, meio, aux);
		merge(v, meio+1, fim, aux);

		intercalacao(v, ini, meio, fim, aux);
	}



	return;
}



void mergeSort(TipoVetor v[], int ini, int fim)
{
	assert(v);

	TipoVetor *p = alocaVetor(fim-ini+3);
	inicializaVetor(p, ini, fim+2);
//	puts("teste");
//	imprimeVetor(p, ini, fim+2);
	merge(v, ini, fim, p);

	return;
}
