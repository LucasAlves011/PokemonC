#include <stdio.h>
#include <stdbool.h>

/**
 * 0 espaços navegáveis
 * 1 espaços navegáveis com pokebolas
 * 2 espaços navegáveis com pokemons
 * 4 espaços não navegáveis
 * 5 estádio pokemon
 */
typedef struct {
    int posicao[2];
    int pokemons;
    int pokebolas;
}ash;

void andarW( ash jogador, int matriz[12][10]);
void andarA( ash jogador, int matriz[12][10]);
void andarS( ash *jogador, int matriz[12][10]);
void andarD( ash jogador, int matriz[12][10]);

void imprimir(int para[12][10]){
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
            printf("%d ",para[i][j]);
        }
        printf("\n");
        condicao = true;
    }
//    printf("\n");
}

int main() {
    //iniciando os status do jogador
    ash jogador;
    jogador.posicao[0] = 0;
    jogador.posicao[1] = 0;
    jogador.pokebolas = 0;
    jogador.pokemons = 0;

    int mapaPosicional[12][10] = {0};

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
                        mapaPosicional[i][j]=4;
                    break;
                case 2:
                    if((i > 0 && i < 4) || i ==8 || i ==10)
                        mapaPosicional[i][j]=4;
                    break;
                case 3:
                    if(i > 0 && i < 7)
                        mapaPosicional[i][j]= 4;
                    break;
                case 4:
                    if(i == 1 || i == 2 || i ==8 || i == 10 || i == 11)
                        mapaPosicional[i][j]=4;
                    break;
                case 5:
                    if((i > 0 && i <5) || i ==6 || i ==8)
                        mapaPosicional[i][j] = 4;
                    break;
                case 6:
                    if(i >3 && i <= 11)
                        mapaPosicional[i][j]=4;
                    break;
                case 7:
                    if((i >= 0 && i <3) || (i > 3 && i < 7))
                        mapaPosicional[i][j]=4;
                    break;
                case 8:
                    if(i > 7 && i <= 11)
                        mapaPosicional[i][j]=4;
                    break;
                case 9:
                    if(i>0 && i <= 11)
                        mapaPosicional[i][j]=4;
                    break;
                default:
                    break;
            }
        }
    }

    imprimir(mapaPosicional);
    printf("\n%d %d\n", jogador.posicao[0],jogador.posicao[0] );
    andarS(&jogador,mapaPosicional);
    imprimir(mapaPosicional);
    printf("\n%d %d\n", jogador.posicao[0],jogador.posicao[0] );


    return 0;
}

void andarS(ash *jogador, int matriz[12][10]){
    if(matriz[jogador -> posicao[0] + 1][jogador -> posicao[1]] == 0){
        jogador -> posicao[0]+=1;
    }
}
