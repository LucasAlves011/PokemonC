#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/**
 * são 56 espaços navegáveis porem [0,0] e [11,0] nao poderam recebar pokemons ou pokebolas
 * 0 espaços navegáveis
 * -- 1 VAI REPRESENTAR O JOGADOR --
 * 2 espaços navegáveis com pokemons
 * 3 espaços navegáveis com pokebolas
 * 4 espaços não navegáveis
 * 5 estádio pokemon
 */
typedef struct {
    int posicao[2];
    int pokemons;
    int pokebolas;
}ash;

// FUNÇÕES VÃO RETORNAR INT PARA REPRESENTAR AÇÕES
void realocarPokemon(int matriz[12][10],ash *jogador);
void clear_screen();
void injetarPokemonsPokebolas(int x[3][55],int mapa[12][10]);
int andarW( ash *jogador, int matriz[12][10]);
int andarA( ash *jogador, int matriz[12][10]);
int andarS( ash *jogador, int matriz[12][10]);
int andarD( ash *jogador, int matriz[12][10]);

void imprimir(int para[12][10], ash jogador){
    int n = 0;
    bool entrar = true;
    bool condicao = true;

    for (int i = 0; i < 12; ++i) {
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
            if(i == jogador.posicao[0] && jogador.posicao[1] == j ){
                printf("1 ");
            }else
                printf("%d ",para[i][j]);
        }
        printf("\n");
        condicao = true;
    }
    printf("\n");
}
int matrizEspacosDisponiveis[3][55]={0};
int pokemonsForagidos = 0;
int main() {
    //iniciando os status do jogador, teste ssh
    setlocale(LC_ALL,"Portuguese");

    ash jogador;
    jogador.posicao[0] = 0;
    jogador.posicao[1] = 0;
    jogador.pokebolas = 0;
    jogador.pokemons = 0;

    int mapaPosicional[12][10] = {0};

    int iterador = 0;

    //iniciar os obstáculos e objetivos no mapa
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 10; ++j) {
            switch (j) {
                case 0:
                    if(i == 0){
                        mapaPosicional[i][j] = 0;
                    }
                    else if( i == 5 || i == 6 || (i > 7 && i <= 11))
                        if( i == 11) {
                            mapaPosicional[i][j] = 5;
                        } else {
                            mapaPosicional[i][j] = 4;
                        }
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
    injetarPokemonsPokebolas(matrizEspacosDisponiveis,mapaPosicional);
    /*
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 55; ++j) {
            printf("%d ",matrizEspacosDisponiveis[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");

    imprimir(mapaPosicional,jogador);
    */
    /*
//    printf("\n%d %d\n", jogador.posicao[0],jogador.posicao[1] );
    andarS(&jogador,mapaPosicional);
    getchar();
    clear_screen();

    imprimir(mapaPosicional,jogador);
    getchar();
    clear_screen();
    andarS(&jogador,mapaPosicional);
    imprimir(mapaPosicional,jogador);
    getchar();
    clear_screen();
    andarS(&jogador,mapaPosicional);
    imprimir(mapaPosicional,jogador);
    getchar();
    //    printf("\n%d %d\n", jogador.posicao[0],jogador.posicao[1] );
     */
    /*
     * TODO função que avisa os encontros do jogador com os objetos e objetivos
     * retornar 0 para que nenhuma ação seja feita
     * retornar 1 para achou uma pokebola
     * retornar 2 para avisar que encontrou um pokemon porem não tinha pokebolas (o pokemon fugiu)
     * retornar 3 avisar que foi capturado um pokemon
     * retornar 4 avisar encontro com o estadio sem pokemons suficientes
     * retornar 5 encontro com o estadio com pokemons suficientes e inicio da batalha
     * 6 não conseguiu exito em pegar um pokemon
     * 7 movimento invalido
     */

    bool flow = true;
    char jogada;
    do{
        imprimir(mapaPosicional,jogador);
        printf("Faça a sua jogada: w/a/s/d ");
        scanf("%c",&jogada);
        getchar();
        switch (jogada) {
            case ('S'):
            case ('s'):
                andarS(&jogador,mapaPosicional);
                clear_screen();
                break;

            case ('W'):
            case ('w'):
                andarW(&jogador,mapaPosicional);
                clear_screen();
                break;

            case ('A'):
            case ('a'):
                andarA(&jogador,mapaPosicional);
                clear_screen();
                break;

            case ('D'):
            case ('d'):
                andarD(&jogador,mapaPosicional);
                clear_screen();
                break;

            default:
                clear_screen();
                printf("Você não digitou uma jogada válida\n");
                break;
        }
//        flow = false;
    }while (flow);


    return 0;
}
/**
 * são 56 espaços navegáveis porem [0,0] e [11,0] nao poderam recebar pokemons ou pokebolas
 * 0 espaços navegáveis
 * 2 espaços navegáveis com pokemons
 * 3 espaços navegáveis com pokebolas
 * 4 espaços não navegáveis
 * 5 estádio pokemon
 */
void injetarPokemonsPokebolas(int x[3][55],int mapa[12][10]){
    /*  3 vai representar as pokebolas
     *  2 vai representar os pokemons
     *  Vão ser inicializadas 15 pokebolas e 15 pokemons consumindo 30 dos 56 espaços disponíveis
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
    } while (y < 15);

    //pokebolas
    do{
        temp = rand() % 55;
        //pokebolas
        if(x[2][temp] == 0){
            x[2][temp] = -1;
            mapa[x[0][temp]][x[1][temp]] = 3;
            y++;
        }
    } while (y < 30);
}

/*
* ----retornar 0 para que nenhuma ação seja feita
* ---- retornar 1 para achou uma pokebola
* ---- retornar 2 para avisar que encontrou um pokemon porem não tinha pokebolas (o pokemon fugiu)
* ---- retornar 3 avisar que foi capturado um pokemon
* ---- retornar 4 avisar encontro com o estadio sem pokemons suficientes
* ---- retornar 5 encontro com o estadio com pokemons suficientes e inicio da batalha
* ---- 6 não conseguiu exito em pegar um pokemon
* -----7 movimento invalido
*/
int andarS(ash *jogador, int matriz[12][10]){
    srand(time(NULL));

    //espaços navegaveis comuns
    if(matriz[jogador -> posicao[0] + 1][jogador -> posicao[1]] == 0){
        jogador -> posicao[0]+=1;
//        matriz[jogador -> posicao[0] + 1][jogador -> posicao[1]] += 1;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return 0;
    }

        //movimento invalido
    else if(jogador -> posicao[0] + 1  > 11 || matriz[jogador -> posicao[0] + 1][jogador -> posicao[1]] == 4){
        return 7;
    }

        //encontro com pokemons
    else if(matriz[jogador -> posicao[0] + 1][jogador -> posicao[1]] == 2){
        jogador -> posicao[0]+=1;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        if(jogador -> pokebolas > 0){
            if(rand() % 100 < 80){
                //conseguiu pegar o pokemon P
                jogador -> pokemons++;
                jogador -> pokebolas--;
                return 3;
            }
            else
                //não teve exito em pegar o pokemon
                realocarPokemon(matriz,jogador);
            jogador -> pokebolas--;
            return 6;
        }else{
            //não tinha pokebolas , o pokemon fugiu
            matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
            realocarPokemon(matriz,jogador);
            return 2;
        }
    }
        //encontro com pokebolas
    else if(matriz[jogador -> posicao[0] + 1][jogador -> posicao[1]] == 3){
        jogador -> posicao[0]+=1;
        jogador -> pokebolas++;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return 1;
    }

    else if(matriz[jogador -> posicao[0] + 1][jogador -> posicao[1]] == 5){
        jogador -> posicao[0] += 1;
        if(jogador -> pokemons > 3){
            //Início do comabte
            return 5;
        } else{
            //Não tem pokemons suficientes para inicio do combate
            return 4;
        }
    }
}
int andarW(ash *jogador, int matriz[12][10]){
    srand(time(NULL));

    //espaços navegaveis comuns
    if(matriz[jogador -> posicao[0] - 1][jogador -> posicao[1]] == 0){
        jogador -> posicao[0]-=1;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return NADA;
    }

        //movimento invalido
    else if(jogador -> posicao[0] - 1  < 0 || matriz[jogador -> posicao[0] - 1][jogador -> posicao[1]] == 4){
        return 7;
    }

        //encontro com pokemons
    else if(matriz[jogador -> posicao[0] - 1][jogador -> posicao[1]] == 2){
        jogador -> posicao[0]-=1;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        if(jogador -> pokebolas > 0){
            if(rand() % 100 < 80){
                //conseguiu pegar o pokemon P
                jogador -> pokemons++;
                jogador -> pokebolas--;
                return 3;
            }
            else
                //não teve exito em pegar o pokemon
                realocarPokemon(matriz,jogador);
            jogador -> pokebolas--;
            return 6;
        }else{
            //não tinha pokebolas , o pokemon fugiu
            matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
            realocarPokemon(matriz,jogador);
            return 2;
        }
    }
        //encontro com pokebolas
    else if(matriz[jogador -> posicao[0] - 1][jogador -> posicao[1]] == 3){
        jogador -> posicao[0]-=1;
        jogador -> pokebolas++;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return 1;
    }

    else if(matriz[jogador -> posicao[0] - 1][jogador -> posicao[1]] == 5){
        jogador -> posicao[0] -= 1;
        if(jogador -> pokemons > 3){
            //Início do comabte
            return 5;
        } else{
            //Não tem pokemons suficientes para inicio do combate
            return 4;
        }
    }
}
int andarA(ash *jogador, int matriz[12][10]){
    srand(time(NULL));

    //espaços navegaveis comuns
    if(matriz[jogador -> posicao[0]][jogador -> posicao[1]-1] == 0){
        jogador -> posicao[1]-=1;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return 0;
    }

        //movimento invalido
    else if(jogador -> posicao[1] - 1  < 0 || matriz[jogador -> posicao[0]][jogador -> posicao[1]- 1] == 4){
        return 7;
    }

        //encontro com pokemons
    else if(matriz[jogador -> posicao[0]][jogador -> posicao[1] - 1] == 2){
        jogador -> posicao[1]-=1;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        if(jogador -> pokebolas > 0){
            if(rand() % 100 < 80){
                //conseguiu pegar o pokemon P
                jogador -> pokemons++;
                jogador -> pokebolas--;
                return 3;
            }
            else
                //não teve exito em pegar o pokemon
                realocarPokemon(matriz,jogador);
            jogador -> pokebolas--;
            return 6;
        }else{
            //não tinha pokebolas , o pokemon fugiu
            matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
            realocarPokemon(matriz,jogador);
            return 2;
        }
    }
        //encontro com pokebolas
    else if(matriz[jogador -> posicao[0]][jogador -> posicao[1] - 1] == 3){
        jogador -> posicao[1]-=1;
        jogador -> pokebolas++;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return 1;
    }

    else if(matriz[jogador -> posicao[0]][jogador -> posicao[1]- 1] == 5){
        jogador -> posicao[1] -= 1;
        if(jogador -> pokemons > 3){
            //Início do comabte
            return 5;
        } else{
            //Não tem pokemons suficientes para inicio do combate
            return 4;
        }
    }
}
int andarD(ash *jogador, int matriz[12][10]){
    srand(time(NULL));

    //espaços navegaveis comuns
    if(matriz[jogador -> posicao[0]][jogador -> posicao[1]+1] == 0){
        jogador -> posicao[1]+=1;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return 0;
    }

        //movimento invalido
    else if(jogador -> posicao[1] + 1  > 9 || matriz[jogador -> posicao[0]][jogador -> posicao[1]+ 1] == 4){
        return 7;
    }

        //encontro com pokemons
    else if(matriz[jogador -> posicao[0]][jogador -> posicao[1] + 1] == 2){
        jogador -> posicao[1]+=1;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        if(jogador -> pokebolas > 0){
            if(rand() % 100 < 80){
                //conseguiu pegar o pokemon P
                jogador -> pokemons++;
                jogador -> pokebolas--;
                return 3;
            }
            else
                //não teve exito em pegar o pokemon
                realocarPokemon(matriz,jogador);
            jogador -> pokebolas--;
            return 6;
        }else{
            //não tinha pokebolas , o pokemon fugiu
            matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
            realocarPokemon(matriz,jogador);
            return 2;
        }
    }
        //encontro com pokebolas
    else if(matriz[jogador -> posicao[0]][jogador -> posicao[1] + 1] == 3){
        jogador -> posicao[1]+=1;
        jogador -> pokebolas++;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return 1;
    }

    else if(matriz[jogador -> posicao[0]][jogador -> posicao[1]+ 1] == 5){
        jogador -> posicao[1] += 1;
        if(jogador -> pokemons > 3){
            //Início do comabte
            return 5;
        } else{
            //Não tem pokemons suficientes para inicio do combate
            return 4;
        }
    }
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
    }
}

void clear_screen(){
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#else
#endif
}
