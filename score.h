#include <string.h>
#include <conio.h>
#include <iostream>
using namespace std;

struct Score{
    char nome[20];
    int pontuacao=0;
    bool perdeu;
};

struct LdeScore {
	Score pont;
	LdeScore *prox, *ant;
};

void criarLOscore (LdeScore *&NOscore) {
	NOscore = NULL;
}

int ldescoreVazia(LdeScore *NOscore) {
	return (NOscore == NULL);
}

void inserirNaLdeScore (LdeScore *&NOscore, Score x, int inicio) {
	LdeScore *aux = new (LdeScore);
	strcpy(aux->pont.nome, x.nome);
	aux->pont.pontuacao = x.pontuacao;

	if(inicio){
		aux->ant = NULL;
		aux->prox = NOscore;

		if(!ldescoreVazia(NOscore)){
			NOscore->ant = aux;
		}
		NOscore = aux;
	}else{
		strcpy(aux->pont.nome, x.nome);
		aux->pont.pontuacao = x.pontuacao;
		aux->prox = NULL;

		if(ldescoreVazia(NOscore)){
			aux->ant = NULL;
			NOscore = aux;
		}else{
			LdeScore *ult = NOscore;
			while(ult->prox != NULL){
				ult = ult->prox;
			}
			ult->prox = aux;
			aux->ant = ult;
		}
	}

}

void removerDaLdeScore (LdeScore *&NOscore, Score x) {

	if(NOscore->pont.nome == x.nome){
		if(NOscore->prox == NULL){
			delete(NOscore);
			NOscore = NULL;
		}else{
			NOscore = NOscore->prox;
			delete(NOscore->ant);
			NOscore->ant = NULL;
		}
	}else{
		LdeScore *aux = NOscore;
		while(aux != NULL && aux->pont.nome != x.nome){
			aux = aux->prox;
		}

		if(aux->prox == NULL){
			aux->ant->prox = NULL;
			delete(aux);
		}else{
			aux->ant->prox = aux->prox;
			aux->prox->ant = aux->ant;
			delete(aux);
		}
	}
}

void imprimirLOscore (LdeScore *NOscore) {
	LdeScore *aux = NOscore;
	if (!ldescoreVazia(NOscore)) {
        cout << "\n\n+===========================+\n";
        cout << "|           SCORE           |\n";
        cout << "+===========================+\n";
		while (aux != NULL) {
			cout << "\n" << aux->pont.nome << "\t" << aux->pont.pontuacao << endl;
			cout << "=============================" << endl;
			aux = aux->prox;
		}
	}
	else
		printf("Nenhuma Pontuacao foi Marcada!");
	printf("\n");
	
}


void scoreGeral(Score &dealer, Score &nome1){
	int pd = 0, pp = 0;

	if(dealer.perdeu != nome1.perdeu){
		if(!dealer.perdeu){
			dealer.pontuacao++;
		}else if(!nome1.perdeu){
			nome1.pontuacao++;
		}
	}

    LdeScore *game;

    criarLOscore(game);

	if(dealer.pontuacao > nome1.pontuacao){
		pd = 1;
	}else{
		pp = 1;
	}

    if(ldescoreVazia(game)){
        inserirNaLdeScore(game,dealer,pd);
        inserirNaLdeScore(game,nome1,pp);
    }else{
        LdeScore *aux;
        while(aux != NULL){
            removerDaLdeScore(game,dealer);
            removerDaLdeScore(game,nome1);
        }
        delete(aux);
        inserirNaLdeScore(game,dealer,pd);
        inserirNaLdeScore(game,nome1,pp);
		}

    imprimirLOscore(game);
	
}
