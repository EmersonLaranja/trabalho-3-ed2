#ifndef PAGERANK_H
#define PAGERANK_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "page.h"
typedef struct pagerank PageRank;

int finishedCalculation(PageRank **pages, int N);
double sumOperation(PageRank **pages, int id);
void pageRank(Page **pagesAux, int numPages);

#endif