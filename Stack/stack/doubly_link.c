#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *beg(struct node *head, int data)
{
    struct node *temp = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    ptr->next = temp;
    temp->prev = ptr;
    temp = ptr;
    head = ptr;
    return head;
}
struct node *after(struct node *head, int data, int element)
{
    struct node *temp = head;
    struct node *x = temp->next;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    while (temp->data != element)
    {
        x = x->next;
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->prev = temp;
    ptr->next = x;
    return head;
}
struct node *deleteafter(struct node *head, int element)
{
    struct node *temp = head;
    struct node *x = temp->next;
    while (temp->data != element)
    {
        x = x->next;
        temp = temp->next;
    }
    temp->next=x->next;
    x->next->prev=temp;
    x->next=NULL;
    x->prev=NULL;
    return head;
}
struct node *last(struct node *head, int data)
{
    struct node *temp = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ptr->prev = temp;
    temp->next = ptr;
    return head;
}

struct node *deletebeg(struct node *head)
{
    struct node *temp=head;
    head=temp->next;
    temp->next=NULL;
    temp->prev=NULL;
    free (temp);
    return head;

}
struct node *deletelast(struct node *head)
{
    struct node *temp=head;
    struct node *prev;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
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
    printf("\n");
}
int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 2;
    head->next = NULL;
    head->prev = NULL;
    head = beg(head, 3);
    head = last(head, 7);
    head = last(head, 8);
    head = last(head, 9);
    display(head);
    head=deleteafter(head,2);
    // head = after(head, 10, 7);
    // head=deletebeg(head);
    // head=deletelast(head);
    display(head);
}