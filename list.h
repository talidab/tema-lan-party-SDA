#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

//pentru lista
typedef struct node
{
    Team data;
    struct node *next;
} Node;

//pentru coada
typedef struct elem
{
    Team team1, team2;
    struct elem *next;
} Queue_Node;
typedef struct
{
    Queue_Node *front, *rear;
} Queue;

//pentru stiva
typedef struct stack
{
    Node *head;
    int size;
} Stack;

//pentru arborele binar de cautare
typedef struct nod
{
    Team data;
    struct nod *left, *right;
} BSTNode;

//functii pentru cerinta 1:
Node *makeNode(Team data, Node *next); 
Node *makeList(FILE *file); 
void addAtBeginning(Node **head, Team data); 
void print_c1(Node *head, FILE *f); 

//functii pentru cerinta 2:
int nrEchipe(Node *head);
float scorMinim(Node *head);
void deleteNode(Node **head, float scor);
int verif_putere(int n);
void sterge(Node **head);

//functii pentru cerinta 3:
Queue *createQueue();
void enQueue(Queue *q, Team team1, Team team2);
Queue *populateQueue(Node *head);
int isEmpty(Queue *q);
void afisare_coada(Queue *q, FILE *f);
void deleteQueue(Queue **q);
Stack *createStack();
int isEmptyStack(Stack *stack);
void push(Stack *stack, Team data);
Team pop(Stack **stack);
void populare_stive(Queue *q, Stack **invinsi, Stack **castigatori, Stack **copie);
void afisare_stiva(Stack *stack, FILE *f);
void deleteStack(Stack **stack);
int putere(int n);
Node *creareLista(Stack *stack);
Node *meciuri(Node *head, FILE *f);

//functii pentru cerinta 4:
BSTNode *newNode(Team data);
BSTNode *insert(BSTNode *node, Team key);
void inorder(BSTNode *root, FILE *f);
BSTNode *createBST(Node *head);