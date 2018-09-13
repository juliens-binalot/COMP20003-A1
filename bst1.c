/* bst1.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "bst1.h"
#define INITIAL 10000

struct bst *readFile(FILE *athleteFilePtr, struct bst *bst){
    /* athlete data pointers */
    char *tmp = NULL;
    tmp =  (char *)malloc(sizeof(char)*INITIAL);
    size_t bufferSize = MAXLN;
    char *athleteName;
    char buffer[MAXLN];
    int count = 0;

    /* gets line of each csv file */
    while(getline(&tmp, &bufferSize, athleteFilePtr) != EOF){
      strcpy(buffer, tmp);
      athleteName = strtok(tmp, ",");
      athleteName = strtok(NULL, ",");
      bst = bst1Insert(bst, athleteName, buffer);
      /*
      Print statements for debugging
      printf("%s\n", idPtr);
      printf("%s\n", namePtr);
      printf("%s\n", dataPtr);*/
      /*free(idPtr);
      free(namePtr);
      free(dataPtr);
      */
      count++;
      if (count>INITIAL){
        tmp = realloc(tmp, INITIAL);
      }
    }
    free(tmp);

 return bst;
}

struct bst *bst1Insert(struct bst *parent, char *athleteName, char *buffer){
  struct bst **insertLocation = &parent;
  /* based off Week 4 Workshop solutions COMP20003 by Grady FItzpatrick */

  /* Traverses a tree until the correct location is found */
  while (*insertLocation != NULL){
      if (strcmp(athleteName,(*insertLocation)->name) <= 0){
        /*printf("%s, %s", athleteName, (*insertLocation)->name);*/
          insertLocation = &(*insertLocation)->left;
      } else {
          insertLocation = &(*insertLocation)->right;
      }
  }

  /* Inserts data */
  *insertLocation = (struct bst *) malloc(sizeof(struct bst));
  assert(*insertLocation);
  (*insertLocation)->left = NULL;
  (*insertLocation)->right = NULL;
  strcpy((*insertLocation)->name, athleteName);
  strcpy((*insertLocation)->data, buffer);

  return parent;

}

void traverse(struct bst *root){
  /* prints contents of tree */

  if (root == NULL){
    return;
  }
  /*printf("%s %s\n",root->name, root->data);*/
    traverse(root->left);
    printf("%s\n",root->name);
    traverse(root->right);
}

void freeTree(struct bst *parent){
  if(! parent){
    return;
  }
freeTree(parent->left);
freeTree(parent->right);
free(parent);

}

FILE *searchTree(struct bst *parent, char *key, FILE *outputFile){
  struct bst **searchLocation = &parent;
  int matchCount = 0;
  int keyComparisons = 0;
  int dir;
  athleteData_t athlete;
  char tmp[MAXLN];



  /* Traverses the tree and finds a match, then places in output file */
  while (*searchLocation != NULL){
    dir = strcmp(key, (*searchLocation)->name);
    /* for debugging only
    printf("%s\n",key);
    printf("%s",(*searchLocation)->name);
    printf("\n%d\n", dir); */
    keyComparisons+=1;
    if (dir < 0){
      searchLocation = &(*searchLocation)->left;
    } else if (dir > 0){
      searchLocation = &(*searchLocation)->right;
    } else if (dir == 0){
      matchCount++;

      /* splits and sends the data to their corresponding field in the
      athlete data struct then prints it out in the output file*/
      /*printf("%s", (*searchLocation)->data);*/
      strcpy(tmp, (*searchLocation)->data);
      athlete = dataSplit(tmp);
      fprintf(outputFile,
        "%s --> ID: %s Sex: %s || Age: %s || Height: %s || Weight: %s ||"
        " Team: %s || NOC: %s || Games: %s || Year: %s || Season: %s || "
        "City: %s || Sport: %s || Event: %s || Medal: %s ||" "\n",
        athlete.name,
        athlete.id,
        athlete.sex,
        athlete.age,
        athlete.height,
        athlete.weight,
        athlete.team,
        athlete.noc,
        athlete.games,
        athlete.year,
        athlete.season,
        athlete.city,
        athlete.sport,
        athlete.event,
        athlete.medal);

      /* for debugging
      (*searchLocation)->athleteData->name,
      (*searchLocation)->athleteData->id,
      (*searchLocation)->athleteData->sex,
      (*searchLocation)->athleteData->age,
      (*searchLocation)->athleteData->height,
      (*searchLocation)->athleteData->weight,
      (*searchLocation)->athleteData->team,
      (*searchLocation)->athleteData->noc,
      (*searchLocation)->athleteData->games,
      (*searchLocation)->athleteData->year,
      (*searchLocation)->athleteData->season,
      (*searchLocation)->athleteData->city,
      (*searchLocation)-> athleteData->sport,
      (*searchLocation)->athleteData->event,
      (*searchLocation)->athleteData->medal*/

        /*printf("%s %s\n", parent->name, parent->data);*/
      searchLocation = &(*searchLocation)->left;
    }

  }

  if (!matchCount){
    fprintf(outputFile, "%s --> NOTFOUND\n", key);
  }
  printf("%s --> %d\n", key, keyComparisons);


    return outputFile;
  }
