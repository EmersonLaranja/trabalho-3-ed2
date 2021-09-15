#include "page.h"
#include "string.h"

struct page
{
  char *name;
  Page **linksIn;
  Page **linksOut;
  double rank;
  int numLinksOut;
  int numLinksIn;
};

Page *initPage(char *name)
{
  Page *page = (Page *)malloc(sizeof(Page));
  page->name = strdup(name);
  page->numLinksOut = 0;
  page->numLinksIn = 0;

  return page;
};

void setPageLinksIn(Page *page, Page **links, int numLinks)
{
  page->numLinksIn = numLinks;
  page->linksIn = (Page **)malloc(numLinks * sizeof(Page *));
  page->linksIn = links;
}

void setPageLinksOut(Page *page, Page **links, int numLinks)
{
  page->numLinksOut = numLinks;
  page->linksOut = (Page **)malloc(numLinks * sizeof(Page *));
  page->linksOut = links;
}

void setPageLinksIn2(Page *page, Page **pages, int numPages)
{
  int totalNumLinks = 0;
  int pageNumLinks = 0;
  for (int i = 0; i < numPages; i++)
  {
    pageNumLinks = pages[i]->numLinksOut;
    for (int j = 0; j < numPages; j++)
  }
}

void printPage(Page *page)
{
  //printf("%s\n", page->name);
  printf("%s (%lf) - %d linksIn - %d linksOut\n", page->name, page->rank, page->numLinksIn, page->numLinksOut);
}

Page *getPageByName(Page **pages, int numPages, char *name)
{
  for (int i = 0; i < numPages; i++)
    if (!strcmp(pages[i]->name, name))
      return pages[i];

  return NULL;
}

Page *destroyPage(Page *page)
{

  if (page != NULL)
  {
    free(page->name);
    //destroyLinksPage();
    free(page);
  }
};

char *getPageName(Page *page)
{
  if (page)
    return page->name;
}

int getNumberLinksOut(Page *page)
{
  if (page)
    return page->numLinksOut;
}
int getNumberLinksIn(Page *page)
{
  if (page)
    return page->numLinksIn;
}

double getPageRank(Page *page)
{
  if (page)
    return page->rank;
}