#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

//******************************************************//
void transverse(struct node *head)
{
    struct node *ptr = head;
     
    do
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    // printf("%d ", ptr->data);
    printf("\n");
}
//*********************************************//
struct node *insertfirst(struct node *head, int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
//***********************************************************//
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
    fourth->next = head;
    transverse(head);
    insertfirst(head, 1);
    transverse(head);
}
