#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "cert-msc50-cpp"
//
// Created by lucas on 09/11/2021.
//
#include "functions.h"

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

void feedbackMovimento(int retorno){
    srand(time(NULL));
    int seletor = rand() % 3;

    switch (retorno) {
        case NADA:
            return;

        case POKEMON_OBTIDO:
            switch (rand() % 10) {
                case 0:
                    printf("Você encontrou um" BGRN" Bulbasaur"RST".");
                    break;
                case 1:
                    printf("Você capturou um "BMAG"Zubat"RST".");
                    break;
                case 2:
                    printf("Você capturou um "BBLU"Snorlax"RST".");
                    break;
                case 3:
                    printf("Você capturou um "BYEL"Pikachu"RST".");
                    break;
                case 4:
                    printf("Você capturou um "BYEL"Diglett"RST".");
                    break;
                case 5:
                    printf("Você capturou um "BRED"Vulpix"RST".");
                    break;
                case 6:
                    printf("Você capturou um "BRED"Pidgey"RST".");
                    break;
                case 7:
                    printf("Você capturou um "BMAG"Ekans"RST".");
                    break;
                case 8:
                    printf("Você capturou um fucking "BMAG"Alakazam"RST".Na teoria eu te daria a vitória agora.");
                    break;
                case 9:
                    printf("Você capturou uma "BRED"Ponyta"RST".");
                    break;
                case 10:
                    printf("Você capturou um "BBLU"Magnemite"RST".");
                    break;
            }
            green();
            printf(" +1 pokemon");
            reset();
            break;

        case POKEBOLA_OBTIDA:
            clear_screen();
            switch (seletor) {
                case 0:
                    printf("Você recebeu achou uma pokébola !!!");
                    break;
                case 1:
                    printf("Você encontrou mais uma pokébola");
                    break;
                case 2:
                    printf("Pokébola encontrada !!");
                    break;
            }
            green();
            printf(" +1 pokebola");
            reset();
            break;

        case FUGA_POKEBOLA_INSU:
            switch (seletor) {
                case 0:
                    printf("Você encontrou um pokémon mas não tinha nenhuma pokebola, o pokémon fugiu. ");
                    break;
                case 1:
                    printf("Você não tinha nenhuma pokébola, o pokémon fugiu");
                    break;
                case 3:
                    printf("Pokémon meteu o pé, você não tinha pokébola.");
                    break;
            }
            break;

        case ESTADIO_POKEMON_INSU:
            printf("Você não tem pokémons suficientes, é necessário no mínimo 3 pokémons");
            break;
        case ESTADIO_BATALHA:

            break;

        case FUGA_POKEMON:
            switch (seletor) {
                case 0:
                    printf("Você não conseguiu pegá-lo, que azar.");
                    break;
                case 1:
                    printf("Você não conseguiu pegar o pokémon, ele foi mais esperto.");
                    break;
                case 2:
                    printf("Gastou um pokébola atoa, ele fugiu.");
                    break;
            }
            red();
            printf(" -1 pokebola");
            reset();
            break;
        case MOVIMENTO_INVALIDO:
            red();
            switch (seletor) {
                case 0:
                    printf("Você não digitou um movimento válido");
                    break;
                case 1:
                    printf("Movimento inválido");
                    break;
                case 2:
                    printf("ahhh coé digita um movimento válido ");
                    break;
            }
            reset();
            break;
    }

}

void apresentar(){
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
    printf("Nesse jogo " BRED "você(1)" RST " é um treinador pokémon iniciante e seu objetivo é conquistar a glória vencendo o" BGRN " ginásio pokémon(5)\n\n" RST
           "Mas para isso você tem que conseguir alguns " BYEL "pokémons(2)" RST " caçando-os pelo mapa.\n\nPara pegar um " BYEL "pokémon(2) " RST
           "é necessário possuir pelo menos uma " BBLU "pokébola(3)" RST " que também estão espalhadas pelo mapa,\nse "BRED"você(1) "RST"se deparar com um" BYEL " pokémon(2) "RST"sem ter nenhuma"BBLU" pokébola(3)" RST", "
           "ele vai fugir, podendo desaparecer ou não do mapa.\n\n");
    printf("Ter uma "BBLU "pokébola(3)" RST "e achar um" BYEL " pokémon(2)" RST " não significa que irá capturá-lo,\n");
    printf(BYEL "pokémons(2)" RST " são espertos e não vão ser capturados facilmente.");

    getchar();
}

#pragma clang diagnostic pop