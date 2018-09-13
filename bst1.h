/* bst1.h */
#include <stdlib.h>
#include <stdio.h>
#include "athleteData.h"
#define MAXSTR 128
#define MAXLN 512

struct bst;

struct bst{
  struct bst *left;
  struct bst *right;
  char name[MAXSTR];
  char data[MAXLN];
  /*char id[MAXSTR];
  char name[MAXSTR];
  char *data;*/

};

struct bst *readFile(FILE *athleteFilePtr, struct bst *bst);
struct bst *bst1Insert(struct bst *parent, char *athleteName, char *buffer);
void freeTree(struct bst *parent);
FILE *searchTree(struct bst *parent, char *key, FILE *outputFile);
void traverse(struct bst *root);
athleteData_t dataSplit(char *data/*, athleteData_t *athleteData*/);
