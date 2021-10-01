#ifndef TST_H
#define TST_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "page.h"
typedef struct tst Tst;

/**
 * Aloca e inicia a estrutura Tst.
 * @param[letter] variável com o conteudo do nó da tst
 * @param[numberPages] quantidade de pages
 * @return ponteiro alocado e com as variáveis acima inicializadas;
 **/
Tst *initTst(char letter, int numberPages);

/**
 * Insere uma palavra em um novo nó na estrutura tst.
 * @param[page] variável da estrutura page
 * @param[word] variável com o conteudo da palavra
 * @param[numberPages] quantidade de pages
 * @param[root] variável com o array de estrutura de tst
 **/
void insert(Tst **root, char *word, int numberPages, Page *page);

/**
 * Percorre a tst e imprime seu conteudo
 * @param[buffer] variável para armazenar os caracteres
 * @param[depth] variável com a posição do caracter dentro do array de char [buffer]
 * @param[root] variável com a estrutura de tst
 **/
void traverseTstUtil(Tst *root, char *buffer, int depth);

/**
 * Percorre a tst e imprime seu conteudo chamando a função anterior
 * @param[root] variável com a estrutura de tst
 **/
void traverseTst(Tst *root);

/**
 * Percorre a tst e retorna a lista de páginas que contem a palavra buscada
 * @param[word] variável com o conteudo da palavra
 * @param[root] variável com a estrutura de tst
 * @return array da estrutura page
 **/
Page **searchTST(Tst *root, char *word);

/**
 * Libera o espaço de memória alocado para a estrutura tst
 * @param[root] variável com a estrutura de tst
 **/
void destroyTST(Tst *root);

#endif