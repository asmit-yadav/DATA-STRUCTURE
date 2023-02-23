#include <iostream>
using namespace std;
class node
{
public:
    char data;
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
node *last(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next;
}
node *beg(node *&head, int data)
{
    node *temp = new node(data);
    node *ptr = head;
    temp->next = ptr;
    head = temp;
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
node *middle(node *head)
{
    node *fast = head->next;
    node *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
node * atanypostion(node *&head, int position)
{
    int i = 1;
    if (i == position)
    {
    node *ptr = head->next;
    node *temp = head;
    head = ptr;
    temp->next = NULL;
    delete (temp);
    }
    else
    {
        node *temp = head->next;
       node *a = head;
        while (i < position - 1)
        {
            a = a->next;
            temp = temp->next;
            i++;
        }
        a->next = temp->next;
        temp->next = NULL;
        delete (temp);
    }
}
void deleted(node *&head)
{
    node *ptr = head->next;
    node *temp = head;
    head = ptr;
    temp->next = NULL;
    delete (temp);
}
void lastdelete(node *&head)
{
    node *curr = head->next;
    node *prev = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
        prev = prev->next;
    }
    prev->next = curr->next;
    delete (curr);
}
void dellete(node *&head,char key)
{
    while(head->data==key)
    {
        head=head->next;
    }
    node *ptr=head;
    node *prev;
    while(ptr!=NULL)
    {
        if(ptr->data==key)
        {
           prev->next=ptr->next;
           ptr=prev->next;
        }
        else
        {
            prev=ptr;
            ptr=ptr->next;
        }
    }
    
}
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *p = new node('x');
    node *head = p;
    node *tail = p;
    beg(head, '1');
    beg(head, '2');
    beg(head, 'x');
    beg(head, '3');
    beg(head, 'x');
    last(tail, '4');
    last(tail, 'x');
    last(tail, 'x');
    print(head);
    // reverseList(head);
    // cout<<middle(tail)->data<<endl;
    // deleted(head);
    // print(head);
    // lastdelete(head);
    // print(head);
    // occurance(head,2);
    dellete(head,'x');
    print(head);
}