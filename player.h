#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *firstName; //primul nume al jucatorului
    char *secondName; //al doilea nume al jucatorului
    int points; //punctajul jucatorului
} Player;

typedef struct
{
    char *teamName; //numele echipei
    int nr_jucatori; //nr de jucatori din echipa
    Player *p;//vectorul de jucatori
    float punctaj; //punctajul total al echipei
} Team;