//Delete Middle Element in Stack
//see copy
//https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    void solve(stack<int>&s, int size, int count)
{
    if(count==size/2)
    {
        s.pop();
        return;
    }
    int x=s.top();
    s.pop();
    solve(s,size,count+1);
    s.push(x);
    return;
}
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int count=0;
        solve(s,sizeOfStack,count); 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends