#ifndef PAGERANK_H
#define PAGERANK_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "page.h"

typedef struct pagerank PageRank;

int E(PageRank **pages, int N);
double summation(PageRank **pages, int id);
int comparePages(const void *a, const void *b);
void pageRank(Page **pagesAux, int numPages);
void pageRank(Page **pagesAux, int numPages);

#endif