#ifndef READ_H
#define READ_H

#include "page.h"

void verifyArgsLength(int numArgs);
void verifyFileWasOpened(FILE *file);
Page **getPages(FILE *file, int *numberPages);
// char **getStopWords(FILE *file, int *numberPages);
//void getLinks(FILE *file, Page **pages, int numberPages);
char **getStopWords(FILE *file, int *numberStopWords);
void getLinks(FILE *file, Page **pages, int numberPages);

#endif /* READ_H */