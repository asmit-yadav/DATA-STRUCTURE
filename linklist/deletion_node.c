#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
//*******************************************************//
struct node *deletelast(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
//****************************************************//
struct node *deleteatvalue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    // printf("%d %d  %d   %d   %d  \n",p, *p, head, q, head->next);
    int i = 0;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}
//****************************************************//
struct node *deleteindex(struct node *head, int index)
{
    struct node *p = head;
    // struct node *q = head->next;
    printf("%d %d  %d     \n", p, *p, head);
    struct node *q = head->next;
    int i = 0;
    while (i < index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}
//************************************************************//
struct node *deletionfirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
//******************************************************//
void transverse(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    struct node *head, *second, *third, *fourth, *link, *ptrs;
    head = (struct node *)malloc(sizeof(struct node));
    printf("%d  \n", head);
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
    transverse(head);
    // head = deletionfirst(head); // for deleting first element of the linkedlist
    head = deleteindex(head, 3);
    // head = deletelast(head);
    // head = deleteatvalue(head, 15);
    //  printf("%d",head);
    transverse(head);
}
