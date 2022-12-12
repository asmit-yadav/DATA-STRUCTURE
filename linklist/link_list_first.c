#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head, *second, *third, *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = 15;
    third = (struct node *)malloc(sizeof(struct node));
    third->data = 20;
    fourth = (struct node *)malloc(sizeof(struct node));
    fourth->data=100;
    printf("%d  %d  %d %d \n", head->data, second->data, third->data,fourth->data);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;
    printf("%d  %d  %d %d\n", head, second, third, fourth);
    printf("%d %d\n", head->next, second->next);
    printf("%d %d\n", second->next, third->next);
    printf("%d %d\n", third->next, fourth->next);
}