//implement stack and queue using deque
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
};
class deque{
    public:
    node* head;
    node* tail;

    deque()
    {
        head=NULL;
        tail=NULL;
    }
    bool isEmpty()
    {
        if(head==NULL)
            return true;
        return false;
    }
    void insert_first(int element)
    {
        node* temp=new node[sizeof(node)]; //as it uses array of pointers
        temp->data=element;
        //if temp is first element
        if(head==NULL)
        {
            head=tail=temp;
            temp->prev=NULL;
            temp->next=NULL;
        }
        else{
            head->prev=temp;
            temp->next=head;
            temp->prev=NULL;
            head=temp;
        }
    }
    void insert_last(int element)
    {
        node* temp=new node[sizeof(node)];
        temp->data=element;
        //if temp is first element
        if(head==NULL)
        {
            head=tail=temp;
            temp->prev=NULL;
            temp->next=NULL;
        }
        else{
            tail->next=temp;
            temp->prev=tail;
            temp->next=NULL;
            tail=temp;
        }
    }
    void delete_first()
    {
        if(!isEmpty())
        {
            node* temp=head;
            head=head->next;
            head->prev=NULL;
            temp->next=NULL;
            delete temp;
            if(head==NULL)
                tail=NULL;
        }
        else
            cout<<"List is empty"<<endl;
    }
    void delete_last()
    {
        if(!isEmpty())
        {
            node* temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            temp->prev=NULL;
            delete temp;
            if(tail==NULL)
                head=NULL;
        }
        else
            cout<<"List is empty"<<endl;
    }
    void display()
    {
        node* temp=head;
        if(!isEmpty())
        {
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        else
            cout<<"List is empty"<<endl;
    }
};
class stack: public deque{
    public:
    void push(int element)
    {
        insert_last(element);
    }
    void pop()
    {
        delete_last();
    }
};
class queue:public deque{
    public:
    void enqueue(int element)
    {
        insert_last(element);
    }
    void dequeue()
    {
        delete_first();
    }
};
int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"Stack"<<endl;
    s.display();
    s.pop();
    cout<<"Stack"<<endl;
    s.display();

    queue q;
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    cout<<"Queue"<<endl;
    q.display();
    q.dequeue();
    cout<<"Queue"<<endl;
    q.display();
    return 0;
}

