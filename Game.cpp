#include <iostream>
#include <string.h>
#include <unistd.h>
#include <locale.h>
//#include <windows.h>
#include "score.h"
#include "baralho.h"


using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");

    char op_menu, op_jogo, play_again;
    bool exit = false, game_over = false, stop = false;
    int i, turn_player = 1;


    do{
        Logo();
        cout << "[1] Jogar\n[2] Instrucoes\n[3] Sair\n";
        cin >> op_menu;
        

        switch(toupper(op_menu)){
            case '1':
            {
                NodePlayer *players;
                Hand player_hand, dealer_hand;
                Score dealer, player;
                Nopilha *deck;
                Cards bcard;
                

                strcpy(dealer.nome, "Dealer");
                cout << "Nome do jogador: ";
                cin >> player.nome;
                system("cls || clear");
                
                while(!game_over){
                    dealer.perdeu = player.perdeu = false;
                    int dealer_points = 0, player_points = 0;
                    deck = baralho();
                    // Cria a lista(mao) dos jogadores
                    Create_hand(dealer_hand);
                    Create_hand(player_hand);

                    // Distribui as cartas
                    for(i = 0; i < 4; i++){
                        if(turn_player){
                            Add_on_hand(player_hand, desempilhar_baralho(deck));
                            player_points += player_hand.last->card.value;
                        }else{
                            Add_on_hand(dealer_hand, desempilhar_baralho(deck));
                            dealer_points += dealer_hand.last->card.value;
                        }
                        turn_player = Troca_player(turn_player);
                    }

                    // Jogadas do usuario
                    do{
                        Actions(dealer_hand, player_hand, dealer_points, player_points, player.nome);
                        cout << "\tSua Vez\n\n[C] Comprar\t[P] Parar\n";
                        cin >> op_jogo;

                        if(toupper(op_jogo) == 'C'){
                            Add_on_hand(player_hand, desempilhar_baralho(deck));
                            player_points += player_hand.last->card.value;
                            cout << "\nComprou " << player_hand.last->card.name;
                            cout << "\n\nPontos: " << player_points << endl;
                            //Sleep(2000);
                            sleep(2);
                        }
                        if(player_points == 21){
                            game_over = true;
                            dealer.perdeu = true;
                            op_jogo = 'P';
                        }
                        if(player_points > 21){
                            cout << "\nEstourou!! Voce perdeu!\n";
                            game_over = true;
                            player.perdeu = true;
                            op_jogo = 'P';
                        }
                    }while(toupper(op_jogo) == 'C');

                    // Jogadas do PC
                    while(!game_over){
                        Actions(dealer_hand, player_hand, dealer_points, player_points, player.nome);
                        cout << "\n\n\tVez do Dealer\n";
                        if(dealer_points < 20 || stop){
                            if(dealer_points <= 11){
                                Add_on_hand(dealer_hand, desempilhar_baralho(deck));
                                dealer_points += dealer_hand.last->card.value;
                                cout << "\nDealer Comprou " << dealer_hand.last->card.name;
                            }else if(dealer_points <= 17 && dealer_points < player_points){
                                Add_on_hand(dealer_hand, desempilhar_baralho(deck));
                                dealer_points += dealer_hand.last->card.value;
                                cout << "\nDealer Comprou " << dealer_hand.last->card.name;
                            }else if(player_points >= 18 && player_points <=19){
                                Add_on_hand(dealer_hand, desempilhar_baralho(deck));
                                dealer_points += dealer_hand.last->card.value;
                                cout << "\nDealer Comprou " << dealer_hand.last->card.name;
                            }else{
                                stop = true;
                                cout << "\nDealer Parou!";
                            }
                            cout << "\n\nPontos: " << dealer_points << endl;
                            //Sleep(2000);
                            sleep(2);
                        }

                        if(dealer_points > 21){
                            dealer.perdeu = true;
                        }

                        if(dealer_points > player_points || dealer_points == 20 || stop){
                            game_over = true;
                        }
                        stop = false;
                    }

                    if(player.perdeu){
                        cout << "\nDEALER VENCEU!!!";
                    }else if(dealer.perdeu){
                        cout << "\nVOCE VENCEU!!!";
                    }else{
                        if(player_points > dealer_points){
                            cout << "\nVOCE VENCEU!!!";
                            dealer.perdeu = true;
                        }else if(player_points < dealer_points){
                            cout << "\nDEALER VENCEU!!!";
                            player.perdeu = true;
                        }else{
                            cout << "\nEMPATE!!";
                        }
                    }
                    
                    scoreGeral(dealer, player);

                    cout << "\nJogar Novamente? [S/N]\n";
                    cin >> play_again;
                    if(toupper(play_again) == 'S'){
                        game_over = false;
                    }else{
                        exit = true;
                    }
                }
            }
            break;

            case '2':
                cout << "O usuario ira jogar contra a maquina, o objetivo do jogo e fazer 21 pontos ou chegar proximo a essa pontuacao. Os jogadores recebem duas cartas com a face para cima. O objetivo de qualquer mao de Blackjack e derrotar o dealer. Para fazer isso, voce deve ter uma mao em que a pontuacao seja mais elevada do que a mao do dealer, mas nao exceda 21 no valor total. Como alternativa voce pode ganhar tendo uma pontuacao menor que 22 quando o valor da mao do dealer ultrapassar 21. Quando o valor total da sua mao for 22 ou mais, normalmente conhecido como 'estourar', voce vai automaticamente perder. Quando solicitado, voce pode pedir cartas para a(s) sua(s) mao(s) com o proposito de aumentar o seu valor total. Quando terminar de pedir cartas, o dealer ira concluir a sua mao.";
                cout << "\n";
			    system ("PAUSE");
            break;
            
            case '3':
                exit = true;
            break;

            default:
                cout << "Opcao Invalida!!\n\n";
            break;
            
        }
    }while(!exit);


    return 0;
}
