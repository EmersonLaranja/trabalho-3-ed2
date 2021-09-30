#include "read.h"
#include "pageRank.h"
#include "tst.h"
#include <ctype.h>

int main(int argc, char const *argv[])
{

  char *basePath = strdup(argv[1]);

  char *path;
  path = getCompletePath(basePath, "/index.txt");
  FILE *fileIn = fopen(path, "r");
  verifyFileWasOpened(fileIn, path);

  int numberPages = 0;
  Page **pages = getPages(fileIn, &numberPages);

  char **stopWords;
  int numberStopWords = 0;

  path = getCompletePath(basePath, "/stopwords.txt");
  FILE *stopWordsFile = fopen(path, "r");
  verifyFileWasOpened(stopWordsFile, path);

  stopWords = getStopWords(stopWordsFile, &numberStopWords);

  path = getCompletePath(basePath, "/graph.txt");
  FILE *graphFile = fopen(path, "r");
  verifyFileWasOpened(graphFile, path);
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

  destroyPageArray(pages, numberPages);
  destroyTST(tst);
  free(pages);
  free(stopWords);
  free(path);

  fclose(stopWordsFile);
  fclose(fileIn);
  fclose(graphFile);

  return 0;
}
