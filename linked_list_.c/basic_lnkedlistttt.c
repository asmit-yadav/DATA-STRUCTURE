#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *begdelete(struct node *head)
{
   struct node *ptr=head;
   struct node *temp=head->next;
   head=temp;
   free(ptr);
    return head;
}
struct node *at(struct node *head,int data,int position)
{
    struct node *temp=head;
    struct node *x=head->next;
    struct node *ptr=(struct node *)malloc(sizeof(struct node *));
    ptr->data=data;
    int i=0;
    while(i<position-1)
    {
       temp=temp->next;
       x=x->next;
       i++;
    }
    temp->next=ptr;
    ptr->next=x;
    return head;
}
struct node *last(struct node *head,int data)
{
    struct node *temp=head;
    struct node *ptr=(struct node *)malloc(sizeof(struct node *));
    ptr->data=data;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->next=NULL;
    return head;
}
struct node *beg(struct node *head, int data)
{
    struct node *temp = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = data;
    ptr->next = temp;
    temp = ptr;
    head = temp;
    return head;
}
// struct node *new_node(int data)
// {
//     struct node *temp=(struct node *)malloc(sizeof(struct node *));
//     temp->data=data;
//     temp->next=NULL;
//     return temp;
// }
void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct node *p1, *p2, *p3, *p4, *head,*tail;
    p1 = (struct node *)malloc(sizeof(struct node *));
    p2 = (struct node *)malloc(sizeof(struct node *));
    p3 = (struct node *)malloc(sizeof(struct node *));
    p4 = (struct node *)malloc(sizeof(struct node *));
    head = (struct node *)malloc(sizeof(struct node *));
    tail=(struct node *)malloc(sizeof(struct node *));
    p1->data = 2;
    p1->next = NULL;
    head = p1;
    head=last(head,3);
    head=last(head,4);
    head=last(head,5);
    head=last(head,6);
    head=begdelete(head);
    head=begdelete(head);
    head=begdelete(head);
    // head=at(head,0,0);
    // head = beg(head, 5);
    // head = beg(head, 3);
    // head = beg(head, 2);
    // head = beg(head, 1);
    print(head);
    // p2->data=3;
    // p3->data=4;
    // p4->data=5;
    // p1->next = p2;
    // p2->next = p3;
    // p3->next = p4;
    // p4->next = NULL;
}