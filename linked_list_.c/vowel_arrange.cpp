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
        char value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data=>:" << value << endl;
    }
};
node *beg(node *&head, char data)
{
    node *temp = new node(data);
    node *ptr = head;
    temp->next = ptr;
    head = temp;
}
node *vowels(node *&head)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data=='a'||ptr->data=='e'||ptr->data=='i'||ptr->data=='o'||ptr->data=='u')
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        else
        ptr=ptr->next;
    }
    node *temp=head;
    while(temp!=NULL)
    {
        if(!(temp->data=='a'||temp->data=='e'||temp->data=='i'||temp->data=='o'||temp->data=='u'))
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        else
        temp=temp->next;
    }
    cout<<endl;
}
void print(node *&head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
   node *p=new node('a');
   node *head=p;
   beg(head,'b');
   beg(head,'c');
   beg(head,'e');
//    print(head);
   vowels(head);
  
}