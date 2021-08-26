#include <iostream>
#include <string.h>

using namespace std;

// ******************** Estruturas ********************

struct Cards{
    char name[10];
    int value;
    int cod;
};

struct Player{
    char name[20];
};

// Struct fila (mao do jogador)
struct NodeHand{
    Cards card;
    NodeHand *next;
};

struct Hand{
    NodeHand *first, *last;
};

// Struct lc (Jogador)
struct NodePlayer{
    Player info;
    NodePlayer *next;
};


// ******************** Lista Hand ********************
void Create_hand(Hand &h){
    h.first = h.last = NULL;
}

int Empt_hand(Hand h){
    return((h.first == NULL) && (h.last == NULL));
}

void Add_on_hand(Hand &h, Cards crd){
    NodeHand *aux = new(NodeHand);
    strcpy(aux->card.name, crd.name);
    aux->card.value = crd.value;
    aux->next = NULL;
    if(Empt_hand(h)){
        h.first = aux;
    }else{
        h.last->next = aux;
    }
    h.last = aux;
}

void Show_hand(Hand h){
    NodeHand *aux;
    aux = h.first;
    while(aux != NULL){
        cout << aux->card.name << " | ";
        aux = aux->next;
    }
}

// ******************** Demais funcoes ********************
int Troca_player(int player){
    player == 1 ? player = 0 : player = 1;
    return player;
}


void Actions(Hand dhand, Hand phand, int dpoints, int ppoints, char pname[]){
    char op_jogo;
    system("cls || clear");
    cout << "\n\nMao do Dealer:\n\n";
    Show_hand(dhand);
    cout << "\n\nPontos: " << dpoints;

    cout << "\n\n================================";
    cout << "\n\nMao do " << pname <<":\n\n";
    Show_hand(phand);
    cout << "\n\nPontos: " << ppoints;
    cout << "\n\n================================\n";
    
}

void Logo(){
	system("cls || clear");
    cout << "+-------------------------------------------------+\n";
    cout << "|                ♥♦♣♠ BLACKJACK ♠♣♦♥              |\n";
    cout << "+-------------------------------------------------+\n";
    cout <<"____________+-----------+ ______________\n";
    cout <<"\\           | K♠        |/             /\n";
    cout <<" \\ 5♦.......| ......... / 2♣........  /\n";
    cout <<"  \\ '       | '       '/  '       '  /\n";
    cout <<"   \\ '      | '       /  '       '  /\n";
    cout <<"    \\ '     | '      /  '       '  /\n";
    cout <<"     \\ '    | '     /  '       '  /\n";
    cout <<"      \\ '   | '    /  '       '  /\n";
    cout <<"       \\ '  | '   /  ;.......'  /\n";
    cout <<"------- \\ '.| '../           2♣/ ----------\n";
    cout <<"====     \\  |    +------------+         =========\n";
    cout <<"          '--===========' \n";
    cout <<"==================================================\n";
}
