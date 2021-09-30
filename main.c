#include "read.h"
#include "pageRank.h"
#include "tst.h"
#include <ctype.h>

int main(int argc, char const *argv[])
{

  char *basePath = strdup(argv[1]);

  char *indexPath = getCompletePath(basePath, "/index.txt");

  FILE *fileIn = fopen(indexPath, "r");
  verifyFileWasOpened(fileIn, indexPath);

  int numberPages = 0;
  Page **pages = getPages(fileIn, &numberPages);

  char **stopWords;
  int numberStopWords = 0;

  char *stpwrdPath = getCompletePath(basePath, "/stopwords.txt");
  FILE *stopWordsFile = fopen(stpwrdPath, "r");
  verifyFileWasOpened(stopWordsFile, stpwrdPath);

  stopWords = getStopWords(stopWordsFile, &numberStopWords);

  char *graphPath = getCompletePath(basePath, "/graph.txt");
  FILE *graphFile = fopen(graphPath, "r");
  verifyFileWasOpened(graphFile, graphPath);

  readLinksOut(graphFile, pages, numberPages);

  for (int i = 0; i < numberPages; i++)
    setPageLinksIn(pages[i], pages, numberPages);

  Tst *tst = NULL;
  tst = readPages(pages, numberPages, stopWords, numberStopWords, tst, basePath);

  pageRank(pages, numberPages);

  getSearchWords(basePath, numberPages, pages, tst);

  //-----------------Liberando a memória--------------------------

  for (int i = 0; i < numberStopWords; i++)
    free(stopWords[i]);
  free(stopWords);
  destroyPageArray(pages, numberPages);
  destroyTST(tst);
  free(basePath);
  free(indexPath);
  free(stpwrdPath);
  free(graphPath);
  fclose(stopWordsFile);
  fclose(fileIn);
  fclose(graphFile);

  return 0;
}
