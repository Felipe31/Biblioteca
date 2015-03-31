#ifndef ORDENACAO_H
#define ORDENACAO_H



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


/********************************************** PRELIMINARES *************************
 * Produza uma biblitoeca  ordenacao.c
 * contendo as implementa��es abaixo solicitadas
 * de acordo com os prot�tipos de procedimento apresentados.
 *
 * Em cada procedimeno, procure seguir as etapas apresetadas e trabalhadas em sala
 * de aula.
 *
 * Exerc�cio individual
 ********************************************* PRELIMINARES *************************/

/*
 * Assegura que o item do vetor com maior valor chave
 * ser� colocado na �ltima posicao. PARA ISSO, o procedimento
 * deve comparar a chave do item i com a do item i+1 e troc�-los
 * de posi��o caso o primeiro tenha chave maior do que a do segundo.
 * n � o total de itens do vetor v.
 * Obviamente i e i+1 devem obedecer os limites do vetor.
 * DICA: i varia de 0 a n-1.
 */
void borbulhaMaior(TipoVetor v[], unsigned int n);


/*
 * Assegura que o item do vetor com menor valor chave
 * ser� colocado na primeira posicao. PARA ISSO, o procedimento
 * deve comparar a chave do item i com a do item i-1 e troc�-los
 * de posi��o caso o primeiro tenha chave menor do que a do segundo.
 * n � o total de itens do vetor v.
 * Obviamente i e i-1 devem obedecer os limites do vetor.
 * DICA: i varia de n-1 a 0.
 */
void borbulhaMenor(TipoVetor v[], unsigned int n);


/*
 *  Pesquisa pelo item de v[] que tem menor valor chave
 *  e troca-o com o da primeira posi��o.
 *  n � o total de itens do vetor v.
 */
void selecao(TipoVetor v[], unsigned int n);

/*
 *  Pesquisa pelo item de v[] que tem maior valor chave
 *  e troca-o com o da ultima posi��o.
 *  n � o total de itens do vetor v.
 */
void selecaoMaior(TipoVetor v[], unsigned int n);

/*
 *  Assume que os i primeiros itens do vetor v[] com n elementos
 *  j� est�o ordenados conforme valor do campo chave, ou seja,
 *  v[0].chave <= v[1].chave <= ... <= v[i-1].chave.
 *  Note que v[i].chave pode ser menor, maior ou igual a v[i-1].chave.
 *  Voc� deve inserir o item v[i] na sequencia ordenada v[0]...v[i-1]
 *  de modo a assegurar que os i+1 primeiros itens do vetor fiquem ordenados,
 *  ou seja, v[0].chave <= v[1].chave <= .... v[i-1].chave <= v[i].chave.
 */
void insercao(TipoVetor v[], int i, unsigned int n);

/*
 *  Assume que os i primeiros itens do vetor v[] com n elementos
 *  j� est�o ordenados conforme valor do campo chave, ou seja,
 *  v[0].chave <= v[1].chave <= ... <= v[i-1].chave.
 *  Voc� deve inserir o item v[i] na sequencia ordenada v[0]...v[i-1]
 *  de modo a assegurar que os i+1 primeiros itens do vetor fiquem ordenados,
 *  ou seja, v[0].chave <= v[1].chave <= .... v[i-1].chave <= v[i].chave.
 *  NOTA: s� mude a posi��o de v[i] para uma posi��o p (0<=p<=i-1) do vetor
 *  se p for a posi��o definitiva
 */
//void insercao(TipoVetor v[], int i, unsigned int n);

/*
 * Assume que o vetor est� ordenado do elemento i+1 at� n-1
 * conforme campo chave.
 * Voc� deve inserir o item v[i] na sequencia ordenada v[i+1]...v[n-1]
 * de modo a assegurar que os itens de i a n-1 est�o ordenados, ou seja
 * v[i].chave <= v[i+1].chave <= .... v[n-2].chave <= v[n-1].chave.
 */
void insercaoFim(TipoVetor v[], int i, unsigned int n);

/*
 * Segue a mesma ideia do procedimento insercao
 * mas assumindo que o sub-arranjo de 0 � i-1 est� em
 * ordem decrescente. A inser��o deve manter a ordem
 * decrescente.
 */
void insercaoDecrescente(TipoVetor v[], int i, unsigned int n);

/*
 * Segue a mesma ideia do procedimento insercaoFim
 * mas assumindo que o sub-arranjo de i+1 a n est� em
 * ordem decrescente. A inser��o deve manter a ordem
 * decrescente.
 */
void insercaoDecrescenteFim(TipoVetor v[], int i, unsigned int n);



int particao(TipoVetor v[], int ini, int fim);

int particaoAleatorio(TipoVetor v[], int ini, int fim);

void intercalacao(TipoVetor v[], int ini, int meio, int fim, TipoVetor aux[]);


/*
 * Como cada uma das estrat�gias acima
 * podem ser utilizados para ordenarmos um vetor?
 * Nesse sentido, proponha uma implementa��o
 * conforme os prot�tipos abaixo definidos.
 */

/*
 * Algoritmos de ordenacao simples
 */
void bubbleSort(TipoVetor v[], unsigned int n); /*usando borbulharMaior*/
void selectionSort(TipoVetor v[], unsigned int n); /*usando selecao*/
void insertionSort(TipoVetor v[], unsigned int n);/*usando insercao*/
void quickSort(TipoVetor v[], int ini, int fim);
void quickSortAleatorio(TipoVetor v[], int ini, int fim);
void mergeSort(TipoVetor v[], int ini, int fim);
void merge(TipoVetor v[], int ini, int fim, TipoVetor aux[]);
#endif
