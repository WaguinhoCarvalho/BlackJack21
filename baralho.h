#include <iostream>
#include <string.h>
#include <time.h>
#include "Game_functions.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

/////// ESTRUTURAS /////////

struct NoLO {
	Cards carta;
	NoLO *prox;
};

struct Nopilha{
	Cards carta;
	Nopilha *prox;
};

////// DECLARACAO DAS VARIAVEIS //////

NoLO* criarCartas();
bool Existe(int valores[], int tam, int value);
void Rand(int v[], int quantNumeros);
Nopilha* baralho();


////// FUNCOES ///////

void criarLO (NoLO *&LO) {
	LO = NULL;
}

int loVazia(NoLO *LO) {
	return (LO == NULL);
}

void inserirNaLO (NoLO *&LO, Cards x) {
	NoLO *aux = new (NoLO);
	aux->carta.cod = x.cod;
	strcpy(aux->carta.name, x.name);
	aux->carta.value= x.value;

	NoLO *vizE = NULL;
	NoLO *vizD = LO;

	while ((vizD != NULL) && (x.cod > vizD->carta.cod)) {
		vizE = vizD;
		vizD = vizD->prox;
	}

	if (vizE == NULL) {
		LO = aux;
	}
	else {
		vizE->prox = aux;
	}
	aux->prox = vizD;
}

Cards removerDaLO (NoLO *&LO, Cards ch) {
	NoLO *vizE = NULL;
	NoLO *vizD = LO;

	while ((vizD != NULL) && (ch.cod > vizD->carta.cod)) {
		vizE = vizD;
		vizD = vizD->prox;
	}

	if (vizD != NULL && vizE == NULL) {
		ch = vizD->carta;
		LO = LO->prox;
		delete(vizD);
		
		
	}
	else if (vizD != NULL) {
		ch = vizD->carta;
		NoLO *aux = vizD;
		vizD = vizD->prox;
		delete(aux);

		if (vizD != NULL)
			vizE->prox = vizD;

		else {
			if (vizE == NULL)
				LO = vizD;
			else
				vizE->prox = vizD;
		}
		
		
	}

	return ch;
}

void imprimirLO (NoLO *LO) {
	if (!loVazia(LO)) {
		NoLO *aux = new (NoLO);
		aux = LO;
		while (aux != NULL) {
			aux = aux->prox;
		}
	}
	else
		printf("Lista vazia!");
	printf("\n\n");
	system("pause");
}

/* ************PILHAS**************** */

void criarPilha(Nopilha*&topo) { //Cria uma pilha vazia, apontando o topo da pilha para nulo
	topo = NULL;
}

int pilhaVazia(Nopilha *topo) { //Verifica se a pilha est� vazia ou n�o atrav�s da vari�vel topo
	return (topo == NULL); //retorna o value da compara��o (0 ou 1)
}

void imprimirPilha(Nopilha *topo) {
		if (!pilhaVazia(topo)) {
		Nopilha *aux = topo;
		while (aux != NULL) {
			printf("%s\t\t\n||\n ",aux->carta.name);
			aux = aux->prox;
		}
		printf("\n\n");
	}
	else printf("Pilha vazia!\n\n");
	system("pause");
}

void empilhar_baralho(Nopilha *&topo, Cards x) {
	Nopilha *aux = new Nopilha(); //aloca uma Nova area
	strcpy(aux->carta.name, x.name);
	aux->carta.value = x.value;
	aux->prox = topo; //faz o pr�ximo do novo n� apontar para onde era o topo
	topo = aux; //faz o topo apontar para o novo n�, que agora aponta para o Novo topo
}

Cards desempilhar_baralho(Nopilha *&topo) {
	Nopilha *remover = topo;
	Cards x = topo->carta;
	topo = topo->prox;
	delete(remover);
	return x;
}

Nopilha* baralho(){
    NoLO* criarCartas(), *lo2;
    Nopilha* baralho(), *pilha;
    bool Existe(int valores[], int tam, int value);
    void Rand(int v[], int quantNumeros);
    Cards carta, crd;
    int i, v[52];

    criarLO(lo2);
    lo2 = criarCartas();

    criarPilha(pilha);
    Rand(v,52);
    for(i=0;i<52;i++){
        carta.cod = v[i];
        crd = removerDaLO(lo2, carta);
        empilhar_baralho(pilha,crd);
    }

    return pilha;
}


NoLO* criarCartas(){

	NoLO *lo1;

	criarLO(lo1);
	int j;
	Cards carta;

	for(j=0;j<13;j++){
		carta.cod = j;
		if(j==0){
			strcpy(carta.name,"A Espadas");
			carta.value = 1;
		}else if(j==1){
			strcpy(carta.name,"2 Espadas");
			carta.value = 2;
		}else if(j==2){
			strcpy(carta.name,"3 Espadas");
			carta.value = 3;
		}else if(j==3){
			strcpy(carta.name,"4 Espadas");
			carta.value = 4;
		}else if(j==4){
			strcpy(carta.name,"5 Espadas");
			carta.value = 5;
		}else if(j==5){
			strcpy(carta.name,"6 Espadas");
			carta.value = 6;
		}else if(j==6){
			strcpy(carta.name,"7 Espadas");
			carta.value = 7;
		}else if(j==7){
			strcpy(carta.name,"8 Espadas");
			carta.value = 8;
		}else if(j==8){
			strcpy(carta.name,"9 Espadas");
			carta.value = 9;
		}else if(j==9){
			strcpy(carta.name,"10 Espadas");
			carta.value = 10;
		}else if(j==10){
			strcpy(carta.name,"J Espadas");
			carta.value = 10;
		}else if(j==11){
			strcpy(carta.name,"Q Espadas");
			carta.value = 10;
		}else if(j==12){
			strcpy(carta.name,"K Espadas");
			carta.value = 10;
		}
		inserirNaLO(lo1,carta);
	}

	for(j=13;j<26;j++){
		carta.cod = j;
		if(j==13){
			strcpy(carta.name,"A Copas");
			carta.value = 1;
		}else if(j==14){
			strcpy(carta.name,"2 Copas");
			carta.value = 2;
		}else if(j==15){
			strcpy(carta.name,"3 Copas");
			carta.value = 3;
		}else if(j==16){
			strcpy(carta.name,"4 Copas");
			carta.value = 4;
		}else if(j==17){
			strcpy(carta.name,"5 Copas");
			carta.value = 5;
		}else if(j==18){
			strcpy(carta.name,"6 Copas");
			carta.value = 6;
		}else if(j==19){
			strcpy(carta.name,"7 Copas");
			carta.value = 7;
		}else if(j==20){
			strcpy(carta.name,"8 Copas");
			carta.value = 8;
		}else if(j==21){
			strcpy(carta.name,"9 Copas");
			carta.value = 9;
		}else if(j==22){
			strcpy(carta.name,"10 Copas");
			carta.value = 10;
		}else if(j==23){
			strcpy(carta.name,"J Copas");
			carta.value = 10;
		}else if(j==24){
			strcpy(carta.name,"Q Copas");
			carta.value = 10;
		}else if(j==25){
			strcpy(carta.name,"K Copas");
			carta.value = 10;
		}
		inserirNaLO(lo1,carta);
	}

	for(j=26;j<39;j++){
		carta.cod = j;
		if(j==26){
			strcpy(carta.name,"A Ouros");
			carta.value = 1;
		}else if(j==27){
			strcpy(carta.name,"2 Ouros");
			carta.value = 2;
		}else if(j==28){
			strcpy(carta.name,"3 Ouros");
			carta.value = 3;
		}else if(j==29){
			strcpy(carta.name,"4 Ouros");
			carta.value = 4;
		}else if(j==30){
			strcpy(carta.name,"5 Ouros");
			carta.value = 5;
		}else if(j==31){
			strcpy(carta.name,"6 Ouros");
			carta.value = 6;
		}else if(j==32){
			strcpy(carta.name,"7 Ouros");
			carta.value = 7;
		}else if(j==33){
			strcpy(carta.name,"8 Ouros");
			carta.value = 8;
		}else if(j==34){
			strcpy(carta.name,"9 Ouros");
			carta.value = 9;
		}else if(j==35){
			strcpy(carta.name,"10 Ouros");
			carta.value = 10;
		}else if(j==36){
			strcpy(carta.name,"J Ouros");
			carta.value = 10;
		}else if(j==37){
			strcpy(carta.name,"Q Ouros");
			carta.value = 10;
		}else if(j==38){
			strcpy(carta.name,"K Ouros");
			carta.value = 10;
		}
		inserirNaLO(lo1,carta);
	}

	for(j=39;j<52;j++){
		carta.cod = j;
		if(j==39){
			strcpy(carta.name,"A Paus");
			carta.value = 1;
		}else if(j==40){
			strcpy(carta.name,"2 Paus");
			carta.value = 2;
		}else if(j==41){
			strcpy(carta.name,"3 Paus");
			carta.value = 3;
		}else if(j==42){
			strcpy(carta.name,"4 Paus");
			carta.value = 4;
		}else if(j==43){
			strcpy(carta.name,"5 Paus");
			carta.value = 5;
		}else if(j==44){
			strcpy(carta.name,"6 Paus");
			carta.value = 6;
		}else if(j==45){
			strcpy(carta.name,"7 Paus");
			carta.value = 7;
		}else if(j==46){
			strcpy(carta.name,"8 Paus");
			carta.value = 8;
		}else if(j==47){
			strcpy(carta.name,"9 Paus");
			carta.value = 9;
		}else if(j==48){
			strcpy(carta.name,"10 Paus");
			carta.value = 10;
		}else if(j==49){
			strcpy(carta.name,"J Paus");
			carta.value = 10;
		}else if(j==50){
			strcpy(carta.name,"Q Paus");
			carta.value = 10;
		}else if(j==51){
			strcpy(carta.name,"K Paus");
			carta.value = 10;
		}
		inserirNaLO(lo1,carta);
	}
	return lo1;
}

bool Existe(int valores[], int tam, int value){
	for(int i=0;i<tam;i++){
		if(valores[i]==value)
		return true;
	}
	return false;
}

void Rand(int v[], int quantNumeros){
	srand(time(NULL));

	int rnd;
	for(int i=0;i<quantNumeros;i++){
		rnd = rand() % 52;
		while(Existe(v,i,rnd)){
			rnd = rand() % 52;
		}
		v[i] = rnd;
	}
}
