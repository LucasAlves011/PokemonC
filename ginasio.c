//
// Created by lucas on 22/11/2021.
//
#include "functions.h"
enum feedBackGinasio {MenosCinquentaBrock = 1, MenosCemBrock = 2, MenosCinquentaAsh = 3, MenosCemAsh = 4};



void comecarBatalha(ash *jogador){
/**
 * ROLA UM DADO de 1 a 10 PRA VER QUEM COMEÇA ATACANDO
 *  Quem ganhar começa a atacando e é rolado dois dados, se o ataque ganhar ele dá um de dano no openenente (cada openente)
 *  se a defesa ganhar o ataque leva 1/2 de dano e o turno vira
 *
 *
 */
}
void turno(nome_pokemon ashPoke[3], nome_pokemon *brockPoke){
    int dadoJogador = rand() % 100;
    int dadoBrock = rand() % 100;
    int diferenca;
    bool jogadorAtk;
    nome_pokemon *temp = brockPoke;
    nome_pokemon *ashPokeSelecionado;
    int round = 1;
    int feedBack = 0;

    for (int i = 0; i < 3; ++i) {
        if(ashPoke[i].hp > 0) {
            ashPokeSelecionado = &ashPoke[i];
        }
    }
    while(temp->hp <= 0)
        temp = temp -> proximo;


    if (dadoJogador > dadoBrock) {
        jogadorAtk = true;
        printf(BYEL"\nVocê ganhou no dado, você vai começar atacando."RST);
    } else {
        jogadorAtk = false;
        printf(BRED"\nO brock ganhou no dado então ele vai começar atacando."RST);
    }

    printf("\n\n");
    getchar();

    do{

        //dado do ataque/def
        dadoJogador = rand() % 100;
        dadoBrock = rand() % 100;
        printf("\n/*****************************  Rodada %d  *****************************\\\n",round++);
        printf("%sVocê => %d"RST" \t\t\tX\t\t\t%s%d <= Brock"RST,jogadorAtk == true ? BRED : BBLU,dadoJogador,jogadorAtk == true ? BBLU : BRED,dadoBrock);
        getchar();

        diferenca = dadoJogador - dadoBrock;

        if (diferenca > 0) {
            // JOGADOR GANHOU NO DADO
            if (jogadorAtk == false) {
                temp->hp -= 50;
                feedBack = 1;
            } else {
                //talvez venha uma mecânica de critico posteriormente
                temp->hp -= 100;
                feedBack = 2;
            }
        } else {
            //JOGADOR PERDEU NO DADO
            if (jogadorAtk == true) {
                ashPokeSelecionado->hp -= 50;
                feedBack = 3;
            } else {
                //talvez venha uma mecânica de critico posteriormente
                ashPokeSelecionado->hp -= 100;
                feedBack = 4;
            }
        }

        mostrarHP(ashPokeSelecionado,temp,feedBack);
        getchar();
        //fim do turno, troca do lado de ataque
        jogadorAtk = !jogadorAtk;

    }while(ashPokeSelecionado->hp > 0 && temp->hp > 0);


    if(ashPokeSelecionado->hp > 0){
        printf("\nVocê saiu vencedor nessa rodada, o seu %s%s"RST" foi curado em "BGRN"+100 HP"RST" como bônus para a próxima batalha",ashPokeSelecionado->cor,ashPokeSelecionado->nome);
        ashPokeSelecionado->hp += 100;
    }else{
        printf("\nVocê foi o "BRED"perdedor"RST" dessa rodada, o seu próximo pokemon entrara na batalha em breve. O pokemon de "
                                             "Brock recebeu "BGRN"+100 HP"RST".");
        temp->hp +=50;
    }
    getchar();
    clear_screen();
}

nome_pokemon* iniciarBrock(){
    nome_pokemon *x =  malloc(sizeof (nome_pokemon));
    nome_pokemon *y =  malloc(sizeof (nome_pokemon));
    nome_pokemon *z =  malloc(sizeof (nome_pokemon));

    strcpy(x->nome,"Croagunk");
    strcpy(y->nome,"Geodude");
    strcpy(z->nome,"Onix");
    x->hp  = 300;
    y->hp = 300;
    z->hp = 350;

    x->anterior = NULL;
    x->proximo = y;
    y->anterior = x;
    y->proximo = z;
    z->anterior = y;
    z->proximo = NULL;

    return x;
}

void iniciarAsh(nome_pokemon lista[]){
    lista->hp = 300;
    lista++;
    lista->hp = 300;
    lista++;
    lista->hp = 300;
}

void mostrarHP(nome_pokemon *ash,nome_pokemon *brock,int feedback){
    switch (feedback) {
        case MenosCinquentaBrock:
            printf("\n%s%s"RST,ash->cor,ash->nome);
            printf("\t\t\tVS\t\t\t%s\n",brock->nome);
            printf("%d HP",ash->hp);
            printf(" \t\t\t\t\t"BRED"(-50)"RST"%d HP",brock->hp);
            break;
        case MenosCemBrock:
            printf("\n%s%s"RST,ash->cor,ash->nome);
            printf("\t\t\tVS\t\t\t%s\n",brock->nome);
            printf("%d HP",ash->hp);
            printf(" \t\t\t\t\t"BRED"(-100)"RST"%d HP",brock->hp);
            break;
        case MenosCinquentaAsh:
            printf("\n%s%s"RST,ash->cor,ash->nome);
            printf("\t\t\tVS\t\t\t%s\n",brock->nome);
            printf("%d HP"BRED"(-50)"RST,ash->hp);
            printf(" \t\t\t\t\t%d HP",brock->hp);
            break;
        case MenosCemAsh:
            printf("\n%s%s"RST,ash->cor,ash->nome);
            printf("\t\t\tVS\t\t\t%s\n",brock->nome);
            printf("%d HP"BRED"(-100)"RST,ash->hp);
            printf(" \t\t\t\t\t%d HP",brock->hp);
            break;
    }

}


