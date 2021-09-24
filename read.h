#ifndef READ_H
#define READ_H
#include <string.h>
#include <ctype.h>
#include "tst.h"

void verifyArgsLength(int numArgs);
void verifyFileWasOpened(FILE *file);
Page **getPages(FILE *file, int *numberPages);
// char **getStopWords(FILE *file, int *numberPages);
//void getLinks(FILE *file, Page **pages, int numberPages);
char **getStopWords(FILE *file, int *numberStopWords);
void readLinksOut(FILE *file, Page **pages, int numberPages);
Tst *readPages(Page **pages, int numberPages, char **stopWords, int numStopWords, Tst *tst);
int isStopWord(char *word, char **stopWords, int numStopWords);
void toLowerCase(char *word);

#endif /* READ_H */