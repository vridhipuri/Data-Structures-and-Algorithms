 //Implement Stack from Scratch using array
#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element)
    {
        //if atleast one element is present
        if(size-top>1){
            top++;
            arr[top]=element;
        }   
        else{
            cout<<"Stack Overflow"<<endl;
        }     
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top--;
        }
    }
    void peek()
    {
        if(top>-1)
        {
            cout<<"Top element of stack is "<<arr[top]<<endl;
        }
        else{
            cout<<"Stack is empty"<<endl;

        }
    }
    void isEmpty()
    {
        if(top==-1)
        {
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"Stack contains atleast one element"<<endl;
        }
    }
          
};
int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.peek();
    s.pop();
    s.peek();
    s.isEmpty();
    return 0;
}
