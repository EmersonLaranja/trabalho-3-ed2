#include "read.h"
#define MAX_WORD_SIZE 50
void verifyArgsLength(int numArgs)
{
  if (numArgs < 2)
  {
    printf("ERRO: Quantidade de argumentos inválidos\n");
    exit(1);
  }
}
void verifyFileWasOpened(FILE *file)
{
  if (file == NULL)
  {
    printf("ERRO: falha na abertura do arquivo de entrada\n");
    exit(1);
  }
}

Page **getPages(FILE *file, int *numberPages)
{

  char pageName[300];

  //TENTAR DEPOIS COM GETLINE

  while (fscanf(file, "%s", pageName) != EOF)
  {
    (*numberPages)++;
  }

  rewind(file);

  //Alocar a lista de paginas;
  Page **pages = (Page **)malloc((*numberPages) * sizeof(Page *));

  for (int i = 0; fscanf(file, "%s", pageName) != EOF; i++)
  {
    pages[i] = initPage(pageName, i);
  }
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

  //TENTAR DEPOIS COM GETLINE

  while (fscanf(file, "%s", stopWord) != EOF)
  {
    (*numberStopWords)++;
  }

  rewind(file);

  //Alocar a lista de stopWords;
  char **stopWords = (char **)malloc(*numberStopWords * sizeof(char *));

  for (int i = 0; fscanf(file, "%s", stopWord) != EOF; i++)
  {
    stopWords[i] = strdup(stopWord);
    toLowerCase(stopWords[i]);
  }
  return stopWords;
}

Tst *readPages(Page **pages, int numberPages, char **stopWords, int numStopWords, Tst *tst)
{
  for (int i = 0; i < numberPages; i++)
  {
    char path[MAX_WORD_SIZE] = "./input/pages/";
    FILE *file = fopen(strcat(path, getPageName(pages[i])), "r");
    if (file == NULL)
    {
      printf("ERRO: falha na abertura do arquivo da pagina %s\n", getPageName(pages[i]));
      exit(1);
    }
    char word[MAX_WORD_SIZE];

    while (EOF != fscanf(file, "%s ", word))
    {
      toLowerCase(word);
      if (!isStopWord(word, stopWords, numStopWords))
      {
        insert(&tst, word, numberPages, pages[i]);
      }
    }
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
  while (*word)
  {
    *word = tolower((unsigned char)*word);
    word++;
  }
}