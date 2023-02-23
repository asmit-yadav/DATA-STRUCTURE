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
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data=>:" << value << endl;
    }
};
void insertnode(node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        node *newnode = new node(d);
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        node *temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(node *&tail)
{
    node *temp = tail;
    if(tail==NULL)
    {
        cout<<"linked list is empty"<<endl;
        return;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
void deletenode(node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "list is empty ,please check again" << endl;
        return;
    }
    else
    {
        // non-empty
        // assuming that value is present in the linked list
        node *prev = tail;
        node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        //one node linked list
        if(curr==prev)
        {
            tail=NULL;
        }
       else  if(tail==curr)
        {
            tail=prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    node *tail = NULL;
    insertnode(tail, 5, 3);
    insertnode(tail, 3, 5);
    insertnode(tail, 5, 7);
    insertnode(tail, 7, 9);
    insertnode(tail, 9, 10);
    insertnode(tail, 3, 4);
    // deletenode(tail, 3);
    // deletenode(tail, 10);
    print(tail);
}