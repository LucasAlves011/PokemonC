# PokemonC
Questão proposta pelo professor [Péricles Miranda](https://www.linkedin.com/in/pbcm/?originalSubdomain=br). Tomei a liberdade de fazer algumas 
alterações para deixar o jogo mais interessante.

Você é Ash Ketchum (A), um treinador Pokemon. O seu sonho é competir em um estádio Pokemon (E). Só que para isso você precisa ter 3
Pokemons. Como Ash não possui pokebolas no início, para capturar pokemons, antes ele deve encontrá-las. Caso Ash encontre um pokemon sem
possuir pokebolas disponíveis, o pokemon foge, desaparecendo do mapa. Caso Ash possua pokebolas disponíveis e passe por um pokemon, ele
tem 80% de chance de capturá-lo. Caso não capture, o pokemon foge do mapa.


O mapa abaixo mostra a posição de Ash (A) e de um estádio Pokemon (E). As células escuras são caminhos navegáveis, as células brancas não são
navegáveis. Pokemons e pokebolas só podem ser inicializados em células escuras.

![Alt text](https://github.com/LucasAlves011/PokemonC/blob/016b8ea957344082a984bcb706cba1c80383aa43/Captura%20de%20tela%20de%202021-10-31%2002-42-32.png "Optional title")

Caso Ash chegue ao estádio sem ao menos 3 pokemons, informe que ele não tem requisitos para competir. Caso contrário, ele competirá. No
estádio Pokemon, Ash enfrentará Brock em uma batalha 3 contra 3. 
Você e Brock selecionam 3 pokemons cada, e coloca 1 a 1 para batalhar.
<!--Você e Brock jogam 3 dados cada com valores de 1 a 10. Aquele que obtiver a maior pontuação, vence a batalha Pokemon. Em seguida, os
próximos pokemons batalham. Esse processo continua até que haja um vencedor.
-->

Você e Brock jogam dois dados no início de cada round para saber quem vai começar atacando.
A partir disso, os oponentes intercalam rodadas de ataque e de defesa. Mais dois dados são lançados,
se você tiver a maior pontuação em sua rodada de ataque, o pokemon de brock sofrerá 100 de dano, mas se a pontuação de brock for superior a sua,
o seu pokemon que sofrerá 50 de dano. Essa regra, de maneira invertida, também vai valer para a roda de ataque do Brock.

Caso você vença Brock, você ganha a insígnia da pedra.