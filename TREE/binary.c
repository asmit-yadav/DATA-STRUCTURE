#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create()
{
    struct node *p;
    int x;
    printf("Enter the element is not insert then tap -1\n");
    scanf("%d", &x);
    if (x == -1)
        return NULL;

    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    printf("insert the left child %d\n", x);
    p->left = create();
    printf("insert the right child %d\n", x);
    p->right = create();
    return p;
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);

    preorder(root->right);
}
// 3 2 1 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main()
{
    struct node *p = create();
    inorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    preorder(p);
}