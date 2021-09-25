#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "page.h"
#include "pageRank.h"
struct pagerank
{

  double value;
  int pageId;
  double oldValue;

  // Output pages number, input pages array and input pages number.
  int n_out;
  int *in;
  int n_in;
};

int E(PageRank **pages, int N)
{
  // Indicates if calculation is finished.
  double sum = 0;
  int i = 0;
  for (i = 0; i < N; i++)
  {
    double old = pages[i]->oldValue;
    double value = pages[i]->value;

    sum += (value - old) * (value - old);
    //sum += (pages[i]->value - pages[i]->oldValue) * (pages[i]->value - pages[i]->oldValue);
  }

  if (sqrt(sum) < 0.0000000001)
    return 1; // Yes.
  else
    return 0; // No.
}

double summation(PageRank **pages, int id)
{
  // Calculates summation of values.

  double sum = 0;
  int i = 0;

  // Using Input pages to calculate summation.
  for (i = 0; i < pages[id]->n_in; i++)
  {

    int inputId = pages[id]->in[i];
    sum += (pages[inputId]->oldValue) / ((double)pages[inputId]->n_out);
  }
  return sum;
}

void pageRank(Page **allPages, int numPages)
{

  // Number of pages, pages array and alocate status check.
  int n_pages = numPages;
  PageRank **pages = (PageRank **)malloc(sizeof(PageRank *) * n_pages);

  // Initializing pages, giving them id "i".

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

    pages[i]->n_in = numLinks;
    pages[i]->in = (int *)malloc(sizeof(int) * numLinks);

    for (int j = 0; j < numLinks; j++)
    {
      pages[i]->in[j] = getPageId(getLinkInPage(allPages[i], j));
    }

    pages[i]->n_out = getNumberLinksOut(allPages[i]);
  }

  // Calculating PageRank.
  int finished = 0;

  // Contants to use in calculation.
  double constOne = (1 - 0.85) / (double)n_pages;
  double constTwo = 0.85;

  while (finished == 0)
  { //While E(k) > ε

    for (int i = 0; i < n_pages; i++)
    {
      // Pages WITHOUT output pages (n_out == 0).
      if (pages[i]->n_out == 0)
      {
        double temp = pages[i]->value;
        pages[i]->value = constOne + constTwo * pages[i]->oldValue + constTwo * summation(pages, i);
        pages[i]->oldValue = temp;
      }
      else
      {
        // Pages WITH output pages.
        double temp = pages[i]->value;
        pages[i]->value = constOne + constTwo * summation(pages, i);
        pages[i]->oldValue = temp;
      }
    }

    //Finishes if E(k) < ε.
    if (E(pages, n_pages) == 1)
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