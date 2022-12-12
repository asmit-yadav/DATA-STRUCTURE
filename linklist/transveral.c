#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int counts(struct node *ptr)
{
    int count=0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
int search(struct node *ptr,int key)
{
int i=0;
while (ptr != NULL)
    {
        if(ptr->data==key)
        {
            return i;
        }
         ptr = ptr->next;
         i++;
    }
   return -1;
}
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
    struct node *head, *second, *third, *fourth, *link ,*ptrs;
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
    transverse(head);
    printf("%d\n",counts(head));
    int k=search(head,100);
    printf("%d",k);
}