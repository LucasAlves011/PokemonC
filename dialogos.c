#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "cert-msc50-cpp"
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
                printf("Você capturou um "BGRN"%s"RST".", pokemonsAll[number]);
                strcpy(cor,BGRN);
            }
            else if(number >= 5 && number < 10) {
                printf("Você capturou um "BMAG"%s"RST".", pokemonsAll[number]);
                strcpy(cor,BMAG);
            }
            else if(number >= 10 && number < 15) {
                printf("Você capturou um "BBLU"%s"RST".", pokemonsAll[number]);
                strcpy(cor,BBLU);
            }
            else if(number >= 15 && number < 20) {
                printf("Você capturou um "BYEL"%s"RST".", pokemonsAll[number]);
                strcpy(cor,BYEL);
            }
            else if(number >= 20 && number < 25) {
                printf("Você capturou um "BRED"%s"RST".", pokemonsAll[number]);
                strcpy(cor,BRED);
            }
            /**
             * Eu entendo que a chamada dessa função deveria estar junto as funções de movimento,
            mas como essa função não tem muito impacto na lógica do game não deve ter muito problemas.
             */
            adicionarPokemon(pokemonsAll[number],jogador,cor);
            bufferPokemon = number;

            printf(BGRN" +1 pokemon"RST);
            break;

        case POKEBOLA_OBTIDA:
            clear_screen();
            switch (rand() % 3) {
                case 0:
                    printf("Você recebeu achou uma pokébola !!!");
                    break;
                case 1:
                    printf("Você encontrou mais uma pokébola !");
                    break;
                case 2:
                    printf("Pokébola encontrada !!");
                    break;
            }
            printf(BGRN" +1 pokebola"RST);
            break;

        case FUGA_POKEBOLA_INSU:
            switch (rand() % 3) {
                case 0:
                    printf("Você encontrou um pokémon mas não tinha nenhuma pokébola, o pokémon fugiu.");
                    break;
                case 1:
                    printf("Você não tinha nenhuma pokébola, o pokémon fugiu.");
                    break;
                case 2:
                    printf("Pokémon meteu o pé, você não tinha pokébola.");
                    break;
            }
            break;

        case ESTADIO_POKEMON_INSU:
            switch (rand() % 4) {
                case 0:
                    printf("Você não tem pokémons suficientes, é necessário no mínimo 3 pokémons.");
                    break;
                case 1:
                    printf("Você precisa de mais pokémons pra enfretar Brock.");
                    break;
                case 2:
                    printf("Para entrar no ginásio é preciso no mínimo 3 pokémons.");
                    break;
                case 4:
                    printf("Onde pensa que vai ?! Você não tem pokpemons suficientes para entrar.");
                    break;
            }
            break;

        case ESTADIO_BATALHA:
            clear_screen();
            printf("Você entrou no estádio, boa sorte.");
            getchar();
            break;

        case FUGA_POKEMON:
            switch (rand() % 4) {
                case 0:
                    printf("Você não conseguiu pegá-lo, que azar.");
                    break;
                case 1:
                    printf("Você não conseguiu pegar o pokémon, ele foi mais esperto.");
                    break;
                case 2:
                    printf("Gastou um pokébola atoa, ele fugiu.");
                    break;
                case 3:
                    printf("O pokémon foi mais esperto, ele fugiu");
                    break;
            }
            printf(BRED" -1 pokebola"RST);
            break;

        case MOVIMENTO_INVALIDO:
            red();
            switch (rand() % 4) {
                case 0:
                    printf("Você não digitou um movimento válido.");
                    break;
                case 1:
                    printf("Movimento inválido.");
                    break;
                case 2:
                    printf("ahhh coé digita um movimento válido.");
                    break;
                case 3:
                    printf("Não é possível andar por estas bandas.");
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
    printf("Olá, pressione enter para começar o jogo...");
    getchar();
    clear_screen();
    char msg1[]="Nesse jogo " BRED "você(1)" RST " é um treinador pokémon iniciante e seu objetivo é conquistar a glória vencendo o" BGRN " ginásio pokémon(5)..." RST;
    char msg2[]="\nMas para isso você tem que conseguir alguns " BYEL "pokémons(2)" RST " caçando-os pelo mapa...";
    char msg3[]="\nPara pegar um " BYEL "pokémon(2) " RST"é necessário possuir pelo menos uma " BBLU "pokébola(3)" RST " que também estão espalhadas pelo mapa,\nse "BRED"você(1) "
                RST"se deparar com um" BYEL " pokémon(2) "RST"sem ter nenhuma"BBLU" pokébola(3)" RST", "
                "ele vai fugir, podendo desaparecer ou não do mapa...";
    char msg4[] = "\nTer uma "BBLU "pokébola(3)" RST " e achar um" BYEL " pokémon(2)" RST " não significa que irá capturá-lo,\n" BYEL "pokémons(2)" RST " são espertos e não vão ser capturados facilmente.\n\n"
                  "Para tentar desafiar Brock no" BGRN " ginásio pokémon(5)" RST" você precisa de pelo menos 3 pokémons."
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
    char msg1[]="Para mover seu personagem pelo mapa você deve digitar a direção que pretende ir escolhendo entre as opções "
                BYEL"w/a/s/d"RST" e depois pressionar a tecla enter para confirmar a jogada.\n\nVamos testar os controles em um mapa de testes...";
    imprimirDelay(msg1,0);
    getchar();

    do {
        clear_screen();
        printf("Você pode navegar pelos caminhos formados pelos 0 brancos. Os "BBLK"X"RST" são caminhos não navegáveis.\n\n");
        printf("Tente movimentar seu personagem "BRED"(1)"RST": w/a/s/d . "BRED"Para sair do tutorial digite 'q' e confirme.\n\n"RST);
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
        printf("\n");
        scanf("%c",&jogada);
        getchar();
        switch (jogada) {
            case 'w':
            case 'W':
                if(jogador.x -1 < 0 ||mapaTeste[jogador.x - 1][jogador.y] == 3 ){
                    printf("Jogada inválida, você deve permanecer dentro do mapa.");
                }else {
                    mapaTeste[jogador.x - 1][jogador.y] = 1;
                    mapaTeste[jogador.x][jogador.y] = 0;
                    jogador.x--;
                }
                break;

            case 's':
            case 'S':
                if(jogador.x + 1> 6 ||mapaTeste[jogador.x + 1][jogador.y] == 3){
                    printf("Jogada inválida, você deve permanecer dentro do mapa.");
                }else {
                    mapaTeste[jogador.x + 1][jogador.y] = 1;
                    mapaTeste[jogador.x][jogador.y] = 0;
                    jogador.x++;
                }
                break;

            case 'a':
            case 'A':
                if(jogador.y - 1 < 0||mapaTeste[jogador.x][jogador.y - 1] == 3){
                    printf("Jogada inválida, você deve permanecer dentro do mapa.");
                } else {
                    mapaTeste[jogador.x][jogador.y - 1] = 1;
                    mapaTeste[jogador.x][jogador.y] = 0;
                    jogador.y--;
                }
                break;

            case 'd':
            case 'D':
                if(jogador.y + 1 > 6||mapaTeste[jogador.x][jogador.y + 1] == 3){
                    printf("Jogada inválida, você deve permanecer dentro do mapa.");
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
                printf("Você não digitou um movimento válido.");
                break;
        }
        printf("\n");

    } while (jogada != 'q');

    char mensagem[] = "/****************************************************************************************\\\n"
                      "Aqui se inicia sua jornada para se tornar um mestre pokémon, seu objetivo é derrotar Brock"
                      " no "BGRN"ginásio(5)"RST" e conseguir a insígnia da Pedra. Boa sorte jogador...";

    imprimirDelay(mensagem,0);
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

void listarPokemons(ash *jogador){
    struct nome_pokemon * temp = jogador->inicio;
    int n = 1;
    printf("Lista de pokemons obtidos: \n");
    while(temp->proximo != NULL){
        printf("%d - %s%s\n",n++,temp->cor,temp->nome);
        temp = temp->proximo;
        reset();
    }
    printf("%d - %s%s\n",n,temp->cor,temp->nome);
    reset();
}

// função criada somente para debug
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

#pragma clang diagnostic pop