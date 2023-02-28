#include <stdio.h>
#include <stdlib.h>
#include "libs\list.h"
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *f1, *f2, *f3;
    Node *lista;
    BSTNode *root;
    int *cerinte = (int *)malloc(5 * sizeof(int));
    //char c1[100],c2[100],c3[100];
    f1 = fopen(argv[1], "rt");
    if (f1 == NULL)
    {
        puts("Fisierul cu date de intrare c.in nu poate fi deschis!");
        exit(1);
    }
    f2 = fopen(argv[2], "rt");
    if (f2 == NULL)
    {
        puts("Fisierul cu date de intrare d.in nu poate fi deschis!");
        exit(1);
    }
    f3 = fopen(argv[3], "wt");
    if (f3 == NULL)
    {
        puts("Fisierul cu date de iesire nu poate fi deschis!");
        exit(1);
    }
    Node *head;
    //cerinta 1:
    for (int i = 0; i < 5; i++)
        fscanf(f1, "%d", &cerinte[i]);
    if (cerinte[0] == 1)
    {
        head = makeList(f2);
    }

    //cerinta 2:
    if (cerinte[1] == 1)
    {
        sterge(&head);
    }
    print_c1(head, f3);

    //cerinta 3
    if (cerinte[2] == 1)
        lista = meciuri(head, f3);

    //cerinta 4
    if (cerinte[3] == 1)
    {
        root = createBST(lista);
        fprintf(f3, "\nTOP 8 TEAMS:\n");
        inorder(root, f3);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    while (head != NULL)
    {
        for (int i = 0; i < head->data.nr_jucatori; i++)
        {
            free(head->data.p[i].firstName);
            free(head->data.p[i].secondName);
        }
        free(head->data.teamName);
        head = head->next;
    }
    free(head);
    head = NULL;
    while (lista != NULL)
    {
        for (int i = 0; i < lista->data.nr_jucatori; i++)
        {
            free(lista->data.p[i].firstName);
            free(lista->data.p[i].secondName);
        }
        free(lista->data.teamName);
        lista = lista->next;
    }
    free(lista);
    lista = NULL;
    free(root);
    root = NULL;
    return 0;
}