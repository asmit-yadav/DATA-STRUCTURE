#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
int getlength(node *&head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

node *reverseList(node *head)
{
    node *prev = NULL;
    node *curr = head;
    node *forward;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
void insertionathead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void print(node *&head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
    cout << endl;
}
void insertail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next;
}
void insertatposition(node *&tail, node *&head, int position, int d)
{
    if (position == 1)
    {
        insertionathead(head, d);
        return;
    }
    node *temp = head;
    int i = 1;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL)
    {
        insertail(tail, d);
        return;
    }
    node *nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    insertail(tail, 20);
    insertail(tail, 30);
    // insertatposition(tail, head, 3, 100);
    print(head);
    reverseList(head);
    print(tail);
}