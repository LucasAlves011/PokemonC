//
// Created by lucas on 22/11/2021.
//
#include "functions.h"
enum feedBackGinasio {Padrao = 0, MenosCinquentaBrock = 1, MenosCemBrock = 2,  EmpatouBrock =3, BrockRecebeCritico =4,
                                    MenosCinquentaAsh =5 , MenosCemAsh =6  , EmpatouAsh =7 ,AshRecebeCritico =8   };

void turno(nome_pokemon ashPoke[3], nome_pokemon *brockPoke,int * ashDerrotados, int * brockDerrotados, int batalhas){
    int dadoJogador = rand() % 100;
    int dadoBrock = rand() % 100;
    int diferenca;
    bool jogadorAtk;
    nome_pokemon *temp = brockPoke;
    nome_pokemon *ashPokeSelecionado;
    int round = 1;
    int feedBack = 0;

    //seleciona o pokemon do jogador
    for (int i = 0; i < 3; ++i) {
        if(ashPoke[i].hp > 0) {
            ashPokeSelecionado = &ashPoke[i];
        }
    }

    //seleciona o pokemon do Brock
    while(temp->hp <= 0)
        temp = temp -> proximo;

    imprimirDelay("\nSeu time: ",3000);
    for (int i = 3; i > 0; --i)
        i > *ashDerrotados ? printf("X ") : printf("_ ");

    printf("\t\t\t\t\t");
    for (int i = 0; i < 3; ++i)
        i >= *brockDerrotados ? printf("X ") : printf("_ ");

    imprimirDelay(":Time do Brock",3000);

    getchar();
    imprimirDelay("|-----------------------------------  ",0);
    printf("%d",batalhas);
    imprimirDelay("  -----------------------------------|",0);
    getchar();

    if (dadoJogador > dadoBrock) {
        jogadorAtk = true;
        printf(BYEL"\n\t\tVocê ganhou no dado, você vai comecar atacando."RST);
    } else {
        jogadorAtk = false;
        printf(BRED"\n\t   O brock ganhou no dado entao ele vai comecar atacando."RST);
    }

    printf("\n");
    mostrarHP(ashPokeSelecionado,temp,Padrao);
    getchar();

    do{

        //dado do ataque/def
        dadoJogador = rand() % 100;
        dadoBrock = rand() % 100;
        printf("\n/*****************************  Turno %d  *****************************\\\n",round++);
        printf("%sVocê => %d"RST" \t\t\tX\t\t\t%s%d <= Brock"RST,jogadorAtk == true ? BRED : BBLU,dadoJogador,jogadorAtk == true ? BBLU : BRED,dadoBrock);
        getchar();

        diferenca = dadoJogador - dadoBrock;

        if (diferenca > 0) {
            // JOGADOR GANHOU NO DADO
            if (jogadorAtk == false) {
                //defesa contra brock
                temp->hp -= DANO_DEFESA;
                feedBack = MenosCinquentaBrock;
            } else {
                if(rand() % 100 <= CHANCE_CRITICO){
                    //ataque critico contra brock
                    temp->hp -= DANO_CRITICO;
                    feedBack = BrockRecebeCritico;
                }else{
                    //ataque normal contra brock 100 de hp
                    temp->hp -= DANO_COMUM;
                    feedBack = MenosCemBrock;
                }
            }
        } else if (diferenca < 0) {
            //JOGADOR PERDEU NO DADO
            if (jogadorAtk == true) {
                //defesa contra ash
                ashPokeSelecionado->hp -= DANO_DEFESA;
                feedBack = MenosCinquentaAsh;
            } else {
                if(rand() % 100 <= CHANCE_CRITICO){
                    //ataque critico contra ash
                    ashPokeSelecionado->hp -= DANO_CRITICO;
                    feedBack = AshRecebeCritico;
                }
                else {
                    //ataque normal contra ash
                    ashPokeSelecionado->hp -= DANO_COMUM;
                    feedBack = MenosCemAsh;
                }
            }
        }else{
            //Empatou no dado, o atacante leva 20 de dano.
            if(jogadorAtk == true) {
                ashPokeSelecionado->hp -= EMPATE;
                feedBack = EmpatouAsh;
            }
            else {
                temp->hp -= EMPATE;
                feedBack = EmpatouBrock;
            }
        }

        mostrarHP(ashPokeSelecionado,temp,feedBack);
        getchar();
        //fim do turno, troca do lado de ataque
        jogadorAtk = !jogadorAtk;

    }while(ashPokeSelecionado->hp > 0 && temp->hp > 0);

    printf("\n\n\n");
    //cura de 100 hp para o pokemon vencedor ou até 300 de hp
    if(ashPokeSelecionado->hp > 0){
        if(ashPokeSelecionado->hp <= 200){
            printf("\nVocê saiu vencedor nessa rodada, o seu %s%s"RST" foi curado em "BGRN"+100 HP"RST" como bonus para a proxima batalha.",
                   ashPokeSelecionado->cor, ashPokeSelecionado->nome);
            ashPokeSelecionado->hp += 100;
        }else if(ashPokeSelecionado->hp > 200 && ashPokeSelecionado-> hp <= 300){
            printf("\nVocê saiu vencedor nessa rodada, o seu %s%s"RST" foi curado ate o"BGRN"maximo"RST" como bonus para a proxima batalha.",
                   ashPokeSelecionado->cor, ashPokeSelecionado->nome);
            ashPokeSelecionado -> hp = 300;
        }else if(ashPokeSelecionado -> hp > 300){
            printf("\nVocê saiu vencedor nessa rodada, o seu %s%s"RST" nao foi curado pois esta com o HP no maximo.",
                   ashPokeSelecionado->cor, ashPokeSelecionado->nome);
        }
        *brockDerrotados += 1;
    }else{
        if(temp->hp <= 200){
            printf("\nVocê foi o "BRED"perdedor"RST" dessa rodada, o seu proximo pokemon entrara na batalha em breve. O pokemon de "
                   "Brock recebeu "BGRN"+100 HP"RST".");
            temp->hp += 100;
        }else if(temp->hp > 200 && temp->hp <= 300){
            printf("\nVocê foi o "BRED"perdedor"RST" dessa rodada, o seu proximo pokemon entrara na batalha em breve. O pokemon de "
                   "Brock foi curado ao"BGRN" maximo "RST"como bonus pela vitoria.");
            temp->hp = 300;
        }else if(temp->hp > 300){
            printf("\nVocê saiu perdedor nessa rodada, o %s%s nao foi curado pois esta com o HP no maximo.",
                   temp->cor, temp->nome);
        }
        *ashDerrotados += 1;
    }
    printf("\n\n\n\n");
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
        case Padrao:
            printf("\n%s%s"RST,ash->cor,ash->nome);
            printf("\t\t\tVS\t\t\t%s\n",brock->nome);
            printf("%d HP",ash->hp);
            printf(" \t\t\t\t\t\t       %d HP",brock->hp);
            break;

        case MenosCinquentaBrock:
            printf("\n%s%s"RST,ash->cor,ash->nome);
            printf("\t\t\tVS\t\t\t%s\n",brock->nome);
            printf("%d HP",ash->hp);
            printf(" \t\t\t\t\t\t"BRED"(-%d)"RST"%d HP",DANO_DEFESA,brock->hp);
            break;

        case MenosCemBrock:
            printf("\n%s%s"RST,ash->cor,ash->nome);
            printf("\t\t\tVS\t\t\t%s\n",brock->nome);
            printf("%d HP",ash->hp);
            printf(" \t\t\t\t\t\t"BRED"(-%d)"RST"%d HP",DANO_COMUM,brock->hp);
            break;

        case MenosCinquentaAsh:
            printf("\n%s%s"RST,ash->cor,ash->nome);
            printf("\t\t\tVS\t\t\t%s\n",brock->nome);
            printf("%d HP"BRED"(-%d)"RST,ash->hp,DANO_DEFESA);
            printf(" \t\t\t\t\t\t%d HP",brock->hp);
            break;

        case MenosCemAsh:
            printf("\n%s%s"RST,ash->cor,ash->nome);
            printf("\t\t\tVS\t\t\t%s\n",brock->nome);
            printf("%d HP"BRED"(-%d)"RST,ash->hp,DANO_COMUM);
            printf(" \t\t\t\t\t\t%d HP",brock->hp);
            break;

        case EmpatouAsh:
            printf("\n%s%s"RST,ash->cor,ash->nome);
            printf("\t\t\tVS\t\t\t%s\n",brock->nome);
            printf("%d HP"BRED"(-%d)"RST,ash->hp,EMPATE);
            printf(" \t\t\t\t\t\t%d HP",brock->hp);
            break;

        case EmpatouBrock:
            printf("\n%s%s"RST,ash->cor,ash->nome);
            printf("\t\t\tVS\t\t\t%s\n",brock->nome);
            printf("%d HP",ash->hp);
            printf(" \t\t\t\t\t\t"BRED"(-%d)"RST"%d HP",EMPATE,brock->hp);
            break;

        case AshRecebeCritico:
            printf("\n%s%s"RST,ash->cor,ash->nome);
            printf("\t\t\tVS\t\t\t%s\n",brock->nome);
            printf("%d HP"BRED"*(-%d)"RST,ash->hp,DANO_CRITICO);
            printf(" \t\t\t\t\t\t%d HP",brock->hp);
            break;

        case BrockRecebeCritico:
            printf("\n%s%s"RST,ash->cor,ash->nome);
            printf("\t\t\tVS\t\t\t%s\n",brock->nome);
            printf("%d HP",ash->hp);
            printf(" \t\t\t\t\t\t"BRED"*(-%d)"RST"%d HP",DANO_CRITICO,brock->hp);
            break;
    }

}


