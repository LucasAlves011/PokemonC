#include <stdio.h>
#include <stdbool.h>

//typedef struct {
//    char nome[10];
//    int idade;
//}aluno;
bool andarW(int ash[]);
void andarA();
void andarS();
void andarD();
bool checar();

void imprimir(char para[12][10]){
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
            printf("%c ",para[i][j]);
        }
        printf("\n");
        condicao = true;
    }
}

//inicializar valores com _
char mapa[12][10];

int main() {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 10; ++j) {
            mapa[i][j] = '_';
        }
    }
    int ash[2] = {0,0};
    //adicionar obstáculos e posição do Ash
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 10; ++j) {
            switch (j) {
                case 0:
                    if(i == 0){
                        mapa[i][j] = 'A';
                    }
                    else if( i == 5 || i == 6 || (i > 7 && i <= 11))
                        if( i == 11) {
                            mapa[i][j] = 'E';
                        } else {
                            mapa[i][j] = 'X';
                        }
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





    return 0;
}
//MAPA[][] ASH[0,0]
bool andarW(int ash[]){
    if((mapa[ash[0] - 1]) > 0 ){
        if(mapa[ash[0]-1][ash[1]] == '_'){
            ash[0] -= 1;
            return true;
        } else if(mapa[ash[0]-1][ash[1]] == 'X'){
            return false;
        }
    }
    return false;
}

