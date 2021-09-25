#ifndef PAGE_H
#define PAGE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct page Page;

Page *initPage(char *name, int id);
Page *destroyPage(Page *);
char *getPageName(Page *page);
int getNumberLinksIn(Page *page);
int getNumberLinksOut(Page *page);
int getPageId(Page *page);
double getPageRank(Page *page);
Page *getPageByName(Page **pages, int numPages, char *name);
void printPage(Page *page);
void setPageLinksOut(Page *page, Page **links, int numLinks);
void setPageLinksIn(Page *page, Page **pages, int numPages);
void printCompletePage(Page *page);
Page *getLinkInPage(Page *page, int index);
void printPageLinksOut(Page *page);
void setPageId(Page *page, int id);
Page *getLinkOutPage(Page *page, int index);
void setPageRank(Page *page, double rank );
Page *getPageById(Page **pages, int numPages, int id);

#endif