#include "read.h"

void verifyArgsLength(int numArgs)
{
  if (numArgs < 2)
  {
    printf("ERRO: Quantidade de argumentos inválidos\n");
    exit(1);
  }
}

void verifyFileWasOpened(FILE *file, const char *fileName)
{
  if (file == NULL)
  {
    printf("ERRO: falha na abertura do arquivo %s\n", fileName);
    exit(1);
  }
}

Page **getPages(FILE *file, int *numberPages)
{

  char pageName[300];

  while (fscanf(file, "%s", pageName) != EOF)
  {
    (*numberPages)++;
  }

  rewind(file);

  //Alocar a lista de paginas;
  Page **pages = (Page **)malloc((*numberPages) * sizeof(Page *));

  for (int i = 0; fscanf(file, "%s", pageName) != EOF; i++)
    pages[i] = initPage(pageName, i);

  return pages;
}

void readLinksOut(FILE *file, Page **pages, int numberPages)
{
  char name[30];
  int numLinks;
  Page *page, *link;
  for (int i = 0; i < numberPages; i++)
  {

    fscanf(file, "%s %d", name, &numLinks);
    page = getPageByName(pages, numberPages, name);
    if (!page)
    {
      printf("ERRO: página %s não encontrada \n", name);
      exit(1);
    }
    Page **links = (Page **)malloc(sizeof(Page *) * numLinks);
    for (int j = 0; j < numLinks; j++)
    {
      fscanf(file, "%s", name);
      link = getPageByName(pages, numberPages, name);
      if (!link)
      {
        printf("ERRO: página %s não encontrada \n", name);
        exit(1);
      }
      links[j] = link;
    }
    setPageLinksOut(page, links, numLinks);
  }
}

char **getStopWords(FILE *file, int *numberStopWords)
{
  char stopWord[300];

  while (fscanf(file, "%s", stopWord) != EOF)
  {
    (*numberStopWords)++;
  }

  rewind(file);

  char **stopWords = (char **)malloc(*numberStopWords * sizeof(char *));

  for (int i = 0; fscanf(file, "%s", stopWord) != EOF; i++)
  {
    stopWords[i] = strdup(stopWord);
    toLowerCase(stopWords[i]);
  }
  return stopWords;
}

Tst *readPages(Page **pages, int numberPages, char **stopWords, int numStopWords, Tst *tst, char *basePath)
{

  char path[MAX_WORD_SIZE];
  strcpy(path, basePath);
  strcat(path, "/pages/");

  for (int i = 0; i < numberPages; i++)
  {
    char *pagePath = getCompletePath(path, getPageName(pages[i]));

    FILE *file = fopen(pagePath, "r");
    verifyFileWasOpened(file, pagePath);
    char word[MAX_WORD_SIZE];

    while (EOF != fscanf(file, "%s", word))
    {
      toLowerCase(word);
      if (!isStopWord(word, stopWords, numStopWords))
      {
        insert(&tst, word, numberPages, pages[i]);
      }
    }
    free(pagePath);
    fclose(file);
  }
  return tst;
}

int isStopWord(char *word, char **stopWords, int numStopWords)
{
  for (int i = 0; i < numStopWords; i++)
    if (strcmp(word, stopWords[i]) == 0)
      return 1;

  return 0;
}

void toLowerCase(char *word)
{
  int i = 0;
  if (*word >= 'A' && *word <= 'Z')
    while (*word != '\0')
    {
      {
        *word = tolower((unsigned char)*word);
      }
      word++;
    }
}

void getSearchWords(char *basePath, int numberPages, Page **pages, Tst *tst)
{
  char *searchesPath = getCompletePath(basePath, "/searches.txt"); //entrada padrão e printa
  FILE *file = fopen(searchesPath, "r");
  verifyFileWasOpened(file, searchesPath);

  char *outputPath = getCompletePath(basePath, "/saida.txt");
  FILE *fileOut = fopen(outputPath, "w");
  verifyFileWasOpened(file, outputPath);

  size_t len = 300;
  char *line = (char *)malloc(sizeof(char) * len);
  char token[] = " ";
  char *word = NULL;
  int weightId[numberPages];
  int numSearchWord = 0;
  Page **results, **pagesSearch;

  // Enquanto ha linhas no arquivo de entrada
  while (getline(&line, &len, stdin) != -1)
  {
    numSearchWord = 0;
    //Retira o caracter \n
    char *pos;

    if ((pos = strchr(line, '\n')) != NULL)
      *pos = '\0';

    for (int i = 0; i < numberPages; i++)
      weightId[i] = 0;

    printf( "search:");
    int resultsId[numberPages];
    word = strtok(line, token);

    while (word != NULL)
    {
      pagesSearch = searchTST(tst, word);

      if (pagesSearch)
      {
        for (int i = 0; i < numberPages; i++)
        {
          if (pagesSearch[i] == NULL)
            break;

          int id = getPageId(pagesSearch[i]);

          weightId[id]++;
          word = strtok(NULL, token);

          numSearchWord++;
        };

        results = (Page **)malloc((numberPages) * sizeof(Page *));
        int numResult = 0;

        //Retornar a lista unica
        for (int i = 0; i < numberPages; i++)
        {
          if (weightId[i] == numSearchWord)
          {
            results[numResult] = getPageById(pages, numberPages, i);
            numResult++;
          }
        }

        sortPage(results, numResult);

        printf( "\npages:");
        for (int i = 0; i < numResult; i++)
        {
          printf( "%s ", getPageName(results[i]));
        }

        printf( "\npr:");

        for (int i = 0; i < numResult; i++)
        {
          printf( "%.18lf ", getPageRank(results[i]));
        }
        printf( "\n");
        free(results);
      }
    }
  }

  free(line);
  fclose(file);
  fclose(fileOut);
  free(searchesPath);
  free(outputPath);
}

char *getCompletePath(char *basePath, char *fileName)
{
  char *path = (char *)malloc(sizeof(char) * MAX_WORD_SIZE);
  strcpy(path, basePath);
  strcat(path, fileName);
  return path;
}