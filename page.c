#include "page.h"
#include "string.h"

struct page
{
  char *name;
  int id;
  Page **linksIn;
  Page **linksOut;
  double rank;
  int numLinksOut;
  int numLinksIn;
};

Page *initPage(char *name, int id)
{
  Page *page = (Page *)malloc(sizeof(Page));
  // page->linksIn = (Page **)malloc(sizeof(Page *));
  // page->linksOut = (Page **)malloc(sizeof(Page *));
  page->name = strdup(name);
  page->numLinksOut = 0;
  page->numLinksIn = 0;
  page->id = id;

  return page;
};

void setPageLinksOut(Page *page, Page **links, int numLinks)
{
  page->numLinksOut = numLinks;
  page->linksOut = links;
}

void printPageLinksOut(Page *page)
{
  printf("%s %p Links Out (%d):\n", page->name, page, page->numLinksOut);
  for (int i = 0; i < page->numLinksOut; i++)
  {
    printf(" > %s %p\n", (page->linksOut[i])->name, page->linksOut[i]);
  }
}
void setPageLinksIn(Page *page, Page **pages, int numPages)
{

  int totalNumLinks = 0;
  int pageNumLinks = 0;
  Page *p, *link;
  char name[30];

  //Conta a quantidade de links
  for (int i = 0; i < numPages; i++)
  {
    p = pages[i];
    pageNumLinks = p->numLinksOut;
    for (int j = 0; j < pageNumLinks; j++)
    {
      link = p->linksOut[j];
      if (!strcmp(p->linksOut[j]->name, page->name))
        totalNumLinks++;
    }
  }

  Page **links = (Page **)malloc(sizeof(Page *) * totalNumLinks);

  int linksAux = 0;
  //Adiciona os links na lista
  for (int i = 0; i < numPages; i++)
  {
    p = pages[i];
    pageNumLinks = p->numLinksOut;
    for (int j = 0; j < pageNumLinks; j++)
      if (!strcmp(p->linksOut[j]->name, page->name))
      {
        links[linksAux] = p;
        linksAux++;
      }
  }

  //Adiciona na struct
  page->numLinksIn = totalNumLinks;
  page->linksIn = links;
}

void printPage(Page *page)
{
 // printf("%d %s (%lf) - %d linksIn - %d linksOut\n", page->id, page->name, page->rank, page->numLinksIn, page->numLinksOut);
 
 printf("%s ",page->name);
}

void printCompletePage(Page *page)
{
  printf("\n----%d %s (rank: %lf) -----\n", page->id, page->name, page->rank);
  printf("Links Out:\n");
  for (int i = 0; i < page->numLinksOut; i++)
  {
    printf("    > %s\n", (page->linksOut[i])->name);
  }

  printf("Links In:\n");
  for (int i = 0; i < page->numLinksIn; i++)
  {
    printf("    < %s\n", (page->linksIn[i])->name);
  }
}

Page *getPageByName(Page **pages, int numPages, char *name)
{
  for (int i = 0; i < numPages; i++)
  {
    if (!strcmp(pages[i]->name, name))
      return pages[i];
  }
  return NULL;
}

Page *getPageById(Page **pages, int numPages, int id)
{
  for (int i = 0; i < numPages; i++)
  {
    if (pages[i]->id == id)
      return pages[i];
  }
  return NULL;
}

Page *destroyPage(Page *page)
{

  if (page != NULL)
  {
    if (page->name)
      free(page->name);
    if (page->linksOut)
      free(page->linksOut);
    if (page->linksIn)
      free(page->linksIn);
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

Page *getLinkInPage(Page *page, int index)
{
  return page->linksIn[index];
}

Page *getLinkOutPage(Page *page, int index)
{
  return page->linksOut[index];
}

double getPageRank(Page *page)
{
  if (page)
    return page->rank;
}

int getPageId(Page *page)
{
  if (page)
    return page->id;
}

void setPageId(Page *page, int id)
{
  if (page)
    page->id = id;
}
void setPageRank(Page *page, double rank )
{
  if (page)
    page->rank = rank;
}

int comparePages(const void *a, const void *b)
{
    // Same PageRank values, comparing indices->
    if ((*(Page **)a)->rank > (*(Page **)b)->rank)
      return -1;
    else if ((*(Page **)a)->rank < (*(Page **)b)->rank)
          return 1;

    return 0;
}

void sortPage(Page** pages, int numPages){
   qsort(pages, numPages, sizeof(Page *), comparePages);
}
