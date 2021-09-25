#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "pageRank.h"
#include "tst.h"
#include <ctype.h>

void toLowerCase2(char *word)
{
  while (*word)
  {
    if(strcmp(word ,"0")&&strcmp(word ,"1")&&strcmp(word ,"2")&&strcmp(word ,"3")&&strcmp(word ,"4"))
      *word = tolower((unsigned char)*word);
    word++;
  }
}

int main(int argc, char const *argv[])
{
  //Ler index.txt e retornar a quantidade de paginas
  char* s = "ABc123";
    printf("%s in lowercase is represented as ",s);
    toLowerCase2(s);
    printf("%s", s);
  verifyArgsLength(argc);
  FILE *fileIn = fopen(argv[1], "r");
  verifyFileWasOpened(fileIn);

  int numberPages = 0;
  Page **pages = getPages(fileIn, &numberPages);

  char **stopWords;
  int numberStopWords = 0;

  FILE *stopWordsFile = fopen("./input/stopwords.txt", "r");
  verifyFileWasOpened(stopWordsFile);

  stopWords = getStopWords(stopWordsFile, &numberStopWords);

  //Ler graph.txt
  FILE *graphFile = fopen("./input/graph.txt", "r");
  readLinksOut(graphFile, pages, numberPages);

  for (int i = 0; i < numberPages; i++)
  {
    setPageLinksIn(pages[i], pages, numberPages);
  }


  Tst *tst = NULL;
  tst = readPages(pages, numberPages, stopWords, numberStopWords, tst);

  pageRank(pages, numberPages);
 
  getSearchWords( numberPages,pages,  tst);

  //Libera a memória
  for (int i = 0; i < numberPages; i++)
  {
    destroyPage(pages[i]);
  }
  for (int i = 0; i < numberStopWords; i++)
  {
    free(stopWords[i]);
  }
destroyTST(tst);
  free(pages);
  free(stopWords);
  fclose(stopWordsFile);
  fclose(fileIn);
  fclose(graphFile);
  return 0;
}
