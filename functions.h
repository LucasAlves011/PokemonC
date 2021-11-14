//
// Created by lucas on 09/11/2021.
//

#ifndef POKEMONC_FUNCTIONS_H
#define POKEMONC_FUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <unistd.h>
#include <string.h>

typedef struct nome_pokemon{
    char nome[25];
    char cor[10];
    struct nome_pokemon * proximo;
}nome_pokemon;

typedef struct {
    int posicao[2];
    int pokemons;
    int pokebolas;
    struct nome_pokemon * inicio;
}ash;

#define NADA 0
#define POKEBOLA_OBTIDA 1
#define FUGA_POKEBOLA_INSU 2
#define POKEMON_OBTIDO 3
#define ESTADIO_POKEMON_INSU 4
#define ESTADIO_BATALHA 5
#define FUGA_POKEMON 6
#define MOVIMENTO_INVALIDO 7

//Texto em negrito e em cores
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"
#define RST "\e[0m"

void listarPokemons(ash *jogador);
void adicionarPokemon(char nome[],ash *jogador,char cor[]);
void imprimirDelay(char msg[],int delay);
void apresentar();
void apresentarControles();
void clear_screen();
void feedbackMovimento(int retorno, ash * jogador);
int andarW( ash *jogador, int matriz[12][10],bool *flow);
int andarA( ash *jogador, int matriz[12][10],bool *flow);
int andarS( ash *jogador, int matriz[12][10],bool *flow);
int andarD( ash *jogador, int matriz[12][10],bool *flow);

//cores
void red();
void green();
void yellow();
void blue();
void purple();
void cyan();
void black();
void reset();

void realocarPokemon(int matriz[12][10],ash *jogador);

#endif //POKEMONC_FUNCTIONS_H
