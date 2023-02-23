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
        this->next = NULL;
    }
    ~node()
    {
        int value=this->data;
        if(next!=NULL)
        {
            delete next;
            next =NULL;
        }
        cout << "memory is free for node with data=>:" << value << endl;
    }
};
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
void insertatposition(node *&tail,node *&head, int position, int d)
{
    if (position == 1)
    {
        insertionathead(head, d);
        return;
    }
    node *temp =head;
    int i = 1;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL)
    {
        insertail(tail,d);
        return;
    }
    node *nodetoinsert=new node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}
void deletenode(int position, node *&head)
{
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next->prev= NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        node *current = head;
        node *prevoius = NULL;
        int i = 1;
        while (i < position)
        {
            prevoius = current;
            current = current->next;
            i++;
        }
        prevoius->next->prev=NULL;
        prevoius->next = current->next;
        current->next = NULL;
        delete current;
    }
}
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    print(head);
    insertail(tail, 12);
    insertail(tail, 13);
    insertail(tail, 14);
    insertail(tail, 16);
    insertail(tail, 18);
    insertatposition(tail,head,4,1000);
     deletenode(4, head);
    print(head);
}