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
class Stack
{
    node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(int data)
    {
        node *temp = new node(data);
        if (!temp)
        {
            cout << "stack is overflow" << endl;
            exit(1);
        }
        temp->data = data;
        temp->next = top;
        top = temp;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    int peek()
    {
        if (!isEmpty())
        {
            return top->data;
        }
        else
            exit(1);
    }
    void pop()
    {
        node *temp;

        if (top == NULL)
        {
            cout << "stack is underflow" << endl;
        }
        else
        {
            temp = top;
            top = top->next;
            free(temp);
        }
    }
    void display()
    {
        node *temp;
        if (temp == NULL)
        {
            cout << "stack underflow" << endl;
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    return 0;
}