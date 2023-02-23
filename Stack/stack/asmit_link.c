#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *beg(struct node *head, int x)
{
    struct node *ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    temp->next = ptr;
    ptr = temp;
    head = ptr;
    return head;
}
struct node *last(struct node *head, int x)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ptr->data = x;
    ptr->next = NULL;
    temp->next = ptr;
    return head;
}
struct node *after(struct node *head, int data, int elements)
{
    struct node *x = (struct node *)malloc(sizeof(struct node));
    x->data = data;
    x->next = NULL;
    struct node *temp = head;
    struct node *ptr = head->next;
    while (temp->data != elements)
    {
        temp = temp->next;
        ptr = ptr->next;
    }
    temp->next = x;
    x->next = ptr;
    return head;
}
struct node *deletend(struct node *head)
{
    struct node *temp=head;
    struct node *ptr=NULL;
    while(temp->next!=NULL)
    {
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=NULL;
    free (temp);
    return head;

}
struct node *deleteafter(struct node *head,int data)
{
    struct node *temp=head;
    struct node *ptr=temp->next;
    while(temp->data!=data)
    {
        ptr=ptr->next;
        temp=temp->next;
    }
    temp->next=ptr->next;
    free (ptr);
    return head;
}
struct node *reverse(struct node *head)
{
    struct node *curr=head;
    struct node *forward;
    struct node *prev=NULL;
    while(curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
   return prev;
}
struct node *deletebeg(struct node *head)
{
    struct node *temp=head;
    head=temp->next;
    free (temp);
    return head;
}
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main()
{
    struct node *head, *p;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 2;
    head->next = NULL;
    //   p=head;
    head = beg(head, 6);
    head = last(head, 8);
    head = after(head, 5, 2);
     display(head);
     head=reverse(head);
    // head=deletebeg(head);
    // head=deletend(head);
    // head=deleteafter(head,2);
    printf("\n");
    display(head);
}