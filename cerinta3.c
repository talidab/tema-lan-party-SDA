#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libs\list.h"

/* functie ce creeaza o coada de elemente si aloca memorie pentru ea*/
Queue *createQueue()
{
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
    {
        puts("Alocare dinamica coada esuata!");
        exit(1);
    }
    q->front = q->rear = NULL;
    return q;
}

/* functie ce adauga in coada cele 2 echipe care se confrunta */
void enQueue(Queue *q, Team team1, Team team2)
{
    Queue_Node *newNode = (Queue_Node *)malloc(sizeof(Queue_Node));
    newNode->team1 = team1;
    newNode->team2 = team2;
    newNode->next = NULL;
    if (q->rear == NULL)
        q->rear = newNode;
    else
    {
        (q->rear)->next = newNode;
        q->rear = newNode;
    }
    if (q->front == NULL)
        q->front = q->rear;
}

/*functie ce populeaza coada de meciuri */
Queue *populateQueue(Node *head)
{
    Queue *q;
    q = createQueue();
    while (head != NULL)
    {
        enQueue(q, head->data, head->next->data);
        head = head->next->next;
    }
    return q;
}

/*functie ce verifica daca coada este goala */
int isEmpty(Queue *q)
{
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

/*functie ce afiseaza continutul cozii*/
void afisare_coada(Queue *q, FILE *f)
{
    Queue *copie = q;
    while (q->front != NULL)
    {
        fprintf(f, "%-33s-%33s\n", q->front->team1.teamName, q->front->team2.teamName);
        q->front = q->front->next;
    }
    q->front = copie->front;
}

/*functie ce sterge coada si elibereaza zona de memorie*/
void deleteQueue(Queue **q)
{
    Queue_Node *aux;
    while (!isEmpty(*q))
    {
        aux = (*q)->front;
        (*q)->front = aux->next;
        free(aux);
    }
    free(*q);
    (*q) = NULL;
}

/*functie ce creeaza stiva de elemente si aloca memorie pentru ea */
Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        puts("Alocare dinamica stiva esuata!");
        exit(1);
    }
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

/*functie ce verifica daca stiva este goala*/
int isEmptyStack(Stack *stack)
{
    if (stack->size == 0)
        return 1;
    else
        return 0;
}

/*functie ce adauga un element in stiva*/
void push(Stack *stack, Team data)
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    stack->size++;
    if (isEmptyStack(stack) == 1)
        stack->head = newNode;
    else
    {
        newNode->next = stack->head;
        stack->head = newNode;
    }
}

/*functie ce scoate un element din varful stivei */
Team pop(Stack **stack)
{
    if (isEmptyStack(*stack))
    {
        printf("Stiva goala!");
        exit(1);
    }
    else
    {
        Node *aux;
        aux = (*stack)->head;
        Team data;
        data.p = (Player *)malloc(aux->data.nr_jucatori * sizeof(Player));
        data = aux->data;
        (*stack)->head = (*stack)->head->next;
        aux->next = NULL;
        free(aux);
        (*stack)->size--;
        return data;
    }
}

/*functie ce creeaza stiva de invinsi si stiva de castigatori*/
void populare_stive(Queue *q, Stack **invinsi, Stack **castigatori, Stack **copie)
{
    (*invinsi) = createStack();
    (*castigatori) = createStack();
    (*copie) = createStack();
    while (!isEmpty(q))
    {
        if (q->front->team1.punctaj > q->front->team2.punctaj)
        {
            q->front->team1.punctaj = q->front->team1.punctaj + 1;
            push((*castigatori), q->front->team1);
            push((*copie), q->front->team1); //am populat si copia stivei pe care o voi folosi la afisare
            push((*invinsi), q->front->team2);
        }
        else if (q->front->team1.punctaj <= q->front->team2.punctaj)
        {
            q->front->team2.punctaj = q->front->team2.punctaj + 1;
            push((*castigatori), q->front->team2);
            push((*copie), q->front->team2); //am populat si copia stivei pe care o voi folosi la afisare
            push((*invinsi), q->front->team2);
        }
        q->front = q->front->next;
    }
}

/*functie ce afiseaza continutul stivei*/
void afisare_stiva(Stack *stack, FILE *f)
{
    while (stack->head != NULL)
    {
        fprintf(f, "%-34s-  %.2f\n", stack->head->data.teamName, stack->head->data.punctaj);
        stack->head = stack->head->next;
    }
}

/*functie ce sterge stiva si elibereaza zona de memorie*/
void deleteStack(Stack **stack)
{
    Node *aux;
    while ((*stack)->head != NULL)
    {
        aux = (*stack)->head;
        (*stack)->head = (*stack)->head->next;
        free(aux);
        (*stack)->size--;
    }
    free(*stack);
    (*stack) = NULL;
}

//functie ce calculeaza k, 2^k=n
int putere(int n)
{
    int k = 0;
    while (n % 2 == 0)
    {
        n = n / 2;
        k++;
    }
    return k;
}

/*functie ce creeaza o lista simplu inlantuita avand ca parametru o stiva */
Node *creareLista(Stack *stack)
{
    Node *head = NULL;
    Team data;
    int nr = 0;
    while (!isEmptyStack(stack))
    {
        data = pop(&stack);
        if (nr == 0)
            head = makeNode(data, NULL);
        else
        {
            Node *newNode;
            newNode = makeNode(data, head);
            head = newNode;
        }
        nr++;
    }
    return head;
}

/*functia ce tine evidenta meciurilor si afiseaza castigatorii pentru fiecare runda */
Node *meciuri(Node *head, FILE *f)
{
    Queue *q, *copie_queue;
    Node *lista;
    Stack *invinsi, *castigatori, *copie_stack, *stiva_invers;
    int i, n = putere(nrEchipe(head)), nr = nrEchipe(head);
    for (i = 0; i < n; i++)
    {
        nr = nr / 2;
        fprintf(f, "\n--- ROUND NO:%d\n", i + 1);
        q = populateQueue(head);
        copie_queue = populateQueue(head); //aici am facut o copie cozii pe care am sacrificat-o doar pentru afisare
        afisare_coada(copie_queue, f);
        populare_stive(q, &invinsi, &castigatori, &copie_stack);
        fprintf(f, "\nWINNERS OF ROUND NO:%d\n", i + 1);
        afisare_stiva(castigatori, f);
        stiva_invers = createStack();
        Team data;
        while (!isEmptyStack(copie_stack))
        {
            data = pop(&copie_stack);
            push(stiva_invers, data);
        }
        Node *cap = creareLista(stiva_invers); //am creat o stiva cu elementele in ordinea inversa din stiva de castigatori
        if (nr == 8)
        {
            lista = cap; //lista cu echipele de pe primele 8 locuri pentru cerinta urmatoare
        }
        deleteQueue(&q);
        deleteQueue(&copie_queue);
        head = cap;
        deleteStack(&invinsi);
        deleteStack(&castigatori);
        deleteStack(&copie_stack);
        deleteStack(&stiva_invers);
    }
    return lista;
}