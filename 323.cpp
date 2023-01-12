//Interleave the first half of the queue with second half
#include<iostream>
#include<queue>
using namespace std;
void interleave(queue<int>& q)
{
    queue<int>temp;
    int half=q.size()/2;
    for(int i=0;i<half;i++)
    {
        temp.push(q.front());
        q.pop();
    }
    while(!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
        q.push(q.front());
        q.pop();
    }
}
int main()
{
    queue<int>q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    
    interleave(q);
    cout<<"Interleaved Queue\n";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}