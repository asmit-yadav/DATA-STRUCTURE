#include <iostream>
using namespace std;
class ListNode
{
public:
    int data;
    bool ans;
    ListNode *next;
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~ListNode()
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
ListNode *beg(ListNode *&head, int data)
{
    ListNode *temp = new ListNode(data);
    ListNode *ptr = head;
    temp->next = ptr;
    head = temp;
}
bool hasCycle(ListNode *head)
{
    if (head == NULL)
        return false;
    if (head->next == NULL)
        return false;
    else
    {
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast != NULL)
        {
            if (fast->next == slow)
                return true;
            else
            {
                fast = fast->next;
                if (fast != NULL)
                {
                    fast = fast->next;
                }
                slow = slow->next;
            }
        }
    }
    
}
 ListNode *loop( ListNode *&head)
 {
     ListNode *ptr=head;
     ListNode *temp=head->next;
     while(ptr!=NULL)
    {
    
        ptr=ptr->next;
    }
    ptr=temp;
   if(hasCycle(head))
   cout<<"true"<<endl;
   else
   cout<<"false"<<endl;
   
 }
int main()
{
  ListNode *p=new ListNode(-4);
   ListNode *head=p;
   beg(head,0);
   beg(head,2);
   beg(head,1);
   loop(head);
}