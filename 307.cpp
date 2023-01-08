//Implement a method to insert an element at its bottom without using any other data structure.
#include<iostream>
#include<stack>
using namespace std;
stack<int> recur(stack<int>s, int n)
{
    if(s.empty())
    {
        s.push(n);
    }
    else{
        int x=s.top();
        s.pop();
        s = recur(s,n);
        s.push(x);
    }
    return s;
}
int main()
{
    int n;
    stack<int>s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    cout<<"Enter n"<<endl;
    cin>>n;
    s = recur(s,n);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;

}