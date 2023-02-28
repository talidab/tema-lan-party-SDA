#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libs\list.h"

/* functie ce creeaza un nod prin alocare dinamica */
Node *makeNode(Team data, Node *next)
{
    Node *nod;
    nod = (Node *)malloc(sizeof(Node));
    nod->data.p = (Player *)malloc(nod->data.nr_jucatori * sizeof(Player));
    if (nod == NULL)
    {
        puts("Alocare dinamica esuata!");
        exit(1);
    }
    nod->data = data;
    nod->next = next;
    return nod;
}

/* functie ce adauga un nod la inceputul listei */
void addAtBeggining(Node **head, Team data)
{
    Node *newNode;
    newNode = makeNode(data, *head);
    *head = newNode;
}

/*functie ce creeaza lista */
Node *makeList(FILE *file)
{
    int nr_echipe, i, j, s;
    Team *echipe;
    Node *head = NULL;
    fscanf(file, "%d", &nr_echipe);
    echipe = (Team *)malloc(nr_echipe * sizeof(Team));
    for (i = 0; i < nr_echipe; i++)
    {
        fscanf(file, "%d", &echipe[i].nr_jucatori);
        char nume_echipa[60], nume_jucator[40], prenume_jucator[40];
        fgets(nume_echipa, 40, file);
        strcpy(nume_echipa, nume_echipa + 1);
        echipe[i].teamName = (char *)malloc((strlen(nume_echipa) + 1) * sizeof(char));
        nume_echipa[strlen(nume_echipa) - 1] = 0;
        while (nume_echipa[strlen(nume_echipa) - 1] == ' ')
            nume_echipa[strlen(nume_echipa) - 1] = '\0';
        strcpy(echipe[i].teamName, nume_echipa);
        s = 0;
        echipe[i].p = (Player *)malloc(echipe[i].nr_jucatori * sizeof(Player));
        for (j = 0; j < echipe[i].nr_jucatori; j++)
        {
            fscanf(file, "%s", nume_jucator);
            echipe[i].p[j].firstName = (char *)malloc((strlen(nume_jucator) + 1) * sizeof(char));
            strcpy(echipe[i].p[j].firstName, nume_jucator);
            fscanf(file, "%s", prenume_jucator);
            echipe[i].p[j].secondName = (char *)malloc((strlen(prenume_jucator) + 1) * sizeof(char));
            strcpy(echipe[i].p[j].secondName, prenume_jucator);
            fscanf(file, "%d", &echipe[i].p[j].points);
            s = s + echipe[i].p[j].points;
        }
        echipe[i].punctaj = (float)s / echipe[i].nr_jucatori;
        if (i == 0)
            head = makeNode(echipe[i], NULL);
        else
            addAtBeggining(&head, echipe[i]);
    }
    fclose(file);
    return head;
}

/*functie ce afiseaza toate elementele unei liste*/
void print_c1(Node *head,FILE *output)
{
    while (head != NULL)
    {
        fprintf(output, "%s\n", head->data.teamName);
        head = head->next;
    }
}