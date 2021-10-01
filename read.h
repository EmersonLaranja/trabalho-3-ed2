#ifndef READ_H
#define READ_H
#include <string.h>
#include <ctype.h>
#include "tst.h"
#include "pageRank.h"
#define MAX_WORD_SIZE 500

/**
 * Retorna um inteiro dizendo se a variável word é uma stopWord ou não
 * @param[word] variável com o valor de uma palavra lida
 * @param[stopWords] lista de palavras
 * @param[numStopWords] variável com o valor da quantidade de palavras contidas no array [numStopWords]
 * @return variável com o valor resultado da função, 0 ou 1;
 **/
int isStopWord(char *word, char **stopWords, int numStopWords);

/**
 * Verifica a quantidade de argumentos passados no inicio do programa
 * @param[numArgs] variável com o valor da quantidade de argumenros passados;
 **/
void verifyArgsLength(int numArgs);

/**
 * Verifica se um detreminado arquivo foi aberto com sucesso ou não
 * @param[file] variável do arquivo;
 * @param[fileName] variável com o nome do arquivo;
 **/
void verifyFileWasOpened(FILE *file, const char *fileName);

/**
 * Faz a leitura e o preenchimento de um array de estruturas Page.
 * @param[file] variável do arquivo a ser aberto;
 * @param[numberPages] variável com a quantidade de páginas a serem lidas;
 * @return ponteiro alocado e preenchido de um array da estrutura Page
 **/
Page **getPages(FILE *file, int *numberPages);

/**
 * Faz a leitura e o preenchimento de um array palavras com as stopWords.
 * @param[file] variável do arquivo a ser aberto;
 * @param[numberStopWords] variável com a quantidade de stopWords a serem lidas;
 * @return array de palavras
 **/
char **getStopWords(FILE *file, int *numberStopWords);

/**
 * Faz a concatenação do path base e o nome do arquivo a ser aberto.
 * @param[fileName] variável com o nome do arquivo a ser aberto;
 * @param[basePath] variável nome do path base onde os arquivos estão contidos;
 * @return variável com o valor do caminho completo até o arquivo com o [fileName]
 **/
char *getCompletePath(char *basePath, char *fileName);

/**
 * Faz a busca com as searchWords dentro do conteudo das page contidas no array da estrutura page e imprime os resultados da busca.
 * @param[basePath] variável nome do path base onde os arquivos estão contidos;
 * @param[numberPages] variável com a quantidade de page contidas no array de estrutura page
 * @param[pages] array da estrutura page
 * @param[tst] estrutura tst
 **/
void getSearchWords(char *basePath, int numberPages, Page **pages, Tst *tst);

/**
 * Faz a leitura e o preenchimento dos links de cada page contida no array de page
 * @param[file] variável do arquivo;
 * @param[numberPages] variável com a quantidade de page contidas no array de estrutura page
 * @param[pages] array da estrutura page
 **/
void readLinksOut(FILE *file, Page **pages, int numberPages);

/**
 * Faz a leitura das pages preenchedo as que não forem stopWords na estrutura tst
 * @param[basePath] variável nome do path base onde os arquivos estão contidos;
 * @param[numberPages] variável com a quantidade de page contidas no array de estrutura page
 * @param[pages] array da estrutura page
 * @param[stopWords] lista de palavras
 * @param[numStopWords] variável com o valor da quantidade de palavras contidas no array [numStopWords]
 * @param[tst] estrutura tst
 * @return estrutura tst alocada e preenchida
 **/
Tst *readPages(Page **pages, int numberPages, char **stopWords, int numStopWords, Tst *tst, char *basePath);

/**
 * Converte uma palavra com caracteres maiusculos para minusculos
 * @param[word] variável com o valor da palavra
 **/
void toLowerCase(char *word);

/**
 * Realiza a comparação entre as páginas
 * @param[a] variavel da estrutura page
 * @param[b] variavel da estrutura page
 * @return inteiro com o resultado da comparação
 **/
int comparePages(const void *a, const void *b);

/**
 * Realiza a orndenação do array de page
 * @param[pages] array da estrutura page
 * @param[numPages] variavel com a quantidade de page dentro do array de estruturas page
 **/
void sortPage(Page **pages, int numPages);

#endif /* READ_H */