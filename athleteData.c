/* athleteData.c */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "athleteData.h"
#define INITIALSIZE 8
#define MAXSTR 128
#define MAXLN 512

char *extractName(char *tmp){
  /* returns ahtlete's name */
  char *athleteName = NULL;

  athleteName = strtok(tmp, ",");
  athleteName = strtok(NULL, ",");

  //printf("%s", athleteName);

  return athleteName;
}

athleteData_t dataSplit(char *data){
  /* Splits athlete data and places them into their respective field in
  a struct */
  athleteData_t athleteData;

  athleteData.id = strtok(data, ",");
  athleteData.name = strtok(NULL, ",");
  athleteData.sex = strtok(NULL, ",");
  athleteData.age = strtok(NULL, ",");
  athleteData.height = strtok(NULL, ",");
  athleteData.weight = strtok(NULL, ",");
  athleteData.team = strtok(NULL, ",");
  athleteData.noc = strtok(NULL, ",");
  athleteData.games = strtok(NULL, ",");
  athleteData.year = strtok(NULL, ",");
  athleteData.season = strtok(NULL, ",");
  athleteData.city = strtok(NULL, ",");
  athleteData.sport = strtok(NULL, ",");
  athleteData.event = strtok(NULL, ",");
  athleteData.medal = strtok(NULL, "\n");

  /* for debugging only
  printf("%s --> ID: %s || Sex: %s || Age: %s || Height: %s || Weight: %s ||"
  "Team: %s || NOC: %s || Games: %s || Year: %s || Season: %s || "
  "City: %s || Sport: %s || Event: %s || Medal: %s || \n",
 athleteData.name,
 athleteData.id,
 athleteData.sex,
 athleteData.age,
 athleteData.height,
 athleteData.weight,
 athleteData.team,
 athleteData.noc,
 athleteData.games,
 athleteData.year,
 athleteData.season,
 athleteData.city,
  athleteData.sport,
 athleteData.event,
 athleteData.medal);*/


  return athleteData;
}
