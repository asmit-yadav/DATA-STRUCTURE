#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void delete(struct node *node1)
{
    if(node1==NULL)
    return ;
    deletetree(node1->left);
    printf("%d ",node1->data);
}
void deletetree(struct node **root)
{
    struct node *noder;
    deletetree(noder);
    noder=NULL;

}
void inorder(struct node * n)
{
    if (n != NULL){
    inorder(n->left);
    printf("%d ", n->data);
    inorder(n->right);
    }
}
struct node *newnode(int x)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
struct node *create(struct node *root, int x)
{
    if (root == NULL)
        return newnode(x);
    if (x < root->data)
        create(root->left, x);
    else
        create(root->right, x);
    return root;
}
int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root=newnode(20);
    create(root, 15);
    create(root, 30);
    create(root, 40);
    create(root, 50);
    create(root, 12);
    create(root, 18);
    create(root, 35);
    create(root, 80);
    create(root, 7);
    inorder(root);
}