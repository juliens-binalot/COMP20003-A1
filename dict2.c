#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "bst2.h"

int main(int argc, char **argv){
  /* file pointers */
  FILE *athleteFilePtr = NULL;
  FILE *outputFilePtr = NULL;
  /* tree pointer */
  struct bst *bst = NULL;
  /* key from stdin pointer */
  char *searchAth = NULL;
  char *newLinePtr = NULL;


  searchAth = (char *)malloc(sizeof(char)*MAXSTR);
  assert(searchAth);

  /* Opens input and output files */
  athleteFilePtr = fopen(argv[1], "r");
  outputFilePtr = fopen(argv[2], "w");
  if(athleteFilePtr == NULL || outputFilePtr == NULL){
    printf("Error");
  }

  bst = readFile(athleteFilePtr, bst);

  /*for debugging only
  traverse(bst);*/

  while (fgets(searchAth, MAXSTR, stdin)){
     /*check for new line */
      if ((newLinePtr = strchr(searchAth, '\n')) || (newLinePtr = strchr(searchAth, '\r'))){
      *newLinePtr = '\0';
      }
      searchTree(bst, searchAth, outputFilePtr);
  }

  fclose(athleteFilePtr);
  fclose(outputFilePtr);
  free(searchAth);
  freeTree(bst);

  return 0;
}
