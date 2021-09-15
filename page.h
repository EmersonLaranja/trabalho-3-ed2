#ifndef PAGE_H
#define PAGE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct page Page;

Page *initPage(char *name);
Page *destroyPage(Page *);
char *getPageName(Page *page);
int getNumberLinksIn(Page *page);
int getNumberLinksOut(Page *page);
double getPageRank(Page *page);
Page *getPageByName(Page **pages, int numPages, char *name);
void printPage(Page *page);
void setPageLinksOut(Page *page, Page **links, int numLinks);
void setPageLinksIn(Page *page, Page **pages, int numPages);
#endif