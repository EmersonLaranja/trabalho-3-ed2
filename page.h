#ifndef PAGE_H
#define PAGE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"

typedef struct page Page;

Page *initPage(char *name, int id);
char *getPageName(Page *page);
int getNumberLinksIn(Page *page);
int getNumberLinksOut(Page *page);
int getPageId(Page *page);
double getPageRank(Page *page);
Page *getPageByName(Page **pages, int numPages, char *name);
void setPageLinksOut(Page *page, Page **links, int numLinks);
void setPageLinksIn(Page *page, Page **pages, int numPages);
Page *getLinkInPage(Page *page, int index);
void setPageId(Page *page, int id);
Page *getLinkOutPage(Page *page, int index);
void setPageRank(Page *page, double rank);
Page *getPageById(Page **pages, int numPages, int id);
Page *destroyPage(Page *);
void destroyPageArray(Page **pages, int numberPages);

#endif