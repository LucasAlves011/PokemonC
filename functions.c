#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "cert-msc51-cpp"
//
// Created by lucas on 09/11/2021.
//
#include "functions.h"

void clear_screen(){
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#else
#endif
}

int andarS(ash *jogador, int matriz[12][10],bool *flow){
    srand(time(NULL));
    setlocale(LC_ALL,"Portuguese");

    //movimento invalido
     if(jogador -> posicao[0] + 1  > 11 || matriz[jogador -> posicao[0] + 1][jogador -> posicao[1]] == 4){
        return MOVIMENTO_INVALIDO;
    }

    //espaços navegaveis comuns
    else if(matriz[jogador -> posicao[0] + 1][jogador -> posicao[1]] == 0){
        jogador -> posicao[0]+=1;
//        matriz[jogador -> posicao[0] + 1][jogador -> posicao[1]] += 1;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return NADA;
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
                return POKEMON_OBTIDO;
            }
            else
                //não teve exito em pegar o pokemon
                realocarPokemon(matriz,jogador);
            jogador -> pokebolas--;
            return FUGA_POKEMON;
        }else{
            //não tinha pokebolas , o pokemon fugiu
            matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
            realocarPokemon(matriz,jogador);
            return FUGA_POKEBOLA_INSU;
        }
    }
        //encontro com pokebolas
    else if(matriz[jogador -> posicao[0] + 1][jogador -> posicao[1]] == 3){
        jogador -> posicao[0]+=1;
        jogador -> pokebolas++;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return POKEBOLA_OBTIDA;
    }

    else if(matriz[jogador -> posicao[0] + 1][jogador -> posicao[1]] == 5){
        jogador -> posicao[0] += 1;
        if(jogador -> pokemons >= 3){
            //Início do comabte
            *flow = false;
            return ESTADIO_BATALHA;
        } else{
            //Não tem pokemons suficientes para inicio do combate
            return ESTADIO_POKEMON_INSU;
        }
    }
}
int andarW(ash *jogador, int matriz[12][10],bool *flow){
    srand(time(NULL));

    //movimento invalido
    if(jogador -> posicao[0] - 1  < 0 || matriz[jogador -> posicao[0] - 1][jogador -> posicao[1]] == 4){
        return MOVIMENTO_INVALIDO;
    }

    //espaços navegaveis comuns
    else if(matriz[jogador -> posicao[0] - 1][jogador -> posicao[1]] == 0){
        jogador -> posicao[0]-=1;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return NADA;
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
                return POKEMON_OBTIDO;
            }
            else
                //não teve exito em pegar o pokemon
                realocarPokemon(matriz,jogador);
            jogador -> pokebolas--;
            return FUGA_POKEMON;
        }else{
            //não tinha pokebolas , o pokemon fugiu
            matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
            realocarPokemon(matriz,jogador);
            return FUGA_POKEBOLA_INSU;
        }
    }
        //encontro com pokebolas
    else if(matriz[jogador -> posicao[0] - 1][jogador -> posicao[1]] == 3){
        jogador -> posicao[0]-=1;
        jogador -> pokebolas++;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return POKEBOLA_OBTIDA;
    }

    else if(matriz[jogador -> posicao[0] - 1][jogador -> posicao[1]] == 5){
        jogador -> posicao[0] -= 1;
        if(jogador -> pokemons >= 3){
            //Início do comabte
            *flow = false;
            return ESTADIO_BATALHA;
        } else{
            //Não tem pokemons suficientes para início do combate
            return ESTADIO_POKEMON_INSU;
        }
    }
}
int andarA(ash *jogador, int matriz[12][10],bool *flow){
    srand(time(NULL));

    //movimento invalido
     if(jogador -> posicao[1] - 1  < 0 || matriz[jogador -> posicao[0]][jogador -> posicao[1]- 1] == 4){
        return MOVIMENTO_INVALIDO;
    }

    //espaços navegaveis comuns
    else if(matriz[jogador -> posicao[0]][jogador -> posicao[1]-1] == 0){
        jogador -> posicao[1]-=1;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return NADA;
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
                return POKEMON_OBTIDO;
            }
            else
                //não teve exito em pegar o pokemon
                realocarPokemon(matriz,jogador);
            jogador -> pokebolas--;
            return FUGA_POKEMON;
        }else{
            //não tinha pokebolas , o pokemon fugiu
            matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
            realocarPokemon(matriz,jogador);
            return FUGA_POKEBOLA_INSU;
        }
    }
        //encontro com pokebolas
    else if(matriz[jogador -> posicao[0]][jogador -> posicao[1] - 1] == 3){
        jogador -> posicao[1]-=1;
        jogador -> pokebolas++;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return POKEBOLA_OBTIDA;
    }

    else if(matriz[jogador -> posicao[0]][jogador -> posicao[1]- 1] == 5){
        jogador -> posicao[1] -= 1;
        if(jogador -> pokemons >= 3){
            //Início do comabte
            *flow = false;
            return ESTADIO_BATALHA;
        } else{
            //Não tem pokemons suficientes para inicio do combate
            return ESTADIO_POKEMON_INSU;
        }
    }
}
int andarD(ash *jogador, int matriz[12][10],bool *flow){
    srand(time(NULL));

    //movimento invalido
    if(jogador -> posicao[1] + 1  > 9 || matriz[jogador -> posicao[0]][jogador -> posicao[1]+ 1] == 4){
        return MOVIMENTO_INVALIDO;
    }

    //espaços navegaveis comuns
    else if(matriz[jogador -> posicao[0]][jogador -> posicao[1]+1] == 0){
        jogador -> posicao[1]+=1;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return NADA;
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
                return POKEMON_OBTIDO;
            }
            else
                //não teve exito em pegar o pokemon
                realocarPokemon(matriz,jogador);
            jogador -> pokebolas--;
            return FUGA_POKEMON;
        }else{
            //não tinha pokebolas , o pokemon fugiu
            matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
            realocarPokemon(matriz,jogador);
            return FUGA_POKEBOLA_INSU;
        }
    }
        //encontro com pokebolas
    else if(matriz[jogador -> posicao[0]][jogador -> posicao[1] + 1] == 3){
        jogador -> posicao[1]+=1;
        jogador -> pokebolas++;
        matriz[jogador -> posicao[0]][jogador -> posicao[1]] = 0;
        return POKEBOLA_OBTIDA;
    }

    else if(matriz[jogador -> posicao[0]][jogador -> posicao[1]+ 1] == 5){
        jogador -> posicao[1] += 1;
        if(jogador -> pokemons >= 3){
            //Início do combata
            *flow = false;
            return ESTADIO_BATALHA;
        } else{
            //Não tem pokemons suficientes para inicio do combate
            return ESTADIO_POKEMON_INSU;
        }
    }
}

#pragma clang diagnostic pop