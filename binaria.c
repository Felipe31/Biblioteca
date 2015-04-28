#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct NoArvBinaria
{
  int chave;
  struct NoArvBinaria * esq;
  struct NoArvBinaria * dir;
};

typedef struct NoArvBinaria NoArvBinaria;


/*
 * PROCEDIMENTOS DE BUSCA CLASSICOS
 * devolve o endereco do no cujo valor chave eh k
 * ou NULL caso tal no nao exista na arvore enraizada
 * por raiz.
 */
NoArvBinaria *buscaArvBinRec(NoArvBinaria *raiz, int k)
{
    if(raiz == NULL)
        return NULL;

    if(k == raiz -> chave)
        return raiz;

    if(k < raiz -> chave)
        return buscaArvBinRec(raiz -> esq, k);

    return buscaArvBinRec(raiz -> dir, k);

}
NoArvBinaria *buscaArvBinIterativa(NoArvBinaria *raiz, int k)
{

    while(1)
    {
        if(raiz == NULL)
            return NULL;

        if(k == raiz -> chave)
            return raiz;

        if(k < raiz -> chave)
            raiz = raiz -> esq;

        else
            raiz = raiz -> dir;
    }

}

/*
 * PROCEDIMENTOS DE BUSCA DO MENOR/MAIOR
 * 1) devolve o endereco do no cujo valor chave eh o
 *    menor da arvore dada ou NULL caso a arvore seja vazia.
 * 2) devolve o endereco do no cujo valor chave eh o
 *    maior da arvore dada ou NULL caso a arvore seja vazia.
 */
NoArvBinaria *buscaEnderecoDoMenor(NoArvBinaria *raiz) /*1*/
{
    if(raiz ==  NULL)
        return NULL;

    if(raiz -> esq == NULL)
        return raiz;

    return buscaEnderecoDoMenor(raiz -> esq);
}


NoArvBinaria *buscaEnderecoDoMaior(NoArvBinaria *raiz) /*2*/
{
    if(raiz ==  NULL)
        return NULL;

    if(raiz -> dir == NULL)
        return raiz;

    return buscaEnderecoDoMaior(raiz -> dir);

}


/*
 * PROCEDIMENTO DE BUSCA DO ENDERECO DO PONTEIRO DO NO k
 * devolve o endereco onde está armazenado o endereco do no
 * cujo valor chave eh k ou NULL caso tal no nao exista. O
 * no raiz da arvore dada esta armazenado no endereco *raiz.
 * Assuma que a arvore pode estar vazia, nesse caso *raiz==NULL.
 * i.e.: Para arvores nao vazias, a funcao deve devolver um
 * ponteiro x tal que a seguinte  condicao seja satisfeita:
 * (*x)->chave == k
 */
NoArvBinaria **buscaEnderecoDoPonteiro(NoArvBinaria **raiz, int k)
{
    assert(raiz);

    if(*raiz == NULL)
        return NULL;

    if(k == (*raiz) -> chave)
        return raiz;

    if(k < (*raiz) -> chave)
        raiz = &((*raiz) -> esq);

    else
        raiz = &((*raiz) -> dir);



    return buscaEnderecoDoPonteiro(raiz, k);
}


/*
 * PROCEDIMENTOS DE BUSCA DO ENDERECO DO PONTEIRO DO MENOR/MAIOR
 * 1) devolve o endereco do ponteiro para o no cujo valor chave eh o
 *    menor da arvore dada ou NULL caso a arvore seja vazia.
 *    i.e.: Para arvores nao nulas a funcao deve devolver um ponteiro x
            tal que (*x)->chave eh o menor valor chave de toda a arvore dada
 * 2) devolve o endereco do ponteiro para o no cujo valor chave eh o
 *    maior da arvore dada ou NULL caso a arvore seja vazia.
 *    i.e.: Para arvores nao nulas a funcao deve devolver um ponteiro x
 *          tal que (*x)->chave eh o maior valor chave de toda a arvore dada
 * O parametro de entrada raiz eh o endereco do ponteiro para o raiz
 * da arvore.
 */
NoArvBinaria **buscaEnderecoDoPonteiroDoMenor(NoArvBinaria **raiz) /*1*/
{
    assert(raiz);

    if(*raiz == NULL)
        return NULL;

    if((*raiz) -> esq == NULL)
        return raiz;

    raiz = &((*raiz) -> esq);

    return buscaEnderecoDoPonteiroDoMenor(raiz);
}


NoArvBinaria **buscaEnderecoDoPonteiroDoMaior(NoArvBinaria **raiz) /*2*/
{
    assert(raiz);

    if(*raiz == NULL)
        return NULL;

    if((*raiz) -> dir == NULL)
        return raiz;

    raiz = &((*raiz) -> dir);

    return buscaEnderecoDoPonteiroDoMaior(raiz);
}

/*
 * Assume que *raiz aponta para um no folha
 * de uma arvore binaria de pesquisa qualquer.
 * O procedimento deve remover tal no.
 */
void removeFolha(NoArvBinaria **raiz)
{
    assert(raiz);

    free(*raiz);

    (*raiz) = NULL;

    return;
}

/*
 * Assume que *raiz != NULL
 * O no armazenado no endereco *raiz TEM NECESSARIAMENTE
 * UM FILHO ARMAZENADO EM (*raiz)->esq OU (exclusivo) (*raiz)->dir.
 * O procedimento deve remover o no armazenado em *raiz e
 * fazer com que *raiz passe a apontar pelo filho do no a
 * ser removido
 */
void removeNoComSomenteUmFilho(NoArvBinaria **raiz)
{
    assert(raiz);

    NoArvBinaria * aux = *raiz;

    if(((*raiz) -> esq == NULL) && ((*raiz) -> dir != NULL))
            (*raiz) = (*raiz) -> dir;

    else if((((*raiz) -> esq != NULL) && (*raiz) -> dir == NULL))
            (*raiz) = (*raiz) -> esq;

    free(aux);

    return;
}

/*
 * PROCEDIMENTOS DE INSERCAO
 * insere um no com chave igual a k numa arvore binaria
 * de pesquisa dada. O no raiz da arvore dada esta armazenado
 * no endereco *raiz. Assuma que a arvore pode estar vazia
 * nesse caso *raiz==NULL.
 * Devolve o endereco do no recem criado ou o endereco do no
 * que ja contenha chave igual a k.
 */

NoArvBinaria *insereArvBinRec(NoArvBinaria **raiz, int k)
{

    assert(raiz);

    if(*raiz == NULL)
    {
        (*raiz) = (NoArvBinaria *) malloc(sizeof(NoArvBinaria));
        if(*raiz == NULL)
            return NULL;

        (*raiz) -> esq = NULL;
        (*raiz) -> dir = NULL;
        (*raiz) -> chave = k;

        return (*raiz);
    }

    if(k == (*raiz) -> chave)
        return *raiz;

    else if(k < (*raiz) -> chave)
        return insereArvBinRec(&((*raiz) -> esq), k);

    return insereArvBinRec(&((*raiz) -> dir), k);

}




NoArvBinaria *insereArvBinIterativa(NoArvBinaria **raiz, int k)
{
    assert(raiz);

    NoArvBinaria * ptr = (NoArvBinaria *) malloc(sizeof(NoArvBinaria));
    NoArvBinaria ** aux = raiz;

    if(ptr == NULL)
        return NULL;

    ptr -> chave = k;
    ptr -> esq = NULL;
    ptr -> dir = NULL;
    
    while(1)
    {
        if((*aux) == NULL)
        {
            *aux = ptr;
            return ptr;
        }

        else if((*aux) -> chave == k)
        {
            return *aux;
        }

        else if(k < (*aux) -> chave)
        {
            aux = &((*aux) -> esq);
        }

        else if(k > (*aux) -> chave)
        {
            aux = &((*aux) -> dir);
        }

    }

}

void imprimeArvBin(NoArvBinaria * raiz)
{
    if(raiz)
    {
        printf("%d ", raiz -> chave );

        imprimeArvBin(raiz -> esq);
        imprimeArvBin(raiz -> dir);

    }
}


