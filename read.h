#ifndef READ_H
#define READ_H
#include <string.h>
#include <ctype.h>
#include "tst.h"
#include "pageRank.h"
#define MAX_WORD_SIZE 500

void verifyArgsLength(int numArgs);
void verifyFileWasOpened(FILE *file, const char *fileName);
Page **getPages(FILE *file, int *numberPages);
char **getStopWords(FILE *file, int *numberStopWords);
void readLinksOut(FILE *file, Page **pages, int numberPages);
Tst *readPages(Page **pages, int numberPages, char **stopWords, int numStopWords, Tst *tst, char *basePath);
int isStopWord(char *word, char **stopWords, int numStopWords);
void toLowerCase(char *word);
void getSearchWords(char *basePath, int numberPages, Page **pages, Tst *tst);
int comparePages(const void *a, const void *b);
void sortPage(Page **pages, int numPages);
char *getCompletePath(char *basePath, char *fileName);

#endif /* READ_H */