//Minimum sum of squares of character counts in a given string after removing “k” characters. (game w string)
//see copy 
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        
        unordered_map<int,int>m;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            m[ch]++;
        }
        priority_queue<int>pq;
        for(auto it:m)
        {
            pq.push(it.second);
        }
        while(k!=0)
        {
            int x=pq.top();
            pq.pop();
            x--;
            pq.push(x);
            k--;
        }
        int sum=0;
        while(!pq.empty())
        {
            int y=pq.top();
            sum=sum+(y*y);
            pq.pop();
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
