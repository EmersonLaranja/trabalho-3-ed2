#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "pageRank.h"
#include "tst.h"
int main(int argc, char const *argv[])
{
  //Ler index.txt e retornar a quantidade de paginas

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

  pageRank(pages, numberPages);

  for (int i = 0; i < numberPages; i++)
  {
    printPage(pages[i]);
  }

  Tst *tst = NULL;
  tst = readPages(pages, numberPages, stopWords, numberStopWords, tst);
  traverseTst(tst);

  Page **findPages = (Page **)malloc((numberPages) * sizeof(Page *));
  findPages = searchTST(tst, "abacate ruim");
  if (findPages != NULL)
  {
    for (int i = 0; i < numberPages; i++)
    {
      if (findPages[i] == NULL)
        break;
      printPage(findPages[i]);
    }
  }
  //Libera a memória
  for (int i = 0; i < numberPages; i++)
  {
    destroyPage(pages[i]);
  }
  for (int i = 0; i < numberStopWords; i++)
  {
    free(stopWords[i]);
  }
  free(pages);
  free(stopWords);
  fclose(stopWordsFile);
  fclose(fileIn);
  fclose(graphFile);
  return 0;
}
