#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void insertTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertathead(node *&head, int d)
{
        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
}
int length(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}
void inserAtPosition(node *&tail, node *&head, int position, int d)
{
    if (position == 1)
    {
        insertathead(head, d);
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
        insertTail(tail, d);
        return;
    }
    node *nodeToinsert = new node(d);
    nodeToinsert->next = temp->next;
    temp->next->prev = nodeToinsert;
    temp->next = nodeToinsert;
    nodeToinsert->prev = temp;
}

int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    insertTail(tail, 22);
    inserAtPosition(tail, head, 2, 100);
    print(head);
}