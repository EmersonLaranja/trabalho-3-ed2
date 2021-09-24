#ifndef TST_H
#define TST_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "page.h"
typedef struct tst Tst;

Tst *initTst(char data, int numberPages);
void insert(Tst **root, char *word, int numberPages, Page *page);
void traverseTstUtil(Tst *root, char *buffer, int depth);
void traverseTst(Tst *root);
Page **searchTST(Tst *root, char *word);
void destroyTST(Tst *root);

#endif