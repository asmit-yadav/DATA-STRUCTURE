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
node *beg(node *&head, int data)
{
    node *temp = new node(data);
    node *ptr = head;
    temp->next = ptr;
    head = temp;
}
void print(node *&head)
{
    node *ptr = head;
    while (ptr->next != NULL)
    {
        cout << ptr->data << " ";
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
node *add(node *l1, node *l2)
{
    node *ans = new node(0);
    node *p = reverseList(l1), *q = reverseList(l2), *curr = ans;
    int carry = 0;
    while (p != NULL || q != NULL)
    {
        int x = (p != NULL) ? p->data : 0;
        int y = (q != NULL) ? q->data : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = new node(sum % 10);
        curr = curr->next;
        if (p != NULL)
            p = p->next;
        if (q != NULL)
            q = q->next;
    }
    if (carry > 0)
        curr->next = new node(carry);

    ans=reverseList(ans);
    return ans;
}
// node *add(node *head, node *head1)
// {
//     node *p = reverseList(head);
//     node *q = reverseList(head1);
//     node *temp ;
//     int carry = 0;
//     int t = 0;
//     while (p != NULL && q != NULL)
//     {
//         int t = p->data + q->data + carry;
//         t = t % 10;
//         beg(temp,t);
//         carry = t / 10;
//         p = p->next;
//         q = q->next;
//     }
//     while (p != NULL)
//     {
//         t = p->data+ carry;
//         t = t % 10;
//         beg(temp,t);
//         carry = t / 10;
//     }
//       while (q!= NULL)
//     {
//         t = q->data+ carry;
//         t = t % 10;
//         beg(temp,t);
//         carry = t / 10;
//         q=q->next;
//     }
//     while(temp->next!=NULL)
//     {
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
// }
int main()
{
    node *p = new node(1);
    node *tail = p;
    node *head = p;
    insertail(tail, 2);
    insertail(tail, 5);
    node *node2 = new node(8);
    node *head1 = node2;
    node *tails = node2;
    insertail(tails, 5);
    print(head1);
    print(head);
    node *m = add(head, head1);
    node *n=m;
    print(m);
    // reverseList(head);
    // reverseList(head1);
}