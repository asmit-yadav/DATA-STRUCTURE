#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *right;
    struct node *left;
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
struct node *insertIntoData(node *&root, int data)
{
    if (root == NULL)
    {
        root = create();
        return root;
    }
    if (data > root->data)
    {
        root->right = insertIntoData(root->right, data);
    }
    else
        root->left = insertIntoData(root->left, data);

    return root;
}
void takeinput(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertIntoData(root, data);
        cin >> data;
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    struct node *p = NULL;
    takeinput(p);
    inorder(p);
}
// 3 2 1 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1