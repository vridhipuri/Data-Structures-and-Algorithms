//Remove Consecutive Characters
//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        stack<char>st;
        for(int i=0;i<S.length();i++)
        {
            if((!st.empty() && st.top()!=S[i]) || st.empty() )
            {
                st.push(S[i]);
            }
        }
        string res="";
        while(!st.empty())
        {
            res=res+st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends