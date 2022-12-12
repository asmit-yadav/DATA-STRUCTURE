#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
//*****************************************************//
void transverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
//************************************// case -1
struct node *insertfirst(struct node *head, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    head=ptr;
    return ptr;
}
//******************************************//
struct node *insertafternode(struct node *head, struct node *prenode,int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prenode->next;
    prenode->next=ptr;
    return head;
}
//**********************************************//
struct node *insertiend(struct node *head, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
//***************************************************//
struct node *insertindex(struct node *head, int data, int index)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
//****************************************************************//
int main()
{
    struct node *head, *second, *third, *fourth, *link, *ptrs;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = 15;
    third = (struct node *)malloc(sizeof(struct node));
    third->data = 20;
    fourth = (struct node *)malloc(sizeof(struct node));
    fourth->data = 100;
    link = (struct node *)malloc(sizeof(struct node));
    link->data = 200;
    head->next = link;
    link->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    head = insertfirst(head, 5);
    // head = insertindex(head, 256,1);
    // printf(" before insertion\n");
    // transverse(head);
    // // head = insertiend(head, 500);
    // printf(" after insertion\n");
    // head=insertafternode(head,second,600);
    transverse(head);
}