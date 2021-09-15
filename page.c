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

void setPageLinksOut(Page *page, Page **links, int numLinks)
{
  page->numLinksOut = numLinks;
  page->linksOut = links;
}

void printPageLinksOut(Page* page){
  printf("%s %p Links Out (%d):\n", page->name, page,page->numLinksOut);
  for(int i = 0; i<page->numLinksOut; i++){
    printf(" > %s %p\n",(page->linksOut[i])->name, page->linksOut[i]);
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
    for (int j = 0; j < pageNumLinks; j++){
      link = p->linksOut[j];
      if (!strcmp(p->linksOut[j]->name, page->name))
        totalNumLinks++;
      }
  }

  Page **links= (Page**)malloc(sizeof(Page*)* totalNumLinks);

  int linksAux =0;
  //Adiciona os links na lista
  for (int i = 0; i < numPages; i++)
  {
    p = pages[i];
    pageNumLinks = p->numLinksOut;
    for (int j = 0; j < pageNumLinks; j++)
      if (!strcmp(p->linksOut[j]->name, page->name)){
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
  printf("%s (%lf) - %d linksIn - %d linksOut\n", page->name, page->rank, page->numLinksIn, page->numLinksOut);
}

void printCompletePage(Page *page)
{
  printf("\n---- %s -----\n", page->name);
  printf("Links Out:\n");
  for(int i = 0; i<page->numLinksOut; i++){
    printf("    > %s\n",(page->linksOut[i])->name);
  }
  
  printf("Links In:\n");
  for(int i = 0; i<page->numLinksIn; i++){
    printf("    < %s\n",(page->linksIn[i])->name);
  }
}

Page *getPageByName(Page **pages, int numPages, char *name)
{
  for (int i = 0; i < numPages; i++){
    if (!strcmp(pages[i]->name, name))
      return pages[i];
  }
  return NULL;
}

Page *destroyPage(Page *page)
{

  if (page != NULL)
  {
    free(page->name);
    free(page->linksOut);
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

Page* getLinkInPage(Page* page, int index){
  return page->linksIn[index];
}

Page* getLinkOutPage(Page* page, int index){
  return page->linksOut[index];
}

double getPageRank(Page *page)
{
  if (page)
    return page->rank;
}