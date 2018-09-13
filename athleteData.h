/* athlete.h */

typedef struct {
  char *id;
  char *name;
  /* M or F */
  char *sex;
  char *age;
  char *height;
  char *weight;
  char *team;
  /* NOC 3 letter code */
  char *noc;
  char *games;
  char *year;
  /* summer or winter */
  char *season;
  char *city;
  char *sport;
  char *event;
  /* Gold, silver, bronze or NA */
  char *medal;

} athleteData_t;

/*athleteData_t dataSplit(char data[]);*/
int copyString(char data[], char field[], int i);
char *extractName(char *tmp);
