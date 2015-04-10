#ifndef LISTAS_H
#define LISTAS_H

/*----------------------------------------COMUMENTE UTILIZADOS----------------------------------------*/
#ifndef TIPOCHAVE_H
#define TIPOCHAVE_H

  typedef int TipoChave;

#endif

typedef struct TipoLS
{

	TipoChave chave;

	struct TipoLS * prox;

} TipoLS;



typedef struct TipoLD
{
	TipoChave chave;

	struct TipoLD * prox;
	struct TipoLD * ant;

} TipoLD;


/*
 * Troca a chave dos n�s informados
 */
void trocaChvL(TipoLD * no1, TipoLD * no2);


TipoLS * criaNoLS();

TipoLS * criaNoLD();


/*----------------------------------------LISTA SIMPLESMENTE ENCADEADA COM CABE�A----------------------------------------*/

 TipoLS * criaLScc();



 TipoLS * insereIniLScc(TipoLS *cabeca, TipoChave chave);

 TipoLS * insereFimLScc(TipoLS *cabeca, TipoChave chave);

 TipoLS * insereDepoisLScc(TipoLS *cabeca, TipoChave chave, TipoChave ref);

//CUIDAR COM A INSERS�O ANTES DO CABECA!!!!!!!!!!!!!!!!!!!!!!!!1 ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
 TipoLS * insereAntesLScc(TipoLS *cabeca, TipoChave chave, TipoChave ref);



void removeIniLScc(TipoLS *cabeca);

void removeFimLScc(TipoLS *cabeca);

void removeNoLScc(TipoLS *cabeca, TipoChave chave);

void removeLScc(TipoLS *cabeca);



//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
TipoLS * pesquisaNoLScc(TipoLS *cabeca, TipoChave chave);

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO  com o CABECA
TipoLS * pesquisaPtrNoLScc(TipoLS *cabeca, TipoChave chave);



void imprimeLScc(TipoLS *cabeca);

void imprimeInversoLScc(TipoLS *cabeca);



/*----------------------------------------LISTA SIMPLESMENTE ENCADEADA SEM CABE�A----------------------------------------*/

TipoLS * criaLSsc();



TipoLS * insereIniLSsc(TipoLS ** list, TipoChave chave);

TipoLS * insereFimLSsc(TipoLS ** list, TipoChave chave);

TipoLS * insereDepoisLSsc(TipoLS * list, TipoChave chave, TipoChave ref);

TipoLS * insereAntesLSsc(TipoLS ** list, TipoChave chave, TipoChave ref);



void removeIniLSsc(TipoLS ** list);

void removeFimLSsc(TipoLS * list);

void removeNoLSsc(TipoLS ** list, TipoChave chave);

void removeLSsc(TipoLS ** list);



TipoLS * pesquisaNoLSsc(TipoLS * list, TipoChave chave);

TipoLS * pesquisaPtrNoLSsc(TipoLS * list, TipoChave chave);


TipoLS * imprimeLSsc(TipoLS * list);

TipoLS * imprimeInversoLSsc(TipoLS * list);



/*----------------------------------------LISTA DUPLAMENTE ENCADEADA COM CABE�A----------------------------------------*/

 TipoLD * criaLDcc();



 TipoLD * insereIniLDcc(TipoLD *cabeca, TipoChave chave);

 TipoLD * insereFimLDcc(TipoLD *cabeca, TipoChave chave);

 TipoLD * insereDepoisLDcc(TipoLD *cabeca, TipoChave chave, TipoChave ref);

//CUIDAR COM A INSERS�O ANTES DO CABECA!!!!!!!!!!!!!!!!!!!!!!!!1 ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
 TipoLD * insereAntesLDcc(TipoLD *cabeca, TipoChave chave, TipoChave ref, TipoChave ref);



void removeIniLDcc(TipoLD *cabeca);

void removeFimLDcc(TipoLD *cabeca);

void removeNoLDcc(TipoLD *cabeca, TipoChave chave);

void removeLDcc(TipoLD *cabeca);



//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
TipoLD * pesquisaNoLDcc(TipoLD *cabeca, TipoChave chave);

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO  com o CABECA
TipoLD * pesquisaPtrNoLDcc(TipoLD *cabeca, TipoChave chave);



void imprimeLDcc(TipoLD *cabeca);

void imprimeInversoLDcc(TipoLD *cabeca);



/*----------------------------------------LISTA DUPLAMENTE ENCADEADA SEM CABE�A----------------------------------------*/


TipoLD * criaLDsc();



TipoLD * insereIniLDsc(TipoLD ** list, TipoChave chave);

TipoLD * insereFimLDsc(TipoLD ** list, TipoChave chave);

TipoLD * insereDepoisLDsc(TipoLD ** list, TipoChave chave, TipoChave ref);

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
TipoLD * insereAntesLDsc(TipoLD ** list, TipoChave chave, TipoChave ref);



void removeIniLDsc(TipoLD ** list);

void removeFimLDsc(TipoLD ** list);

void removeNoLDsc(TipoLD ** list, TipoChave chave);

void removeLDsc(TipoLD ** list);



TipoLD * pesquisaNoLDsc(TipoLD * list, TipoChave chave);

TipoLD * pesquisaPtrNoLDsc(TipoLD * list, TipoChave chave);


TipoLD * imprimeLDsc(TipoLD * list);

TipoLD * imprimeInversoLDsc(TipoLD * list);



/*----------------------------------------LISTA CIRCULAR SIMPLESMENTE ENCADEADA COM CABE�A----------------------------------------*/

TipoLS * criaLCScc();


TipoLS * insereIniLCScc(TipoLS ** ult, TipoChave chave);

TipoLS * insereFimLCScc(TipoLS ** ult, TipoChave chave);

TipoLS * insereDepoisLCScc(TipoLS ** ult, TipoChave chave, TipoChave ref);

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
TipoLS * insereAntesLCScc(TipoLS ** ult, TipoChave chave, TipoChave ref);



void removeIniLCScc(TipoLS ** ult, TipoChave chave);

void removeFimLCScc(TipoLS ** ult, TipoChave chave);

void removeNoLCScc(TipoLS ** ult, TipoChave chave);

void removeLCScc(TipoLS ** ult);



TipoLS * pesquisaNoLCScc(TipoLS * ult, TipoChave chave);

TipoLS * pesquisaPtrNoLCScc(TipoLS * ult, TipoChave chave);



void imprimeLCScc(TipoLS * ult);

void imprimeInversoLCScc(TipoLS * ult);



/*----------------------------------------LISTA CIRCULAR SIMPLESMENTE ENCADEADA SEM CABE�A----------------------------------------*/

TipoLS * criaLCSsc();


TipoLS * insereIniLCSsc(TipoLS ** ult, TipoChave chave);

TipoLS * insereFimLCSsc(TipoLS ** ult, TipoChave chave);

TipoLS * insereDepoisLCSsc(TipoLS ** ult, TipoChave chave, TipoChave ref);

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
TipoLS * insereAntesLCSsc(TipoLS ** ult, TipoChave chave, TipoChave ref);



void removeIniLCSsc(TipoLS ** ult, TipoChave chave);

void removeFimLCSsc(TipoLS ** ult, TipoChave chave);

void removeNoLCSsc(TipoLS ** ult, TipoChave chave);

void removeLCSsc(TipoLS ** ult);



TipoLS * pesquisaNoLCSsc(TipoLS * ult, TipoChave chave);

TipoLS * pesquisaPtrNoLCSsc(TipoLS * ult, TipoChave chave);



void imprimeLCSsc(TipoLS * ult);

void imprimeInversoLCSsc(TipoLS * ult);



/*----------------------------------------LISTA CIRCULAR DUPLAMENTE ENCADEADA COM CABE�A----------------------------------------*/

TipoLD * criaLCDcc();


TipoLD * insereIniLCDcc(TipoLD ** ult, TipoChave chave);

TipoLD * insereFimLCDcc(TipoLD ** ult, TipoChave chave);

TipoLD * insereDepoisLCDcc(TipoLD ** ult, TipoChave chave, TipoChave ref);

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
TipoLD * insereAntesLCDcc(TipoLD ** ult, TipoChave chave, TipoChave ref);



void removeIniLCDcc(TipoLD ** ult, TipoChave chave);

void removeFimLCDcc(TipoLD ** ult, TipoChave chave);

void removeNoLCDcc(TipoLD ** ult, TipoChave chave);

void removeLCDcc(TipoLD ** ult);



TipoLD * pesquisaNoLCDcc(TipoLD * ult, TipoChave chave);

TipoLD * pesquisaPtrNoLCDcc(TipoLD * ult, TipoChave chave);



void imprimeLCDcc(TipoLD * ult);

void imprimeInversoLCDcc(TipoLD * ult);



/*----------------------------------------LISTA CIRCULAR DUPLAMENTE ENCADEADA SEM CABE�A----------------------------------------*/

TipoLD * criaLCDsc();


TipoLD * insereIniLCDsc(TipoLD ** ult, TipoChave chave);

TipoLD * insereFimLCDsc(TipoLD ** ult, TipoChave chave);

TipoLD * insereDepoisLCDsc(TipoLD ** ult, TipoChave chave, TipoChave ref);

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO
TipoLD * insereAntesLCDsc(TipoLD ** ult, TipoChave chave, TipoChave ref);



void removeIniLCDsc(TipoLD ** ult, TipoChave chave);

void removeFimLCDsc(TipoLD ** ult, TipoChave chave);

void removeNoLCDsc(TipoLD ** ult, TipoChave chave);

void removeLCDsc(TipoLD ** ult);



TipoLD * pesquisaNoLCDsc(TipoLD * ult, TipoChave chave);

TipoLD * pesquisaPtrNoLCDsc(TipoLD * ult, TipoChave chave);



void imprimeLCDsc(TipoLD * ult);

void imprimeInversoLCDsc(TipoLD * ult);



#endif
