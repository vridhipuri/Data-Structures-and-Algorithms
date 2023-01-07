//implementation of queue using linked list
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
class Queue{
    public:
    Node* front;
    Node* rear;
    Queue()
    {
        front=NULL;
        rear=NULL;
    }
    void enqueue(int value)
    {
        Node* temp=new Node(value);
        if(rear==NULL)
        {
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }
    void dequeue()
    {
        if(front==NULL)
        {
            return;
        }
        Node* temp=front;
        front=front->next;
        delete temp;
        if (front==rear)
        {
            front=rear=NULL;
        }
    }
    void display()
    {
        Node* temp=front;
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
};

int main(){
    Queue q;
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    q.enqueue(15);
    q.display();
    cout<<endl;
    q.dequeue();
    q.display();
    cout<<endl;
    q.dequeue();
    q.display();
    return 0;
}
