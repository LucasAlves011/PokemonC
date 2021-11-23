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

/** As funções de movimento W/A/S/D retornam os seguintes números:
* ----retornar 0 para que nenhum feedback seja dado
* ---- retornar 1 para achou uma pokebola
* ---- retornar 2 para avisar que encontrou um pokemon porem não tinha pokebolas (o pokemon fugiu)
* ---- retornar 3 avisar que foi capturado um pokemon
* ---- retornar 4 avisar encontro com o estadio sem pokemons suficientes
* ---- retornar 5 encontro com o estadio com pokemons suficientes e inicio da batalha
* ---- 6 não conseguiu exito em pegar um pokemon
* -----7 movimento invalido
*/

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

void adicionarPokemon(char novoNome[] , ash *jogador , char cor[]){
    nome_pokemon *novo = (nome_pokemon *) malloc(sizeof(nome_pokemon));
    nome_pokemon *temp = (nome_pokemon *) malloc(sizeof(nome_pokemon));
    strcpy(novo->nome,novoNome);
    strcpy(novo->cor,cor);
    novo -> proximo = NULL;
    if(jogador->inicio == NULL) {
        jogador->inicio = novo;
        jogador->inicio->anterior = NULL;
    }
    else{
        temp = jogador->inicio;
        while(temp->proximo != NULL)
            temp = temp->proximo;
        novo -> anterior = temp;
        temp -> proximo = novo;
    }
    jogador->tamanho++;
}

nome_pokemon selecionarPokemon(ash *jogador, nome_pokemon listaSelecionados[3]){
    int index;
    bool first = true;
    struct nome_pokemon * temp = jogador->inicio;
    do{
        first == true ? first = false : printf(BRED"Digite um número VÁLIDO a um pokemon !"RST);
        listarPokemons(jogador);
        printf("\nSeu time: \n");
        for (int i = 0; i < 3; ++i)
            //TODO As vezes ele imprime lixo aqui, concertar futuramente
            printf("%d - %s%s\t"RST,(i+1),listaSelecionados[i].cor,listaSelecionados[i].nome);
        printf("\n");

        printf("\nDigite o index do pokemon que você vai querer que componha seu time contra Brock: ");
        scanf("%d", &index);
        clear_screen();
    } while (index < 0 || index > jogador -> tamanho);

    for (int i = 1; i < index ; ++i) {
        temp = temp->proximo;
    }

    if(temp-> anterior  == NULL && temp-> proximo  == NULL ) {
        //poderia colocar um return *temp aqui mas por boas práticas vou deixa-lo somento no final.
    }
    else if(temp-> anterior  == NULL) {
        temp-> proximo -> anterior = NULL;
        jogador -> inicio = temp -> proximo;
        temp -> proximo = NULL;
    }
    else if(temp -> proximo == NULL) {
        temp->anterior->proximo = NULL;
        temp -> anterior = NULL;
    }
    else {
        temp->anterior->proximo = temp->proximo;
        temp->proximo->anterior = temp->anterior;
    }
    jogador -> tamanho--;
    return *temp;
}


#pragma clang diagnostic pop