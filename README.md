# Dama com Vovô


Mesmo com poucos dias de férias, como é tradicional de sua família, você resolveu passar alguns
dias com seu avô. Ele já está bem velhinho e sempre fica muito feliz com suas visitas. Uma das
diversões preferidas do vovô é jogar dama com você, não apenas jogar, mas te dar uma verdadeira
surra. Depois desses poucos dias com seu avô e de várias surras na dama, você resolveu utilizar seus
conhecimentos em Ciência da Computação para tentar surpreender seu velho amigo na próxima
folga (E você achava que AEDSIII não te serveria para nada né?)
O Jogo de Damas, inventado a mais de 4.000 anos atrás possui várias variações ao redor do
mundo. Trata-se de um jogo de tabuleiro para dois jogadores, cujo tabuleiro é quadrado com 8x8
pequenos quadrados que são alternadamente coloridos com uma cor clara e uma cor escura, no
padrão usual de um tabuleiro de damas (os quadrados de cor escura é que são as casas). O Jogo
de damas jogados entre você e seu avô é um porquinho diferente. O tabuleiro é retangular, com N
linhas e M colunas, ou seja, nem sempre é um tabuleiro quadrado e o número de pequenos quadrados
pode mudar a cada novo jogo (seu avô gosta de inovar e supreender para tornar mais divertida a
brincadeira!).


No início do jogo, cada jogador (você e seu avô) tem um certo número de peças, posicionadas
nas casas mais próximas da borda do tabuleiro que cada um escolher (sempre bordas opostas).
Durante o jogo, as peças só podem ocupar as casas do tabuleiro. Um dos movimentos do jogo é
capturar uma peça do oponente (vovô chama de comer a peça), saltando sobre ela, diagonalmente,
para a casa adjacente além da peça, casa esta que deve estar vazia. A peça do oponente é então
removida do tabuleiro. As três casas envolvidas na captura (a casa inicial, a que contém a peça
do oponente e a vazia, onde sua peça estará após a jogada) devem estar diagonalmente alinhadas e
devem ser diagonalmente adjacentes. Na Dama do Vovô uma peça pode capturar peças do oponente
saltando diagonalmente para a frente ou para trás (seu avô é o cara!). Você pode também efetuar
uma captura múltipla, com uma peça apenas, saltando seguidamente para casas vazias sobre peças
oponentes, podendo mudar de direção, saltando primeiro em uma direção e depois em outra. Você
pode capturar apenas uma peça a cada salto, mas pode capturar várias peças com saltos seguidos.
Você não pode saltar sobre uma peça sua, e não pode saltar a mesma peça oponente mais de uma
vez.


Dadas as dimensões do tabuleiro e uma descrição do estado corrente de um jogo, na sua jogada
você deve determinar computacionalmente o número máximo de peças do seu oponente que podem
ser capturadas em um movimento de captura. E claro, você não pode demorar muito a determinar
sua jogada!


Assim, seu objetivo nesse trabalho é implementar duas estratégias para solucionar esse problema:
• Uma estratégia força bruta;
• Um estratégia alternativa que seja capaz de sempre resolver o problema, tentando o mínimo
de movimentos;


Entrada e Saída
A entrada contém vários casos de teste. A primeira linha de um caso de teste contém dois
inteiros N e M indicando respectivamente o número de linhas e o número de colunas do tabuleiro
(3 ≤ N ≤ 20, 3 ≤ M ≤ 20 e N × M ≤ 200). O quadrado mais à esquerda do tabuleiro na borda
mais próxima ao jogador é uma casa. A segunda linha contém a descrição do estado do jogo.
Cada descrição consiste de (N × M)/2 inteiros, separados por um espaço, correspondendo às
casas do tabuleiro, que são numeradas de 1 a (N × M)/2, da esquerda para a direita, da borda
mais próxima ao jogador à borda mais próxima ao seu oponente. Na descrição do estado do jogo, 0
representa uma casa vazia, 1 representa uma casa com uma de suas peças, e 2 representa uma casa
com uma peça de seu oponente. Há no máximo (N × M)/4 peças de cada jogador no tabuleiro. O
final da entrada é indicado por N = M = 0.


Exemplo de entrada:

3 3

2 1 2 0 1

5 3

1 0 2 1 0 2 0 0

8 8

2 2 2 2 0 0 0 0 2 2 2 2 0 0 0 0 2 2 2 2 0 0 0 0 2 2 2 2 0 1 0 0

0 0

Exemplo de saída

1

2

7
