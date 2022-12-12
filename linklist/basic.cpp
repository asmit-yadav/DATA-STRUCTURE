#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
} *head, *first, *second, *third, *fourth;
int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    
}
