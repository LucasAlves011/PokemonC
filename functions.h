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



void clear_screen();

int andarW( ash *jogador, int matriz[12][10]);
int andarA( ash *jogador, int matriz[12][10]);
int andarS( ash *jogador, int matriz[12][10]);
int andarD( ash *jogador, int matriz[12][10]);

void realocarPokemon(int matriz[12][10],ash *jogador);

#endif //POKEMONC_FUNCTIONS_H
