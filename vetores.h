#ifndef VETORES_H
#define VETORES_H
/*
 * Implemente uma biblioteca contendo a defini��o
 * para cada um dos prot�tipos abaixo espeficados.
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef TIPOCHAVE_H
#define TIPOCHAVE_H

  typedef int TipoChave;

#endif

#ifndef TIPOVETOR_H
#define TIPOVETOR_H


  struct TipoVetor
  {
    TipoChave chave;
    /*
     * aqui podemos ter outros
     * campos conforme aplicacao...
     */
  };
  typedef struct TipoVetor TipoVetor;
#endif
/*
 * Aloca vetor de n itens do tipo TipoVetor.
 * Devolve NULL caso n seja invalido ou ocorra
 * erro de aloca��o
 */
TipoVetor *alocaVetor(int n);


/*
 * Troca o elemento da posi��o i
 * com o elemento da posi��o j do vetor v
 */
void trocaVetor(TipoVetor v[], int i, int j);



/*
 * Imprime todos os elementos do vetor v
 * se os par�metros de entrada forem v�lidos.
 * ini indica o �ndice do primeiro elemento
 * fim indica o �ndice do �ltimo elemento
 */
void imprimeVetor(TipoVetor v[], int ini, int fim);

/*
 * Inicializa todos os elementos do vetor v
 * com -1 se os par�metros de entrada forem v�lidos.
 * ini indica o �ndice do primeiro elemento de v
 * fim indica o �ndice do �ltimo elemento de v
 */
void inicializaVetor(TipoVetor v[], int ini, int fim);

/*
 * Inicializa todos os elementos do vetor v
 * com valores aleat�rios da funcao rand se
 * os par�metros de entrada forem v�lidos.
 * ini indica o �ndice do primeiro elemento
 * fim indica o �ndice do �ltimo elemento
 * maxchave indica o maior valor aleat�rio
 *          que pode ser atribuido a uma
 *          posi��o do vetor. Assuma maxchave>=0.
 * OBS.: N�o use srand
 */
void inicializaVetorAleatorio(TipoVetor v[], int ini, int fim, TipoChave maxchave);

/*
 * Inicializa v[] com valores crescentes (a partir de zero)
 * se os par�metros de entrada forem v�lidos;
 * Ex. v[ini]=0, v[ini+1]=1, ...
 * ini indica o �ndice do primeiro elemento
 * fim indica o �ndice do �ltimo elemento
 */
void inicializaOrdenadoCrescente(TipoVetor v[], int ini, int fim);


/*
 * Inicializa v[] com valores decrescentes
 * se os par�metros de entrada forem v�lidos;
 * Se no vetor cabem n elementos, entao teriamos
 * Ex. v[ini]=n, v[ini+1]=n-1, ...
 * ini indica o �ndice do primeiro elemento
 * fim indica o �ndice do �ltimo elemento
 */
void inicializaOrdenadoDecrescente(TipoVetor v[], int ini, int fim);


/*
 * Inicializa v[] com valores crescentes (a partir de zero)
 * da posic�o ini at� a posi��o j-1 se os par�metros de
 * entrada forem v�lidos;
 * Ex. v[ini]=0, v[ini+1]=1, ....,
 * Da posi��o j ate fim, v[] deve ser inicializado
 * com valores aleat�rios menores ou iguals a maxchave
 * ini indica o �ndice do primeiro elemento
 * fim indica o �ndice do �ltimo elemento
 */
void inicializaOrdenadoAleatorio(TipoVetor v[], int ini, int j, int fim, TipoChave maxchave);

/*
 * Devolve 1 caso o vetor v esteja ordenado ou 0
 * caso contrario. Se pelo menos uma das entradas
 * forem inv�lidas algoritmo deve devolver -1.
 * ini indica o �ndice do primeiro elemento
 * fim indica o �ndice do �ltimo elemento
 */
char estaOrdenado(TipoVetor v[], int ini, int fim);

/*
 * Copia os elementos do vetor v[] em um novo vetor
 * que dever� ser alocado com a mesma quantidade de
 * elementos de v[].
 * Devolve o ponteiro para o primeiro elemento do novo
 * vetor, ou NULL caso haja problemas de aloca��o ou
 * alguma das entradas sejam inv�lidas.
 */
TipoVetor *copiaVetor(TipoVetor v[], int ini, int fim);

/*
 * Devolve 1 se os par�metros de entrada for�m v�lidos e
 * os vetores v1[] e v2[] forem iguais, isto �,
 * t�m a mesma quantidade de elementos e satisfaz:
 * v1[i] == v2[i] para todo i válido. Devolve 0 caso os vetores
 * sejam diferentes.
 * ini1 indica o �ndice do primeiro elemento de v1[]
 * fim1 indica o �ndice do �ltimo elemento de v1[]
 * ini2 indica o �ndice do primeiro elemento de v2[]
 * fim2 indica o �ndice do �ltimo elemento de v2[]
 */
char comparaVetores(TipoVetor v1[], int ini1, int fim1, TipoVetor v2[], int ini2, int fim2);

/*
 * Libera o espa�o de um vetor previamente alocado de forma
 * din�mica. O primeiro elemento do vetor encontra-se no
 * endere�o *v.
 */
void liberaVetorDinamico(TipoVetor **v);
#endif
