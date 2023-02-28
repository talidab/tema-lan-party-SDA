#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libs\list.h"

BSTNode *newNode(Team data)
{
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
BSTNode *insert(BSTNode *node, Team key)
{
    if (node == NULL)
        return newNode(key);
    if (key.punctaj > node->data.punctaj)
        node->left = insert(node->left, key);
    else if (key.punctaj < node->data.punctaj)
        node->right = insert(node->right, key);
    else if (key.punctaj == node->data.punctaj)
    {
        if (strcmp(key.teamName, node->data.teamName) > 0)
            node->left = insert(node->left, key);
        else if (strcmp(key.teamName, node->data.teamName) < 0)
            node->right = insert(node->right, key);
    }
    return node;
}
void inorder(BSTNode *root, FILE *f)
{
    if (root != NULL)
    {
        inorder(root->left, f);
        fprintf(f, "%-34s-  %.2f\n", root->data.teamName, root->data.punctaj);
        inorder(root->right, f);
    }
}
BSTNode *createBST(Node *head)
{
    BSTNode *root = NULL;
    while (head != NULL)
    {
        root = insert(root, head->data);
        head = head->next;
    }
    return root;
}