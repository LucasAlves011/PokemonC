#include "functions.h"

/**
 * são 56 espaços navegáveis porem [0,0] e [11,0] nao poderam recebar pokemons ou pokebolas
 * 0 espaços navegáveis
 * -- 1 VAI REPRESENTAR O JOGADOR --
 * 2 espaços navegáveis com pokemons
 * 3 espaços navegáveis com pokebolas
 * 4 espaços não navegáveis
 * 5 estádio pokemon
 */

int matrizEspacosDisponiveis[3][55]={0};
int pokemonsForagidos = 0;

int main() {
    //iniciando os status do jogador
    setlocale(LC_ALL,"Portuguese");
//    ato1();
//    tutorial();

    ash jogador;
    jogador.tamanho = 0;
    jogador.posicao[0] = 0;
    jogador.posicao[1] = 0;
    jogador.pokebolas = 10;
    jogador.pokemons = 0;
    jogador.inicio = NULL;

    int mapaPosicional[12][10] = {0};
    int iterador = 0;

    clear_screen();
    //iniciar os obstáculos e objetivos no mapa
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 10; ++j) {
            switch (j) {
                case 0:
                    if(i == 0){
                        mapaPosicional[i][j] = 0;
                    }
                    else if( i == 5 || i == 6 || (i > 7 && i <= 11))
                        if (i == 11) {
                            mapaPosicional[i][j] = 5;
                        } else { mapaPosicional[i][j] = 4; }
                    break;
                case 1:
                    if((i > 0 && i < 4) || i == 5 || i == 6 || i == 8 || i == 10)
                        mapaPosicional[i][j] = 4;
                    break;
                case 2:
                    if((i > 0 && i < 4) || i == 8 || i == 10)
                        mapaPosicional[i][j] = 4;
                    break;
                case 3:
                    if(i > 0 && i < 7)
                        mapaPosicional[i][j] = 4;
                    break;
                case 4:
                    if(i == 1 || i == 2 || i ==8 || i == 10 || i == 11)
                        mapaPosicional[i][j] = 4;
                    break;
                case 5:
                    if((i > 0 && i < 5) || i == 6 || i == 8)
                        mapaPosicional[i][j] = 4;
                    break;
                case 6:
                    if(i > 3 && i <= 11)
                        mapaPosicional[i][j] = 4;
                    break;
                case 7:
                    if((i >= 0 && i < 3) || (i > 3 && i < 7))
                        mapaPosicional[i][j] = 4;
                    break;
                case 8:
                    if(i > 7 && i <= 11)
                        mapaPosicional[i][j] = 4;
                    break;
                case 9:
                    if(i > 0 && i <= 11)
                        mapaPosicional[i][j] = 4;
                    break;
                default:
                    break;
            }
        }
    }

    //Alocar valor a matriz de espaços disponíveis
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(mapaPosicional[i][j] == 0 && !((i == 11 && j == 0) ||( i == 0 && j == 0))){
                matrizEspacosDisponiveis[0][iterador] = i;
                matrizEspacosDisponiveis[1][iterador] = j;
                iterador++;
            }
        }
    }

    //injetar pokebolas e pokemons no mapa
    injetarPokemonsPokebolas(matrizEspacosDisponiveis, mapaPosicional);

    bool flow = true;
    int controlador = 0;
    char jogada;
    do{
        printf("\n\n");
        imprimir(mapaPosicional,jogador);
        printf("Faça a sua jogada: w/a/s/d \n");
        printf("Você atualmente tem %d "BBLU "pokébolas"RST" e %d"BYEL" pokémons"RST". ",jogador.pokebolas,jogador.pokemons);
        scanf("%c",&jogada);
        getchar();

        switch (jogada) {
            case ('S'):
            case ('s'):
                controlador = andarS(&jogador,mapaPosicional,&flow);
                clear_screen();
                feedbackMovimento(controlador,&jogador);
                break;

            case ('W'):
            case ('w'):
                controlador=andarW(&jogador,mapaPosicional,&flow);
                clear_screen();
                feedbackMovimento(controlador,&jogador);
                break;

            case ('A'):
            case ('a'):
                controlador = andarA(&jogador,mapaPosicional,&flow);
                clear_screen();
                feedbackMovimento(controlador,&jogador);
                break;

            case ('D'):
            case ('d'):
                controlador = andarD(&jogador,mapaPosicional,&flow);
                clear_screen();
                feedbackMovimento(controlador,&jogador);
                break;

            default:
                clear_screen();
                printf("Você não digitou uma jogada válida\n");
                break;
        }
    }while (flow);

    clear_screen();
    nome_pokemon selecionados[3];

    selecionados[0] = selecionarPokemon(&jogador,selecionados);
    clear_screen();
    selecionados[1] = selecionarPokemon(&jogador,selecionados);
    clear_screen();
    selecionados[2] = selecionarPokemon(&jogador,selecionados);

    getchar();

    printf("Você selecionou: ");
    for (int i = 0; i < 3; ++i)
        printf("\n%d - %s%s"RST,(i+1),selecionados[i].cor,selecionados[i].nome);

    // TODO apresentar time do brock
    // TODO inic



    return 0;
}

void injetarPokemonsPokebolas(int x[3][55], int mapa[12][10]){
    /*  3 vai representar as pokebolas
     *  2 vai representar os pokemons
     *  Vão ser inicializadas 10 pokebolas e 10 pokemons consumindo 20 dos 56 espaços disponíveis
     */
    srand(time(NULL));
    int y = 0;
    int temp = 0;
    do{
        temp = rand() % 55;
        //pokemons
        if(x[2][temp] == 0 ){
            x[2][temp] = -1;
            mapa[x[0][temp]][x[1][temp]] = 2;
            y++;
        }
    } while (y < 10);

    //pokebolas
    do{
        temp = rand() % 55;
        //pokebolas
        if(x[2][temp] == 0){
            x[2][temp] = -1;
            mapa[x[0][temp]][x[1][temp]] = 3;
            y++;
        }
    } while (y < 20);
}

void realocarPokemon(int matriz[12][10],ash *jogador) {
    //Essa funçao so vai realocar no mapa em ate 3 fugas, acima disso os pokemons desaparecem do mapa
    if(pokemonsForagidos < 3){
        srand(time(NULL));
        int x;
        do {
            x = rand() % 56;
            if (matrizEspacosDisponiveis[2][x] == 0) {
                matrizEspacosDisponiveis[2][x] = -1;
            }
        } while (matrizEspacosDisponiveis[2][x] != -1);
        matriz[matrizEspacosDisponiveis[0][x]][matrizEspacosDisponiveis[1][x]] = 2;
        pokemonsForagidos++;
    }
}

void imprimir(int para[12][10], ash jogador){
    int n = 0;
    bool entrar = true;
    bool condicao = true;
    for (int i = 0; i < 12; ++i) {
        purple();
        if(i == 0){
            if(entrar){
                printf("   ");
                entrar = false;
            }
            for (int j = 0; j < 10; ++j) {
                printf("%d ",j);
            }
            printf("\n");
        }

        for (int j = 0; j < 10; ++j) {
            if(j == 0){
                printf("%d ",n++);
            }
            if(i <= 9 && condicao == true) {
                printf(" ");
                condicao = false;
            }
            reset();
            if(i == jogador.posicao[0] && jogador.posicao[1] == j ){
                red();
                printf("1 ");
                reset();
            }else{
                switch (para[i][j]) {
                    case 0:
                        break;
                    case 2:
                        yellow();
                        break;
                    case 3:
                        blue();
                        break;
                    case 4:
                        black();
                        printf("X ");
                        break;
                    case 5:
                        green();
                        break;
                }
                if(para[i][j] != 4){
                    printf("%d ",para[i][j]);
                }
            }
            reset();
        }
        printf("\n");
        condicao = true;
    }
    printf("\n");
}