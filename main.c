#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "page.h"

int main(int argc, char const *argv[])
{
  //Ler index.txt e retornar a quantidade de paginas

  verifyArgsLength(argc);
  FILE *fileIn = fopen(argv[1], "r");
  verifyFileWasOpened(fileIn);

  int numberPages = 0;
  Page **pages;
  pages = getPages(fileIn, &numberPages);

  printf("NumberPages = %d\n", numberPages);

  for (int i = 0; i < numberPages; i++)
  {
    printPage(pages[i]);
  }

  //Ler graph.txt
  //FILE *graphFile = fopen('graph.txt', "r");
  //getLinks(graphFile, pages, numberPages);

  //Ler stopWords em um vetor de stopwords
  char **stopWords;
  int numberStopWords = 0;

  FILE *stopWordsFile = fopen("./input/stopwords.txt", "r");
  if (stopWordsFile == NULL)
    printf("Error opening stopwords");
  // stopWords = getStopWords(stopWordsFile, &numberStopWords);

  // printf("NumberStopords = %d\n", numberStopWords);

  // for (int i = 0; i < numberStopWords; i++)
  // {
  //   printf("StopWords[%d]: %s\n", i, stopWords[i]);
  // }

  return 0;
}
