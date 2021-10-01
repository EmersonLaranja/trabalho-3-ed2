
#include "pageRank.h"
#define CONST_VALUE 0.0000000001
#define ALPHA 0.85

struct pagerank
{
  double value;
  int pageId;
  double oldValue;

  int nOut;
  int nIn;
  int *in;
};

int finishedCalculation(PageRank **pages, int N)
{
  double sum = 0;
  int i = 0;
  for (i = 0; i < N; i++)
  {
    double old = pages[i]->oldValue;
    double value = pages[i]->value;

    sum += (value - old) * (value - old);
  }

  if (sqrt(sum) < CONST_VALUE)
    return 1; // Yes
  else
    return 0; // No
}

double sumOperation(PageRank **pages, int id)
{
  double sum = 0;
  int i = 0;

  for (i = 0; i < pages[id]->nIn; i++)
  {
    int inputId = pages[id]->in[i];
    sum += (pages[inputId]->oldValue) / ((double)pages[inputId]->nOut);
  }

  return sum;
}

void pageRank(Page **allPages, int numPages)
{

  int n_pages = numPages;
  PageRank **pages = (PageRank **)malloc(sizeof(PageRank *) * n_pages);

  for (int i = 0; i < n_pages; i++)
  {
    setPageId(allPages[i], i);
  }
  for (int i = 0; i < n_pages; i++)
  {
    pages[i] = (PageRank *)malloc(sizeof(PageRank));
    pages[i]->pageId = i;
    pages[i]->oldValue = (1 / (double)n_pages);
    pages[i]->value = 0;

    int numLinks = getNumberLinksIn(allPages[i]);

    pages[i]->nIn = numLinks;
    pages[i]->in = (int *)malloc(sizeof(int) * numLinks);

    for (int j = 0; j < numLinks; j++)
    {
      pages[i]->in[j] = getPageId(getLinkInPage(allPages[i], j));
    }

    pages[i]->nOut = getNumberLinksOut(allPages[i]);
  }

  int finished = 0;

  double constOne = (1 - ALPHA) / (double)n_pages;
  double constTwo = ALPHA;

  while (finished == 0)
  {

    for (int i = 0; i < n_pages; i++)
    {
      if (pages[i]->nOut == 0)
      {
        double temp = pages[i]->value;
        pages[i]->value = constOne + constTwo * pages[i]->oldValue + constTwo * sumOperation(pages, i);
        pages[i]->oldValue = temp;
      }
      else
      {
        double temp = pages[i]->value;
        pages[i]->value = constOne + constTwo * sumOperation(pages, i);
        pages[i]->oldValue = temp;
      }
    }

    if (finishedCalculation(pages, n_pages) == 1)
      finished = 1;
  }

  for (int i = 0; i < n_pages; i++)
  {
    setPageRank(allPages[i], pages[i]->value);
  }

  for (int i = 0; i < n_pages; i++)
  {
    free(pages[i]->in);
    free(pages[i]);
  }
  free(pages);
}