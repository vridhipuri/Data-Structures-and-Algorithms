//Design a Stack that supports getMin() in O(1) time and O(1) extra space.
//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends


void push(stack<int>& s, int a){
	s.push(a);
}

bool isFull(stack<int>& s,int n){
    
	if(n==s.size())
	{
	    return true;
	}
	return false;
}

bool isEmpty(stack<int>& s){
	if(s.empty())
	    return true;
    return false;
}

int pop(stack<int>& s){
	
	int t=s.top();
	s.pop();
	return t;
}

int getMin(stack<int>& s){
	
	int mini=s.top();
	while(!s.empty())
	{
	    mini=min(mini,s.top());
	    s.pop();
	}
	return mini;
}