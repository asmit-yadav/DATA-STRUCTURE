#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head, *new, *temp;
;
int main()
{
    int n = 2;
    create(n);
    transverse();
}
void create(int n)
{
    head = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("no alloction");
        exit(0);
    }
    int data;
    scanf("%d", &data);
    head->data = data;
    temp = head;
    for (int i = 1; i <= n; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        if (new == NULL)
        {
            printf(" ");
            exit(0);
        }
        scanf("%d", &data);
        new->data = data;
        new->next = NULL;
        temp->next = new;
        temp = temp->next;
    }
}
void transverse()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}