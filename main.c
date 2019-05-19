#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

void tree_print(struct Node* p)
{
    if(p != NULL)
    {
        tree_print(p->left);
        printf("%d ", p->value);
        tree_print(p->right);
    }
}

struct Node* tree_add(struct Node* p, int x)
{
    if(p == NULL)
    {
        p = malloc(sizeof(struct Node));
        p->value = x;
        p->left = p->right = NULL;
    }
    else if(x < p->value)
    {
        p->left = tree_add(p->left, x);
    }
    else
    {
        p->right = tree_add(p->right, x);
    }
    printf("%d ", p);
    return p;
}

int main()
{
   struct Node* mytree = NULL;
   mytree = tree_add(mytree, 7);
   mytree = tree_add(mytree, 3);
   mytree = tree_add(mytree, 2);
   mytree = tree_add(mytree, 9);
   mytree = tree_add(mytree, 5);
   mytree = tree_add(mytree, 14);
   mytree = tree_add(mytree, 6);
   tree_print(mytree);
   return 0;
}
