/* bst2.h */
#include <stdlib.h>
#include <stdio.h>
#include "athleteData.h"
#define MAXSTR 128
#define MAXLN 512

struct node;
struct node {
  char data[MAXLN];
  struct node *next;
};

struct bst;

struct bst{
  struct bst *left;
  struct bst *right;
  char name[MAXSTR];
  /*char data[MAXLN];*/
  struct node *data;
};



/* for declaring later
struct node* newnode;*/

struct bst *readFile(FILE *athleteFilePtr, struct bst *bst);
struct bst *bst2Insert(struct bst *parent, char *athleteName, char *buffer);
void freeTree(struct bst *parent);
FILE *searchTree(struct bst *parent, char *key, FILE *outputFile);
void traverse(struct bst *root);
athleteData_t dataSplit(char *data/*, athleteData_t *athleteData*/);
void freeList(struct node *dataList);
