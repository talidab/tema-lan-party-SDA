#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libs\list.h"

/* functie ce numara cate echipe se afla in lista*/
int nrEchipe(Node *head)
{
    int nr = 0;
    while (head != NULL)
    {
        nr++;
        head = head->next;
    }
    return nr;
}

/* functie ce calculeaza scorul minim */
float scorMinim(Node *head)
{
    float min = 9999;
    while (head != NULL)
    {
        if (head->data.punctaj < min)
            min = head->data.punctaj;
        head = head->next;
    }
    return min;
}

/* functie care sterge echipa cu scorul minim*/
void deleteNode(Node **head, float scor)
{
    if ((*head) == NULL)
        return;
    Node *headcopy = *head;
    if (headcopy->data.punctaj == scor)
    {
        (*head) = (*head)->next;
        //printf("ECHIPA ELIMINATA ESTE: %s\n", headcopy->data.teamName);
        free(headcopy);
        return;
    }
    Node *aux = (*head);
    headcopy = *head;
    while (headcopy != NULL)
    {
        if (headcopy->data.punctaj != scor)
        {
            aux = headcopy;
            headcopy = headcopy->next;
        }
        else
        {
            aux->next = headcopy->next;
            //printf("ECHIPA ELIMINATA ESTE: %s\n", headcopy->data.teamName);
            free(headcopy);
            return;
        }
    }
}

/* functie care verifica daca un numar este putere a lui 2 */
int verif_putere(int n)
{
    while (n % 2 == 0)
        n = n / 2;
    if (n == 1)
        return 1;
    else
        return 0;
}

/* functie care elimina din lista echipele cu cel mai mic punctaj, 
astfel incat sa ramana n echipe cu n putere a lui 2 */
void sterge(Node **head)
{
    if (verif_putere(nrEchipe(*head)) == 1)
        return;
    while (verif_putere(nrEchipe(*head)) == 0)
    {
        if (verif_putere(nrEchipe(*head)) == 0)
        {
            float scor = scorMinim(*head);
            deleteNode(head, scor);
        }
    }
}