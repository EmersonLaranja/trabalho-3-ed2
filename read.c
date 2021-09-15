#include "read.h"

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
    pages[i] = initPage(pageName);
  }
  return pages;
}

void getLinks(FILE *file, Page **pages, int numberPages)
{
  for (int i = 0; i < numberPages; i++)
  {
    pages[i] = initPage(pageName);
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
  printf("NumberStopords = %d\n", *numberStopWords);
  rewind(file);

  //Alocar a lista de stopWords;
  char **stopWords = (char **)malloc(*numberStopWords * sizeof(char *));

  for (int i = 0; fscanf(file, "%s", stopWord) != EOF; i++)
  {
    stopWords[i] = strdup(stopWord);
  }
  return stopWords;
}