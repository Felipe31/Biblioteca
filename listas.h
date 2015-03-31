#ifndef LISTAS_H
#define LISTAS_H

/*----------------------------------------COMUMENTE UTILIZADOS----------------------------------------*/
#ifndef TIPOCHAVE_H 
#define TIPOCHAVE_H

  typedef int TipoChave;

#endif

typedef struct tipoLS
{
	
	tipoChave chave;

	struct tipoLS * prox;

} tipoLS;



typedef struct tipoLD
{
	tipoChave chave;

	struct tipoLD * prox;
	struct tipoLD * ant;
	
} tipoLD;


/*
 * Troca a chave dos nós informados
 */
void trocaChvL(tipoLD * no1, tipoLD * no2);


tipoLS * criaNoLS();

tipoLS * criaNoLD();


/*----------------------------------------LISTA SIMPLESMENTE ENCADEADA COM CABEÇA----------------------------------------*/

 tipoLS * criaLScc();



 tipoLS * insereIniLScc(tipoLS *cabeca, tipoChave chave);

 tipoLS * insereFimLScc(tipoLS *cabeca, tipoChave chave);

 tipoLS * insereDepoisLScc(tipoLS *cabeca, tipoChave chave, tipoChave ref);
 
//CUIDAR COM A INSERSÃO ANTES DO CABECA!!!!!!!!!!!!!!!!!!!!!!!!1 ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
 tipoLS * insereAntesLScc(tipoLS *cabeca, tipoChave chave, tipoChave ref);



void removeIniLScc(tipoLS *cabeca);

void removeFimLScc(tipoLS *cabeca);

void removeNoLScc(tipoLS *cabeca, tipoChave chave);

void removeLScc(tipoLS *cabeca);



//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
tipoLS * pesquisaNoLScc(tipoLS *cabeca, tipoChave chave);

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO  com o CABECA
tipoLS * pesquisaPtrNoLScc(tipoLS *cabeca, tipoChave chave);



void imprimeLScc(tipoLS *cabeca);

void imprimeInversoLScc(tipoLS *cabeca);



/*----------------------------------------LISTA SIMPLESMENTE ENCADEADA SEM CABEÇA----------------------------------------*/

tipoLS * criaLSsc();



tipoLS * insereIniLSsc(tipoLS ** list, tipoChave chave);

tipoLS * insereFimLSsc(tipoLS ** list, tipoChave chave);

tipoLS * insereDepoisLSsc(tipoLS * list, tipoChave chave);

tipoLS * insereAntesLSsc(tipoLS ** list, tipoChave chave);



void removeIniLSsc(tipoLS ** list);

void removeFimLSsc(tipoLS * list);

void removeNoLSsc(tipoLS ** list, tipoChave chave);

void removeLSsc(tipoLS ** list);



tipoLS * pesquisaNoLSsc(tipoLS * list, tipoChave chave);

tipoLS * pesquisaPtrNoLSsc(tipoLS * list, tipoChave chave);


tipoLS * imprimeLSsc(tipoLS * list);

tipoLS * imprimeInversoLSsc(tipoLS * list);



/*----------------------------------------LISTA DUPLAMENTE ENCADEADA COM CABEÇA----------------------------------------*/

 tipoLD * criaLDcc();



 tipoLD * insereIniLDcc(tipoLD *cabeca, tipoChave chave);

 tipoLD * insereFimLDcc(tipoLD *cabeca, tipoChave chave);

 tipoLD * insereDepoisLDcc(tipoLD *cabeca, tipoChave chave, tipoChave ref);
 
//CUIDAR COM A INSERSÃO ANTES DO CABECA!!!!!!!!!!!!!!!!!!!!!!!!1 ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
 tipoLD * insereAntesLDcc(tipoLD *cabeca, tipoChave chave, tipoChave ref);



void removeIniLDcc(tipoLD *cabeca);

void removeFimLDcc(tipoLD *cabeca);

void removeNoLDcc(tipoLD *cabeca, tipoChave chave);

void removeLDcc(tipoLD *cabeca);



//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
tipoLD * pesquisaNoLDcc(tipoLD *cabeca, tipoChave chave);

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO  com o CABECA
tipoLD * pesquisaPtrNoLDcc(tipoLD *cabeca, tipoChave chave);



void imprimeLDcc(tipoLD *cabeca);

void imprimeInversoLDcc(tipoLD *cabeca);



/*----------------------------------------LISTA DUPLAMENTE ENCADEADA SEM CABEÇA----------------------------------------*/


tipoLD * criaLDsc();



tipoLD * insereIniLDsc(tipoLD ** list, tipoChave chave);

tipoLD * insereFimLDsc(tipoLD ** list, tipoChave chave);

tipoLD * insereDepoisLDsc(tipoLD ** list, tipoChave chave);

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
tipoLD * insereAntesLDsc(tipoLD ** list, tipoChave chave);



void removeIniLDsc(tipoLD ** list);

void removeFimLDsc(tipoLD ** list);

void removeNoLDsc(tipoLD ** list, tipoChave chave);

void removeLDsc(tipoLD ** list);



tipoLD * pesquisaNoLDsc(tipoLD * list, tipoChave chave);

tipoLD * pesquisaPtrNoLDsc(tipoLD * list, tipoChave chave);


tipoLD * imprimeLDsc(tipoLD * list);

tipoLD * imprimeInversoLDsc(tipoLD * list);



/*----------------------------------------LISTA CIRCULAR SIMPLESMENTE ENCADEADA COM CABEÇA----------------------------------------*/

tipoLS * criaLCScc();


tipoLS * insereIniLCScc(tipoLS ** ult, tipoChave chave);

tipoLS * insereFimLCScc(tipoLS ** ult, tipoChave chave);

tipoLS * insereDepoisLCScc(tipoLS ** ult, tipoChave chave);

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
tipoLS * insereAntesLCScc(tipoLS ** ult, tipoChave chave);



void removeIniLCScc(tipoLS ** ult, tipoChave chave);

void removeFimLCScc(tipoLS ** ult, tipoChave chave);

void removeNoLCScc(tipoLS ** ult, tipoChave chave);

void removeLCScc(tipoLS ** ult);



tipoLS * pesquisaNoLCScc(tipoLS * ult, tipoChave chave);

tipoLS * pesquisaPtrNoLCScc(tipoLS * ult, tipoChave chave);



void imprimeLCScc(tipoLS * ult);

void imprimeInversoLCScc(tipoLS * ult);



/*----------------------------------------LISTA CIRCULAR SIMPLESMENTE ENCADEADA SEM CABEÇA----------------------------------------*/

tipoLS * criaLCSsc();


tipoLS * insereIniLCSsc(tipoLS ** ult, tipoChave chave);

tipoLS * insereFimLCSsc(tipoLS ** ult, tipoChave chave);

tipoLS * insereDepoisLCSsc(tipoLS ** ult, tipoChave chave);

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
tipoLS * insereAntesLCSsc(tipoLS ** ult, tipoChave chave);



void removeIniLCSsc(tipoLS ** ult, tipoChave chave);

void removeFimLCSsc(tipoLS ** ult, tipoChave chave);

void removeNoLCSsc(tipoLS ** ult, tipoChave chave);

void removeLCSsc(tipoLS ** ult);



tipoLS * pesquisaNoLCSsc(tipoLS * ult, tipoChave chave);

tipoLS * pesquisaPtrNoLCSsc(tipoLS * ult, tipoChave chave);



void imprimeLCSsc(tipoLS * ult);

void imprimeInversoLCSsc(tipoLS * ult);



/*----------------------------------------LISTA CIRCULAR DUPLAMENTE ENCADEADA COM CABEÇA----------------------------------------*/

tipoLD * criaLCDcc();


tipoLD * insereIniLCDcc(tipoLD ** ult, tipoChave chave);

tipoLD * insereFimLCDcc(tipoLD ** ult, tipoChave chave);

tipoLD * insereDepoisLCDcc(tipoLD ** ult, tipoChave chave);

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
tipoLD * insereAntesLCDcc(tipoLD ** ult, tipoChave chave);



void removeIniLCDcc(tipoLD ** ult, tipoChave chave);

void removeFimLCDcc(tipoLD ** ult, tipoChave chave);

void removeNoLCDcc(tipoLD ** ult, tipoChave chave);

void removeLCDcc(tipoLD ** ult);



tipoLD * pesquisaNoLCDcc(tipoLD * ult, tipoChave chave);

tipoLD * pesquisaPtrNoLCDcc(tipoLD * ult, tipoChave chave);



void imprimeLCDcc(tipoLD * ult);

void imprimeInversoLCDcc(tipoLD * ult);



/*----------------------------------------LISTA CIRCULAR DUPLAMENTE ENCADEADA SEM CABEÇA----------------------------------------*/

tipoLD * criaLCDsc();


tipoLD * insereIniLCDsc(tipoLD ** ult, tipoChave chave);

tipoLD * insereFimLCDsc(tipoLD ** ult, tipoChave chave);

tipoLD * insereDepoisLCDsc(tipoLD ** ult, tipoChave chave);

//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
//ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO ATENCAO 
tipoLD * insereAntesLCDsc(tipoLD ** ult, tipoChave chave);



void removeIniLCDsc(tipoLD ** ult, tipoChave chave);

void removeFimLCDsc(tipoLD ** ult, tipoChave chave);

void removeNoLCDsc(tipoLD ** ult, tipoChave chave);

void removeLCDsc(tipoLD ** ult);



tipoLD * pesquisaNoLCDsc(tipoLD * ult, tipoChave chave);

tipoLD * pesquisaPtrNoLCDsc(tipoLD * ult, tipoChave chave);



void imprimeLCDsc(tipoLD * ult);

void imprimeInversoLCDsc(tipoLD * ult);



#endif