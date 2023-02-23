#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
//************************FULL BINARY TREE***********************//
bool isFBT(struct node *root)
{
    if(root==NULL)
    return true;
    if(root->left==NULL&&root->right==NULL)
    return true;
    if(root->left&&root->right)
    return isFBT(root->left)&&isFBT(root->right);
    return false;
}
//******************COMPLETE BINRAY TREE **********************//
bool isCBT(struct node *root, int index, int size)
{
    int left,right;
    if (root == NULL)
        return true;
    if (index > size)
        return false;
    return isCBT(root->left, 2 * index, size) && isCBT(root->right, 2 * index + 1, size);
}
//*************************************//
int counttwonode(struct node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        if (root->left != NULL && root->right != NULL)
         return counttwonode(root->left) + counttwonode(root->right) + 1;
    }
}
//**********************************//
int countonechild(struct node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        if (root->left != NULL && root->right == NULL)
        {
            return countonechild(root->left) + 1;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            return countonechild(root->right) + 1;
        }
        return countonechild(root->left) + countonechild(root->right);
    }
}
//********************************//
int add(struct node *root)
{
    int left, right, sumleft = 0, sumright = 0;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        sumleft += add(root->left);
        sumright = add(root->right);
        return root->data + sumleft + sumright;
    }
}
//******************************//
int size(struct node *root)
{
    int left, right;
    if (root == NULL)
        return 0;
    else
    {
        return (1 + size(root->left)) + size(root->right);
    }
}
//*****************************//
int height(struct node *root)
{
    int left, right;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        left = height(root->left);
        right = height(root->right);
        if (left > right)
            return (left + 1);
        else
        {
            return (right + 1);
        }
    }
}
//************************INORDER***********//
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
//**************************PREORDER*********//
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
//******POSTORDER*************//
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
//****************************************//
struct node *newnode(int data)
{
    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    n1->data = data;
    n1->left = NULL;
    n1->right = NULL;
    return (n1);
}
int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->right=newnode(6);
    // inorder(root);
    // printf("\n");
    // preorder(root);
    // printf("\n");
    // postorder(root);
    // printf("\n%d\n", height(root));
    // int x=size(root);
    // printf("%d\n", size(root));
    // printf("\n%d\n", add(root));
     printf("\n%d\n",countonechild(root));
    // printf("%d", counttwonode(root));
    // printf("%d",isCBT(root,1,x));
    // if(isCBT(root,1,x))
    // {
    //     printf("YES");
    // }
    // else
    // {
    //     printf("NO");
    // }
    // printf("\n");
    // if(isFBT(root))
    // {
    //     printf("YES");
    // }
    // else
    // {
    // printf("NO");
    // }
}