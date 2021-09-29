#ifndef EOW_H
#define EOW_H
#include "page.h"

typedef struct endOfWord EndOfWord;

EndOfWord *initEOW(int maxPages);
void addPageEOW(EndOfWord *eow, Page *page);
void destroyEOW(EndOfWord *eow);
Page **getPagesEOW(EndOfWord *eow);
#endif