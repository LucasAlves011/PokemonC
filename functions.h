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


typedef struct {
    int posicao[2];
    int pokemons;
    int pokebolas;
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

void apresentar();
void clear_screen();
void feedbackMovimento(int retorno);
int andarW( ash *jogador, int matriz[12][10]);
int andarA( ash *jogador, int matriz[12][10]);
int andarS( ash *jogador, int matriz[12][10]);
int andarD( ash *jogador, int matriz[12][10]);

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
