#ifndef PAGE_H
#define PAGE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"

typedef struct page Page;

/**
 * Aloca e inicia a estrutura Page.
 * @param[name] variável com o nome da página
 * @param[id] variável com o id da página
 * @return ponteiro alocado e com as variáveis acima inicializadas;
 **/
Page *initPage(char *name, int id);

/**
 * Retorna o nome de uma Page.
 * @param[page] estrutura page
 * @return string com o nome da Page;
 **/
char *getPageName(Page *page);

/**
 * Retorna o numero de links (In) de uma Page.
 * @param[page] estrutura page
 * @return int com a quantidade de links (In) de uma Page;
 **/
int getNumberLinksIn(Page *page);

/**
 * Retorna o numero de links (Out) de uma Page.
 * @param[page] estrutura page
 * @return int com a quantidade de links (Out) de uma Page;
 **/
int getNumberLinksOut(Page *page);

/**
 * Retorna o id de uma Page.
 * @param[page] estrutura page
 * @return int com o valor do id da Page;
 **/
int getPageId(Page *page);

/**
 * Retorna o page rank de uma Page.
 * @param[page] estrutura page
 * @return double com o valor do pange rank da Page;
 **/
double getPageRank(Page *page);

/**
 * Busca uma page específica dado o nome em um array de Page.
 * @param[pages] array da estrutura page
 * @param[numPages] variável com a quantidade de páginas no array de Page
 * @param[name] variável com o nome de uma page a ser buscado no array
 * @return ponteiro de uma estrutura Page ou NULL caso não encontre a page
 **/
Page *getPageByName(Page **pages, int numPages, char *name);

/**
 * Altera o valor do atributo [linksIn] da variável page.
 * @param[page] variável da estrutura page
 * @param[links] array da estrutura page, contendo os links para outras page
 * @param[numLinks] variável com a quantidade de links do array de page
 **/
void setPageLinksOut(Page *page, Page **links, int numLinks);

/**
 * Altera o valor do atributo [linksOut] da variável page.
 * @param[page] variável da estrutura page
 * @param[links] array da estrutura page, contendo os links para outras page
 * @param[numLinks] variável com a quantidade de links do array de page
 **/
void setPageLinksIn(Page *page, Page **pages, int numPages);

/**
 * Retorna um ponteiro para uma page dento da variável [linksIn] da estrutura page
 * @param[page] variável da estrutura page
 * @param[index] variável com o valor do index da page desejada dentro do array [linksIn]
 * @return ponteiro para a page com o valor da variavel index
 **/
Page *getLinkInPage(Page *page, int index);

/**
 * Altera o valor do atributo [id] da variável page.
 * @param[page] variável da estrutura page
 * @param[id] variável com o valor do id da page
 **/
void setPageId(Page *page, int id);

/**
 * Retorna um ponteiro para uma page dento da variável [linksOut] da estrutura page
 * @param[page] variável da estrutura page
 * @param[index] variável com o valor do index da page desejada dentro do array [linksOut]
 * @return ponteiro para a page com o valor da variavel index
 **/
Page *getLinkOutPage(Page *page, int index);

/**
 * Altera o valor do atributo [rank] da variável page.
 * @param[page] variável da estrutura page
 * @param[rank] variável com o valor do rank da page
 **/
void setPageRank(Page *page, double rank);

/**
 * Retorna um ponteiro para uma page contida em um array da estrutura page
 * @param[pages] array da estrutura page
 * @param[numPages] variável com o valor da quantidade de page dentro do array [pages]
 * @param[id] variável com o valor do id da page
 * @return ponteiro para a page com o valor da variavel id
 **/
Page *getPageById(Page **pages, int numPages, int id);

/**
 * Libera o espaço de memória alocado para as variáveis da estrutura page
 * @param[page] variavel da estrutura page
 **/
void destroyPage(Page *page);

/**
 * Libera o espaço de memória alocado para as variáveis de um array da estrutura page
 * @param[pages] array da estrutura page
 * @param[numberPages] variável com o valor do numero de page contidas no array [pages]
 **/
void destroyPageArray(Page **pages, int numberPages);

#endif