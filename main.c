#include <stdio.h>
#include <stdbool.h>

//typedef struct {
//    char nome[10];
//    int idade;
//}aluno;

void imprimir(char para[10][12]){
    for (int i = 0; i < 10; ++i) {
        if(i == 0){
            for (int j = 0; j < 10; ++j) {
                printf("%d ",j);
            }
            printf("\n");
        }
        for (int j = 0; j < 12; ++j) {
            printf("%c ",para[i][j]);
        }
        printf("\n");
    }
}


#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
int main() {

    char mapa[10][12];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 12; ++j) {
            mapa[i][j] = '_';
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 12; ++j) {
            switch (j) {
                case 0:
                    if( i == 5 || i == 6 || (i > 7 && i < 11))
                        mapa[i][j] = 'X';
                    break;
                case 1:
                    if((i > 0 && i < 4) || i == 5 || i == 6 || i == 8 || i == 10)
                        mapa[i][j]='X';
                    break;
                case 2:
                    if((i > 0 && i < 4) || i ==8 || i ==10)
                        mapa[i][j]='X';
                    break;
                case 3:
                    if(i > 0 && i < 7)
                        mapa[i][j]= 'X';
                    break;
                case 4:
                    if(i == 1 || i == 2 || i ==8 || i == 10 || i == 11)
                        mapa[i][j]='X';
                    break;
                case 5:
                    if((i > 0 && i <5) || i ==6 || i ==8)
                        mapa[i][j] = 'X';
                    break;
                case 6:
                    if(i >3 && i <= 11)
                        mapa[i][j]='X';
                    break;
                case 7:
                    if((i >= 0 && i <3) || (i > 3 && i < 7))
                        mapa[i][j]='X';
                    break;
                case 8:
                    if(i > 7 && i <= 11)
                        mapa[i][j]='X';
                    break;
                case 9:
                    if(i>0 && i <= 11)
                        mapa[i][j]='X';
                    break;
                default:
                    break;
            }
        }
    }

    imprimir(mapa);
//    bool continuar = true;
//    int ashe[2] = {0,0};
//
//
//    //iniciar lop do jogo
//    do{
//
//
//
//
//
//
//    }while (continuar);

    return 0;
}
#pragma clang diagnostic pop
