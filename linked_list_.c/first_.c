#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *getnode()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    return p;
}
void InsEnd(struct node **start, int x)
{
    if ((*start) == NULL)
    {
        printf("LINKED LIST IS EMPTY\n");
    }
    else
    {
        struct node *p;
        p = (*start);
        while ((p->next) != NULL)
        {
            p = p->next;
        }
        struct node *q = getnode();
        q->next = NULL;
        q->data = x;
        p->next = q;
    }
}
struct node *merge(struct node *s1, struct node *s2)
{
    struct node *p, *q, *start3;
    p = s1;
    q = s2;
    start3=NULL;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            InsEnd(start3, p->data);
            p = p->next;
        }
        else
        {
            InsEnd(start3, q->data);
            q = q->next;
        }
    }
    while (p != NULL)
    {
        InsEnd(start3, p->data);
        p = p->next;
    }
    while (q != NULL)
    {
        InsEnd(start3, q->data);
        q = p->next;
    }
    return start3;
}
struct node *inserthead(struct node *head, int data)
{
    struct node *temp, *ptr;
    ptr = head;
    temp = getnode();
    temp->data = data;
    temp->next = ptr;
    ptr = temp;
    head = ptr;
    return head;
}
struct node *insertail(struct node *tail, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = tail;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return tail;
}
void print(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
struct node *reverse(struct node *head)
{
    struct node *forward, *curr, *prev;
    prev = NULL;
    curr = head;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
int main()
{
    struct node *head, *tail, *q1, *q2, *q3, *q4;
    head = getnode();
    head->data = 3;
    head->next = NULL;
    tail = getnode();
    tail->data = 1;
    tail->next = NULL;

    //    head->next=NULL;
    //    head=inserthead(head,1);
    //    head=inserthead(head,2);
    //    head=inserthead(head,3);
    //    head=inserthead(head,5);

    head = insertail(head, 4);
    head = insertail(head, 5);
    tail = insertail(tail, 2);
    tail = insertail(tail, 3);
    tail = insertail(tail, 4);
    tail = insertail(tail, 5);
    struct node *list = merge(head, tail);
    print(list);
}