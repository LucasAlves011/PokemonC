//
// Created by lucas on 09/11/2021.
//
#include "functions.h"
//verde , roxo , azul ,amarelo , vermelho
char pokemonsAll[25][15]={"Bulbasaur","Chikorita","Bellsprout","Weepinbell","Oddish",
                          "Ekans","Alakazam","Gastly","Rattata","Zubat",
                          "Tentacool","Poliwag","Snorlax","Squirtle","Psyduck",
                          "Sandshrew","Cubone","Pikachu","Diglett","Electabuzz",
                          "Cyndaquil","Vulpix","Charmander","Pidgey","Ponyta"};

int bufferPokemon;

void red(){
    printf("\033[1;31m");
}

void green(){
    printf("\033[0;32m");
}

void yellow(){
//    printf("\033[0;33m");
    printf("\e[0;93m");
}

void blue(){
//    printf("\033[0;34m");
    printf("\e[0;94m");
}

void purple(){
    printf("\033[0;35m");
}

void cyan(){
    printf("\033[0;36m");
}

void reset(){
    printf("\033[0m");
}

void black(){
    printf("\033[0;30m");
}

void feedbackMovimento(int retorno, ash * jogador){
    srand(time(NULL));
    int number;

    do{
        number = rand() % 25;
    }while(number == bufferPokemon);

    char cor[10] ;

    switch (retorno) {
        case NADA:
            return;

        case POKEMON_OBTIDO:
            if(number < 5) {
                printf("Voce capturou um "BGRN"%s"RST".", pokemonsAll[number]);
                strcpy(cor,BGRN);
            }
            else if(number >= 5 && number < 10) {
                printf("Voce capturou um "BMAG"%s"RST".", pokemonsAll[number]);
                strcpy(cor,BMAG);
            }
            else if(number >= 10 && number < 15) {
                printf("Voce capturou um "BBLU"%s"RST".", pokemonsAll[number]);
                strcpy(cor,BBLU);
            }
            else if(number >= 15 && number < 20) {
                printf("Voce capturou um "BYEL"%s"RST".", pokemonsAll[number]);
                strcpy(cor,BYEL);
            }
            else if(number >= 20 && number < 25) {
                printf("Voce capturou um "BRED"%s"RST".", pokemonsAll[number]);
                strcpy(cor,BRED);
            }
            /**
             * Eu entendo que a chamada dessa funcao deveria estar junto as funcões de movimento,
            mas como essa funcao nao tem muito impacto na lógica do game nao deve ter muito problemas.
             */
            adicionarPokemon(pokemonsAll[number],jogador,cor);
            bufferPokemon = number;

            printf(BGRN" +1 pokemon"RST);
            break;

        case POKEBOLA_OBTIDA:
            clear_screen();
            switch (rand() % 3) {
                case 0:
                    printf("Voce recebeu achou uma pokebola !!!");
                    break;
                case 1:
                    printf("Voce encontrou mais uma pokebola !");
                    break;
                case 2:
                    printf("Pokebola encontrada !!");
                    break;
            }
            printf(BGRN" +1 pokebola"RST);
            break;

        case FUGA_POKEBOLA_INSU:
            switch (rand() % 3) {
                case 0:
                    printf("Voce encontrou um pokemon mas nao tinha nenhuma pokebola, o pokemon fugiu.");
                    break;
                case 1:
                    printf("Voce nao tinha nenhuma pokebola, o pokemon fugiu.");
                    break;
                case 2:
                    printf("Pokemon meteu o pe, voce nao tinha pokebola.");
                    break;
            }
            break;

        case ESTADIO_POKEMON_INSU:
            switch (rand() % 4) {
                case 0:
                    printf("Voce nao tem pokemons suficientes, e necessario no minimo 3 pokemons.");
                    break;
                case 1:
                    printf("Voce precisa de mais pokemons pra enfretar Brock.");
                    break;
                case 2:
                    printf("Para entrar no ginasio e preciso no minimo 3 pokemons.");
                    break;
                case 4:
                    printf("Onde pensa que vai ?! Voce nao tem pokpemons suficientes para entrar.");
                    break;
            }
            break;

        case ESTADIO_BATALHA:
            clear_screen();
            printf("Voce entrou no estadio, boa sorte.");
            getchar();
            break;

        case FUGA_POKEMON:
            switch (rand() % 4) {
                case 0:
                    printf("Voce nao conseguiu pega-lo, que azar.");
                    break;
                case 1:
                    printf("Voce nao conseguiu pegar o pokemon, ele foi mais esperto.");
                    break;
                case 2:
                    printf("Gastou um pokebola atoa, ele fugiu.");
                    break;
                case 3:
                    printf("O pokemon foi mais esperto, ele fugiu");
                    break;
            }
            printf(BRED" -1 pokebola"RST);
            break;

        case MOVIMENTO_INVALIDO:
            red();
            switch (rand() % 4) {
                case 0:
                    printf("Voce nao digitou um movimento valido.");
                    break;
                case 1:
                    printf("Movimento invalido.");
                    break;
                case 2:
                    printf("ahhh coe digita um movimento valido.");
                    break;
                case 3:
                    printf("Nao e possivel andar por estas bandas.");
                    break;
            }
            reset();
            break;
    }

}

void ato1(){
    clear_screen();
    printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdhNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdy+ohNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
           "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNMMMMMNdyo::+ydMMMMMMMMNNNNNMMMMMMMMMMMMMMMMMMMMMM\n"
           "MMMMMMNmmddhhhddmNMMMMMMMMNmddyyhdhyhmMMNdysoyhmNMMNddddhhysssyNMMMMMNNNMMMMMMMMMMMMM\n"
           "MMNmdyso+/:::://oshmMMMMNdho/::/yy+:/shmmhsoooosydmdy+::/ss--/ymMMMMmdyssyyhdNNNNMMMM\n"
           "Mmhs/:-----------:+ydMMMmhhy+--/s/---:oyo/:///:-:oyhy:---++--:sdMMMMdhy+-::/yhysssyhm\n"
           "Nmdy+-------/oso:-:ohMNNmmmhs--::---/syo--odhs::oydhs----::---+ymhyysyys---:oys--:+ym\n"
           "MNdhhoo+----:ymys-:shhso++osy:----:oymy+--oy+:+o+oyy+---------os++o:-:/so---/y/--:shM\n"
           "MMNdhhhh/----+hs/:oy+:+s:-/:+y:---:/osyy:-::-::--:+yo:-/:----+s::yy+/o-/y/--:o---+yNM\n"
           "MMMNNNddy/---:/:+yh+-:oysoo::y+-/+::--:oso/::://osys---os:/o:s/--+ooo:-+y:/--:--/ymMM\n"
           "MMMMMMNmdy:---:yhdh:--:///:-+y:-oyhyo+:::+ooyhdmmmyo:::yyssy:os:------/s/-o-----shMMM\n"
           "MMMMMMMNmdy:--:shmds:-----:+yo--oyNNmdhyo/:/ymMMNmdddhhhmhhy/:oso+/+oss:-:y----+yNMMM\n"
           "MMMMMMMMNNhs---/ydNmhsoooshdhs+oshMMMMNNmdhyymMMMMMMMMMMNNmhsoooyymmmhs//oy---:ydMMMM\n"
           "MMMMMMMMMNmho--:shNMNNmmNNMNmmmNNNMMMMMMMMNNmNMMMMMMMMMMMMNNNNmmddMMNmmddhy:--ohMMMMM\n"
           "MMMMMMMMMMNmhooshdNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmhysoyNMMMMM\n"
           "MMMMMMMMMMMNmmNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmNMMMMMM\n\n");
    printf("Ola, pressione enter para comecar o jogo...");
    getchar();
    clear_screen();
    char msg1[]="Nesse jogo " BRED "voce(1)" RST " e um treinador pokemon iniciante e seu objetivo e conquistar a gloria vencendo o" BGRN " ginasio pokemon(5)..." RST;
    char msg2[]="\nMas para isso voce tem que conseguir alguns " BYEL "pokemons(2)" RST " cacando-os pelo mapa...";
    char msg3[]="\nPara pegar um " BYEL "pokemon(2) " RST"e necessario possuir pelo menos uma " BBLU "pokebola(3)" RST " que tambem estao espalhadas pelo mapa, se "BRED"voce(1) "
                RST"se deparar com um" BYEL " pokemon(2) "RST"sem ter nenhuma"BBLU" pokebola(3)" RST", "
                "ele vai fugir, podendo desaparecer ou nao do mapa...";
    char msg4[] = "\nTer uma "BBLU "pokebola(3)" RST " e achar um" BYEL " pokemon(2)" RST " nao significa que ira captura-lo,\n" BYEL "pokemons(2)" RST " sao espertos e nao vao ser capturados facilmente.\n\n"
                  "Seu primeiro desafio na jornada sera contra Brock no" BGRN " ginasio pokemon(5)" RST" da Pedra,mas para isso voce precisa de pelo menos 3 pokemons."
                  "\n\nAperte enter para continuar...";

    imprimirDelay(msg1,0);
    getchar();

    imprimirDelay(msg2,0);
    getchar();

    imprimirDelay(msg3,0);
    getchar();

    imprimirDelay(msg4,0);
    getchar();
}
void tutorial(){
    typedef struct {
        int x;
        int y;
    }jogadorMapaTeste;

    int mapaTeste[7][7] ={1,0};
    mapaTeste[0][3]= 3;
    mapaTeste[0][4]= 3;
    mapaTeste[2][2]= 3;
    mapaTeste[2][5]= 3;
    mapaTeste[5][1]= 3;
    mapaTeste[5][3]= 3;
    mapaTeste[5][6]= 3;
    mapaTeste[6][6]= 3;
    mapaTeste[3][3]= 3;
    mapaTeste[3][4]= 3;
    jogadorMapaTeste jogador;
    jogador.x =0;
    jogador.y =0;

    char jogada = ' ';
    clear_screen();
    imprimirDelay("Para mover seu personagem pelo mapa voce deve digitar a direcao que pretende ir escolhendo entre as opcoes "
                    BYEL"w/a/s/d"RST" e depois pressionar a tecla enter para confirmar a jogada.\n\nVamos testar os controles em um mapa de testes...",0);
    getchar();

    do {
        clear_screen();
        printf("Voce pode navegar pelos caminhos formados pelos 0 brancos. Os "BBLK"X"RST" sao caminhos nao navegaveis.\n\n");
        printf("Tente movimentar seu personagem "BRED"(1)"RST" escolhendo entre as teclas w/a/s/d e depois pressionando a tecla enter.\n\n");
        if (jogada != 'q'){
            for (int i = 0; i < 7; ++i) {
                for (int j = 0; j < 7; ++j) {
                    if (mapaTeste[i][j] == 1) {
                        printf(BRED"%d "RST, mapaTeste[i][j]);
                    } else if (mapaTeste[i][j] == 3){
                        printf(BBLK"X "RST);
                    }else
                        printf("%d ", mapaTeste[i][j]);
                }
                printf("\n");
            }
        }
        printf(BRED"\n\nPara sair do tutorial digite 'q' e confirme.\n\n"RST);
        printf("\n");
        scanf("%c",&jogada);
        getchar();
        switch (jogada) {
            case 'w':
            case 'W':
                if(jogador.x -1 < 0 ||mapaTeste[jogador.x - 1][jogador.y] == 3 ){
                    printf("Jogada invalida, voce deve permanecer dentro do mapa.");
                }else {
                    mapaTeste[jogador.x - 1][jogador.y] = 1;
                    mapaTeste[jogador.x][jogador.y] = 0;
                    jogador.x--;
                }
                break;

            case 's':
            case 'S':
                if(jogador.x + 1> 6 ||mapaTeste[jogador.x + 1][jogador.y] == 3){
                    printf("Jogada invalida, voce deve permanecer dentro do mapa.");
                }else {
                    mapaTeste[jogador.x + 1][jogador.y] = 1;
                    mapaTeste[jogador.x][jogador.y] = 0;
                    jogador.x++;
                }
                break;

            case 'a':
            case 'A':
                if(jogador.y - 1 < 0||mapaTeste[jogador.x][jogador.y - 1] == 3){
                    printf("Jogada invalida, voce deve permanecer dentro do mapa.");
                } else {
                    mapaTeste[jogador.x][jogador.y - 1] = 1;
                    mapaTeste[jogador.x][jogador.y] = 0;
                    jogador.y--;
                }
                break;

            case 'd':
            case 'D':
                if(jogador.y + 1 > 6||mapaTeste[jogador.x][jogador.y + 1] == 3){
                    printf("Jogada invalida, voce deve permanecer dentro do mapa.");
                } else {
                    mapaTeste[jogador.x][jogador.y + 1] = 1;
                    mapaTeste[jogador.x][jogador.y] = 0;
                    jogador.y++;
                }
                break;

            case 'q':
            case 'Q':
                break;

            default:
                printf("Voce nao escolheu um movimento valido.");
                getchar();
                break;
        }
        printf("\n");

    } while (jogada != 'q');

    imprimirDelay("/***********************************************************************************\\\n"
                      "Aqui se inicia sua jornada para se tornar um mestre pokemon, seu objetivo e derrotar Brock"
                      " no "BGRN"ginasio(5)"RST" e conseguir a insignia da Pedra. Boa sorte jogador...",0);
    getchar();
}

void imprimirDelay(char msg[],int delay){
    if(delay == 0){
        delay = 10000;
    }
    for (int i = 0; i <  strlen(msg)  ; i++) {
        printf("%c",msg[i]);
        fflush(stdout);
        usleep(delay);
    }
}

// funcao criada somente para debug
void testarLista(ash *jogador){
    struct nome_pokemon * temp = jogador->inicio;
    int n = 1;
    printf("\n\nLista de pokemons obtidos: \n");
    while(temp->proximo != NULL){
        printf("\n\n Anterior:%s\nAtual:%s\nProximo:%s",temp->anterior->nome,temp->nome,temp->proximo->nome);
        temp = temp->proximo;
    }
    printf("\n\n Anterior:%s\nAtual:%s\nProximo:%s",temp->anterior->nome,temp->nome,temp->proximo->nome);
}

void tutorialGinasio(){
    imprimirDelay("\n\nA batalha esta prestes a comecar. Serao batalhas de 1 contra 1 ate que o hp de um pokemon chegue a zero. "
                  "O pokemon vencedor tera uma parcela de seu hp "BGRN"curado"RST" e estara pronto para a batalha contra o proximo pokemon oponente.\n\n",4000);
    getchar();
    imprimirDelay("As batalhas são uma alternancia de "BRED"turno de ataque"RST" e "BBLU"turno de defesa"RST". No comeco de cada batalha a sorte vai definir quem comecara "BRED"atacando"RST".\n\n",4000);
    getchar();
    imprimirDelay("Fazer uma pontuacao maior estando no "BRED"turno de ataque"RST" faz com que o pokemon oponente receba 100 de dano.\n"
                    "Caso contrario o pokemon atacante recebera "BBLU"30 de dano.\n"RST
                  BYEL"Essa regra vale tanto para voce quanto para brock.\n\n"RST,4000);
    imprimirDelay(BYEL"Danos criticos"RST" podem acontecer, eles causam "BRED"150 de dano"RST" e so podem acontecer em turnos de ataque.",4000);
    getchar();
}

void jogadorGanhou(){
    imprimirDelay("Parabens treinador, voce derrotou Brock nessa batalha. E como recompensa...\n\n",0);

    imprimirDelay("                .-/++oss+-             \n"
                  "        .:/+++osso+///:s.-/oo/.         \n"
                  "       oho-...-:::::::/+....``/++/`     \n"
                  "      yhs/+:..-:::::::s-....`    .+s+   \n"
                  "    `hysss:/+.::::::-.+.....`   `:::h.  \n"
                  "   .dysssss--++++//:--://-..` -:-  .+s  \n"
                  "  -dysssss+.-+//:::   ``.://::`    `-d` \n"
                  " /dsssssss--+.::::`  ``````.+       .s/ \n"
                  "odsssssss::/`::/:`  ``````../.      `-d \n"
                  "ydyyyyyhyso`::::.`  ````...  /       .y-\n"
                  "`dysssssssy/:::.`  ````...`  +---.`  `/y\n"
                  " -mssssssssh/:.`` ````...`  :-```.---:od\n"
                  "  +dssssssssy.``  ```...`  /.````````/y`\n"
                  "   yyssssssyh+/-```....``-+` ```````+s  \n"
                  "   `dysssyyo/::/++++////-`-/` `````s+   \n"
                  "    -msyy+/::::::::s....   `:- ``.y:    \n"
                  "     ods/::::::::::s...      .:.-h.     \n"
                  "      `-+oso//:::::o.`      `-/ys`      \n"
                  "           ./osso/:o..-/++++/-`         \n"
                  "                -+os++:.                \n\n\n",3500);

    imprimirDelay("voce conseguiu a sua primeira insignia. A "BYEL"Insignia da Pedra"RST" e a primeira insigna na jornada"
                        " de um treinador para se tornar um grande mestre pokemon.",0);
}

void jogadorPerdeu(){
    imprimirDelay("Infelizmente voce nao conseguiu ganhar a batalha contra o Brock.",0);
}

void creditos(){
    clear_screen();

    imprimirDelay("\n\n           By: Lucas Alves, estudante de Ciencia da Computacao na UFRPE.\n\n",0);

    imprimirDelay("                                yhhhhhhhhs+.+yhhhhhhhh`  \n"
                  "                                dNNNNNNNNNNmhNNNNNNNNm`  \n"
                  "                                ://////+hNNNNd+///////  \n"
                  "                                        -NNNN/  \n"
                  "                                oyyy+   -NNNN/ \n"
                  "                                dNNNs   -NNNN/ \n"
                  "                                dNNNs   -NNNN/ \n"
                  "                                dNNNh++odNNNNdo+++++++ \n"
                  "                                dNNNNNNNNNNNNNNNNNNNNm` \n"
                  "                                syyyyyyyyo/:osyyyyyyyy   ",2000);

    imprimirDelay("\n\n\n\t\t\t Departamento de Computacao - UFRPE \n",0);
    imprimirDelay("\t\t\t    Recife - Pernambuco - Brasil.\n\t\t\t\t  Novembro de 2021.",0);
    getchar();

    imprimirDelay("\n\n\n\t\t\t        Obrigado por jogar!\n\n\n",0);
    imprimirDelay(
                  "                                                           \n"
                  "                     .//////////    ////    -////-    .////-  \n"
                  "                     +MMMMMMMMMN    mMMm    oMMMMd    yMMMMy  \n"
                  "                     +MMMo/////:    mMMm    oMMMMM-  `NMMMMy  \n"
                  "                     +MMM:          mMMm    oMMmNMs  +MMdMMy  \n"
                  "                     +MMM:          mMMm    oMMdyMN` mMdyMMy  \n"
                  "                     +MMMmdddd-     mMMm    oMMd:MM/:MM+yMMy  \n"
                  "                     +MMMmmmmm-     mMMm    oMMd mMdyMN`yMMy  \n"
                  "                     +MMM:          mMMm    oMMd oMMMMy yMMy  \n"
                  "                     +MMM:          mMMm    oMMd .MMMM- yMMy  \n"
                  "                     +MMM:          mMMm    oMMd  hMMm  yMMy  \n"
                  "                     +MMM:          mMMm    oMMd  /MMo  yMMy  \n"
                  "                     /hhh-          yhhy    /hhs  `hh.  ohho  \n"
                  "                                                              \n\n",1300);
}
