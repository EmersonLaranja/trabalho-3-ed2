#include "endOfWord.h"
#include "stdlib.h"
#include "string.h"
struct endOfWord
{
  int index;
  Page **pages;
};

EndOfWord *initEOW(int maxPages)
{
  EndOfWord *eow = (EndOfWord *)malloc(sizeof(EndOfWord));
  eow->index = 0;
  eow->pages = malloc(maxPages * sizeof(EndOfWord));

  for (int i = 0; i < maxPages; i++)
  {
    eow->pages[i] = NULL;
  }

  return eow;
}

void addPageEOW(EndOfWord *eow, Page *page)
{
  for (int i = 0; i < eow->index; i++)
  {
    if (!strcmp(getPageName(eow->pages[i]), getPageName(page)))
      return;
  }
  eow->pages[eow->index] = page;
  eow->index++;
}

void destroyEOW(EndOfWord *eow)
{
  free(eow->pages);
  free(eow);
}

Page **getPagesEOW(EndOfWord *eow)
{
  return eow->pages;
}