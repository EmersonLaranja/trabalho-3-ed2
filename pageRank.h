#ifndef PAGERANK_H
#define PAGERANK_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "page.h"
typedef struct pagerank PageRank;

/**
 * Retorna um inteiro dizendo se o fim do cáculo já ocorreu ou não
 * @param[pages] array da estrutura pageRank
 * @param[N] variável com o valor da quantidade de page contidas no array [pages]
 * @return variável com o valor resultado da função, 0 ou 1;
 **/
int finishedCalculation(PageRank **pages, int N);

/**
 * Retorna a soma do rank de uma page
 * @param[pages] array da estrutura pageRank
 * @param[id] variável com o valor do id da page contida no array [pages]
 * @return variável com o valor resultado da soma;
 **/
double sumOperation(PageRank **pages, int id);

/**
 * Calcula o rank de todas as page contidas no array [pagesAux]
 * @param[pagesAux] array da estrutura page
 * @param[numPages] variável com o valor da quantidade de page contida no array [pagesAux]
 **/
void pageRank(Page **pagesAux, int numPages);

#endif