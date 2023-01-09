//Implement a Circular queue
#include<iostream>
using namespace std;
class cqueue{
    public:
    int* arr;
    int size;
    int front,rear;
    cqueue(int n)
    {
        size=n;
        arr=new int[n];
        front=-1;
        rear=-1;
    }
    void enqueue(int element)
    {
        if((front==0 && rear==size-1) || front==rear+1)
            cout<<"Overflow"<<endl;
        else{
            rear=(rear+1)%size;
            arr[rear]=element;
            if(front==-1)
                front=0;
        }
    }
    void dequeue()
    {
        if(front==-1)
        {
            cout<<"Underflow"<<endl;
        }
        else if(front==rear){
            front=rear=-1;

        }
        else{
            front=(front+1)%size;
        }
    }
    void display()
    {
        int i;
        if(front==-1)
        {
            cout<<"Underflow"<<endl;
        }
        else{
            for(i=front; i!=rear; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<arr[i];
        }
    }
};
int main(){
    cqueue c(5);
    c.enqueue(10);
    c.enqueue(20);
    c.enqueue(30);
    c.enqueue(40);
    c.enqueue(50);
    cout<<endl;
    c.display();
    cout<<endl;
    c.dequeue();
    c.display();
    return 0;
}