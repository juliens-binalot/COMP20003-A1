/* bst2.c*/
/* bst1.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "bst2.h"
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
      bst = bst2Insert(bst, athleteName, buffer);
      /*Print statements for debugging
      printf("%s\n", idPtr);
      printf("%s\n", namePtr);
      printf("%s\n", dataPtr);*/
      /*free(idPtr);
      free(namePtr);
      free(dataPtr);*/
      count++;
      if (count>INITIAL){
        tmp = realloc(tmp, INITIAL);
      }
    }
    free(tmp);

 return bst;
}

struct bst *bst2Insert(struct bst *parent, char *athleteName, char *buffer){
  struct bst **insertLocation = &parent;
  struct node **insertLocationList = NULL;
  int dir = -1;
  /* Traverses a tree until the correct location is found */
  while (*insertLocation != NULL){
    dir = strcmp(athleteName,(*insertLocation)->name);
      if (dir < 0){
        /*printf("%s, %s", athleteName, (*insertLocation)->name);*/
          insertLocation = &(*insertLocation)->left;
      }
      else if (dir > 0){
          insertLocation = &(*insertLocation)->right;
      }
      else {
        break;
      }
  }

  /* Inserts data */
  if (dir != 0){
  *insertLocation = (struct bst *) malloc(sizeof(struct bst));
  assert(*insertLocation);
  (*insertLocation)->left = NULL;
  (*insertLocation)->right = NULL;
  strcpy((*insertLocation)->name, athleteName);
  /* place buffer in a linked list, get the address of a free memory*/
  insertLocationList = &(*insertLocation)->data;
  /* First entry in a list */
    *insertLocationList = (struct node*)malloc(sizeof(struct node));
    assert(*insertLocationList);
    strcpy((*insertLocationList)->data, buffer);
    /*printf("%s", (*insertLocationList)->data);*/
    (*insertLocationList)->next = NULL;
  }

  else if (dir==0){

    /* Traverses the linked list */
      /*printf("%d\n", dir); */
      insertLocationList = &(*insertLocation)->data;
      while (*insertLocationList != NULL){
        /*traverse list until free space is found*/
        insertLocationList = &(*insertLocationList)->next;
      }
      *insertLocationList = (struct node*)malloc(sizeof(struct node));
      assert(*insertLocationList);
      strcpy((*insertLocationList)->data, buffer);
      (*insertLocationList)->next = NULL;
      /*printf("%s", (*insertLocationList)->data);*/
    }

  return parent;

}

void traverse(struct bst *root){
  /* prints contents of tree */

  if (root == NULL){
    return;
  }
  /*printf("%s %s\n",root->name, root->data);*/
  struct bst **data = &root;
  struct node **dataList = &(*data)->data;
  while((*dataList)->next!= NULL){
  printf("%s\n\n\n",root->data->data);
  dataList = &(*dataList)->next;
}
    traverse(root->left);
    traverse(root->right);
}

void freeTree(struct bst *parent){
  if(! parent){
    return;
  }

struct bst **data = &parent;
struct node **dataList = &(*data)->data;
freeTree(parent->left);
freeList(*dataList);
freeTree(parent->right);
free(parent);

}

void freeList(struct node *dataList){
  struct node *prevDataList;
  if(! dataList){
    printf("end\n" );
    return;
  }
  /* traverse the list until the last entry*/
  while((dataList) != NULL){
  /*printf("%s\n\n\n",dataList->data);*/
  prevDataList = dataList;
  dataList = dataList->next;
  free(prevDataList);

/* frees last entry*/
}
  }

FILE *searchTree(struct bst *parent, char *key, FILE *outputFile){
  struct bst **searchLocation = &parent;
  int matchCount = 0;
  int keyComparisons = 0;
  int dir = -1;
  //char athlete[MAXSTR];
  athleteData_t athlete;
  char tmp[MAXLN];

  /*strcpy(athlete, key);*/
  /*printf("%s", athlete); */

  /* Traverses the tree and finds a match, then places in output file */
  while (*searchLocation != NULL){
    dir = strcmp(key, (*searchLocation)->name);
    //printf("\n%d\n", dir);
    if (dir < 0){
      searchLocation = &(*searchLocation)->left;
    } else if (dir > 0){
      searchLocation = &(*searchLocation)->right;
    } else if (dir == 0){
      keyComparisons+=1;
      break;
    }
    keyComparisons+=1;
  }
  if (dir ==0){
      /* splits and sends the data to their corresponding field in the
      athlete data struct then prints it out in the output file*/
      struct node **dataList = &(*searchLocation)->data;
      /*printf("%s", ((*dataList)->data));
      athlete = dataSplit((*dataList)->data); */
      while((*dataList)->data != NULL){
        /*printf("%s", ((*dataList)->data));*/
        matchCount++;
        strcpy(tmp, (*dataList)->data);
        athlete = dataSplit(tmp);
        fprintf(outputFile,
          "%s --> ID: %s Sex: %s || Age: %s || Height: %s || Weight: %s || "
          "Team: %s || NOC: %s || Games: %s || Year: %s || Season: %s || "
          "City: %s || Sport: %s || Event: %s || Medal: %s ||\n",
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
          dataList = &(*dataList)->next;
        }

    } else {
      fprintf(outputFile, "%s --> NOTFOUND\n\n", key);
    }

    /* change key comparison count */

  printf("%s --> %d\n", key, keyComparisons);

    return outputFile;
  }
