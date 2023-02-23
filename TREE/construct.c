#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void postorder(struct node *n)
{
    if (n == NULL)
    {
        return;
    }
    postorder(n->left);
    postorder(n->right);
    printf("%d ", n->data);
}
void inorder(struct node *n)
{
    if (n == NULL)
    {
        return;
    }
    inorder(n->left);
    printf("%d ", n->data);
    inorder(n->right);
}
void preorder(struct node *n)
{
    if (n == NULL)
    {
        return;
    }
    printf("%d ", n->data);
    preorder(n->left);
    preorder(n->right);
}
struct node *newnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right= NULL;
    return n;
}
int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}