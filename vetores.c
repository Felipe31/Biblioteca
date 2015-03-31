#include "vetores.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

TipoVetor *alocaVetor(int n)
{
	if (0 >= n) return NULL;

	return (TipoVetor *) malloc( sizeof(TipoVetor) * n);
}



void trocaVetor(TipoVetor v[], int i, int j)
{

	TipoChave aux = v[i].chave;

	v[i].chave = v[j].chave;
	v[j].chave = aux;

	return;
}



/*
 * Imprime todos os elementos do vetor v
 * se os parâmetros de entrada forem válidos.
 * ini indica o índice do primeiro elemento
 * fim indica o índice do último elemento
 */
void imprimeVetor(TipoVetor v[], int ini, int fim)
{
	assert(v);
	if((ini > fim) || (ini < 0) || (fim < 0))
		return;
	

	fim++;
	
	for(; ini < fim; ini++)
	{
		printf("%d ", v[ini].chave);
	}

	printf("\n");
	return;
}




/*
 * Inicializa todos os elementos do vetor v
 * com -1 se os parâmetros de entrada forem válidos.
 * ini indica o índice do primeiro elemento de v
 * fim indica o índice do último elemento de v
 */
void inicializaVetor(TipoVetor v[], int ini, int fim)
{
	assert(v);
	if((ini > fim) || (ini < 0) || (fim < 0))
		return;

	fim++;
	for(; ini < fim; ini++)
	{
		v[ini].chave = -1;
	}

	return;
}



/*
 * Inicializa todos os elementos do vetor v
 * com valores aleatórios da funcao rand se
 * os parâmetros de entrada forem válidos.
 * ini indica o índice do primeiro elemento
 * fim indica o índice do último elemento
 * maxchave indica o maior valor aleatório
 *          que pode ser atribuido a uma 
 *          posição do vetor. Assuma maxchave>=0.
 * OBS.: Não use srand
 */
void inicializaVetorAleatorio(TipoVetor v[], int ini, int fim, TipoChave maxchave)
{

	assert(v);
	if((ini > fim) || (ini < 0) || (fim < 0))
		return;

	fim++;
	for(; ini < fim; ini++)
	{
		v[ini].chave = rand() % maxchave + 1; // duvidaaaaaaa
	}

	return;
}

/*
 * Inicializa v[] com valores crescentes (a partir de zero) 
 * se os parâmetros de entrada forem válidos;
 * Ex. v[ini]=0, v[ini+1]=1, ...
 * ini indica o índice do primeiro elemento
 * fim indica o índice do último elemento
 */
void inicializaOrdenadoCrescente(TipoVetor v[], int ini, int fim)
{
	assert(v);
	if((ini > fim) || (ini < 0) || (fim < 0))
		return;
	
	int i = 0;

	fim++;
	for(; ini < fim; ini++)
	{
		v[ini].chave = i++;
	}

	return;
}


/*
 * Inicializa v[] com valores decrescentes
 * se os parâmetros de entrada forem válidos;
 * Se no vetor cabem n elementos, entao teriamos
 * Ex. v[ini]=n, v[ini+1]=n-1, ...
 * ini indica o índice do primeiro elemento
 * fim indica o índice do último elemento
 */
void inicializaOrdenadoDecrescente(TipoVetor v[], int ini, int fim)
{
	assert(v);
	if((ini > fim) || (ini < 0) || (fim < 0))
		return;
	
	int i = fim;

	fim++;
	for(; ini < fim; ini++)
	{
		v[ini].chave = i--;
	}

	return;
}


/*
 * Inicializa v[] com valores crescentes (a partir de zero) 
 * da posicão ini até a posição j-1 se os parâmetros de  
 * entrada forem válidos;
 * Ex. v[ini]=0, v[ini+1]=1, ....,
 * Da posição j ate fim, v[] deve ser inicializado
 * com valores aleatórios menores ou iguals a maxchave
 * ini indica o índice do primeiro elemento
 * fim indica o índice do último elemento
 */
void inicializaOrdenadoAleatorio(TipoVetor v[], int ini, int j, int fim, TipoChave maxchave)
{

	assert(v);
	if((ini > fim) || (ini < 0) || (fim < 0))
		return;


	int i = 0;

	for(; ini < j; ini++)
	{
		v[ini].chave = i++;
	}


	fim++;
	for(;ini < fim; ini++)
	{
		v[ini].chave = rand() % maxchave + 1;
	}

	return;
}



/*
 * Devolve 1 caso o vetor v esteja ordenado ou 0 
 * caso contrario. Se pelo menos uma das entradas
 * forem inválidas algoritmo deve devolver -1.
 * ini indica o índice do primeiro elemento
 * fim indica o índice do último elemento
 */
char estaOrdenado(TipoVetor v[], int ini, int fim)
{
	assert(v);
	if((ini > fim) || (ini < 0) || (fim < 0))
		return -1;

	TipoChave anterior = v[ini].chave;

	ini++;
	fim++;
	for(;ini < fim; ini++)
	{
		if(anterior < v[ini].chave)
			anterior = v[ini].chave;

		else
			return 0;
	}

	return 1;
}

/*
 * Copia os elementos do vetor v[] em um novo vetor
 * que deverá ser alocado com a mesma quantidade de
 * elementos de v[].
 * Devolve o ponteiro para o primeiro elemento do novo
 * vetor, ou NULL caso haja problemas de alocação ou
 * alguma das entradas sejam inválidas.
 */
TipoVetor *copiaVetor(TipoVetor v[], int ini, int fim)
{

	assert(v);
	if((ini > fim) || (ini < 0) || (fim < 0))
		return NULL;
	

	TipoVetor *v2 = alocaVetor(fim-ini+1);


	fim++;
	for(; ini < fim; ini++)
	{
		v2[ini].chave = v[ini].chave;
	}


	return v2;
}

/*
 * Devolve 1 se os parâmetros de entrada forêm válidos e
 * os vetores v1[] e v2[] forem iguais, isto é,
 * têm a mesma quantidade de elementos e satisfaz:
 * v1[i] == v2[i] para todo i válido. Devolve 0 caso os vetores
 * sejam diferentes.
 * ini1 indica o índice do primeiro elemento de v1[]
 * fim1 indica o índice do último elemento de v1[]
 * ini2 indica o índice do primeiro elemento de v2[]
 * fim2 indica o índice do último elemento de v2[]
 */
char comparaVetores(TipoVetor v1[], int ini1, int fim1, TipoVetor v2[], int ini2, int fim2)
{
	assert(v1);
	if((ini1 > fim1) || (ini1 < 0) || (fim1 < 0))
		return 0;

	assert(v2);
	if((ini2 > fim2) || (ini2 < 0) || (fim2 < 0))
		return 0;
	
	if((fim1 - ini1 + 1) != (fim2 - ini2 + 1) )
		return 0;

	fim1++;
	while(ini1 < fim1)
	{
		if(v1[ini1].chave != v2[ini2].chave)
			return 0;

		ini1++;
		ini2++;
	}

	return 1;
}

/*
 * Libera o espaço de um vetor previamente alocado de forma
 * dinâmica. O primeiro elemento do vetor encontra-se no
 * endereço *v.
 */
void liberaVetorDinamico(TipoVetor **v)
{
	assert(v);
	assert(*v);

	free(*v);
	*v = NULL;

	return;
}






