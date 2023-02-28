//functii pentru cerinta 5:
/*typedef struct nod_nou
{
    Team data;
    struct nod_nou *left;
    struct nod_nou *right;
    int height;
} AVLNode;

int height(AVLNode *nod)
{
    if (nod == NULL)
        return 0;
    return nod->height;
}
int maxim(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
AVLNode *newAVLNode(Team data)
{
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = maxim(height(y->left), height(y->right)) + 1;
    x->height = maxim(height(x->left), height(x->right)) + 1;
    return x;
}
AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = maxim(height(x->left), height(x->right)) + 1;
    y->height = maxim(height(y->left), height(y->right)) + 1;
    return y;
}
int getBalance(AVLNode *nod)
{
    if (nod == NULL)
        return 0;
    return height(nod->left) - height(nod->right);
}
AVLNode *insertNode(AVLNode *node, Team key)
{
    if (node == NULL)
        return (newAVLNode(key));
    if (key.punctaj > node->data.punctaj)
        node->left = insertNode(node->left, key);
    else if (key.punctaj < node->data.punctaj)
        node->right = insertNode(node->right, key);
    else if (key.punctaj == node->data.punctaj)
    {
        if (strcmp(key.teamName, node->data.teamName) > 0)
            node->left = insertNode(node->left, key);
        else if (strcmp(key.teamName, node->data.teamName) < 0)
            node->right = insertNode(node->right, key);
    }
    else
        return node;
    node->height = 1 + maxim(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key.punctaj < node->left->data.punctaj)
        return rightRotate(node);
    if (balance < -1 && key.punctaj > node->right->data.punctaj)
        return leftRotate(node);
    if (balance > 1 && key.punctaj > node->left->data.punctaj)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key.punctaj < node->right->data.punctaj)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void preOrder(AVLNode *root)
{
    if (root != NULL)
    {
        printf("%s\n", root->data.teamName);
        preOrder(root->left);
        preOrder(root->right);
    }
}
AVLNode *createAVL(Node *head)
{
    AVLNode *root = NULL;
    while (head != NULL)
    {
        root = insertNode(root, head->data);
        head = head->next;
    }
    return root;
}*/