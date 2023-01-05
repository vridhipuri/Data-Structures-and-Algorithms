//implementation of stack using LL
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int n)
    {
        this->data=n;
        this->next=NULL;
    }
};
class Stack
{
    public:
    Node* top;

    Stack()
    {
        top=NULL;
    }

    void push(int value)
    {
        Node* temp=new Node(value);
        if(temp==NULL)
        {
            cout<<"Stack Overflow"<<endl;
        }
        else{
            temp->data=value;
            temp->next=top;
            top=temp;
        }
    }
    void pop()
    {
        Node* temp;
        if(top==NULL)
        {
            cout<<"Stack Underflow"<<endl;
        }
        else{
            temp=top;
            top=top->next;
            temp->next=NULL;
            delete temp;

        }
    }
    void peek()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"\nTop element is "<<top->data<<endl;
        }
    }
    void isEmpty()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"Stack contains atleast one element"<<endl;
        }
    }
    void display()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty"<<endl;
        }
        else{
            Node* temp=top;
            while(temp!=NULL)
            {
                cout<<temp->data;
                temp=temp->next;
                if(temp!=NULL)
                {
                    cout<<"->";
                }
            }

        }
    }
};
int main()
{
    Stack s;
    s.isEmpty();
    s.push(5);
    s.push(10);
    s.push(15);
    /*s.push(10);
    s.push(10);
    s.push(10);*/
    s.display();
    s.peek();
    s.pop();
    s.isEmpty();
    s.display();
    s.peek();
    return 0;

}