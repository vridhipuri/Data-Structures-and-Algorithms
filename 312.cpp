//Length of the Longest Valid Substring (see copy)
//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        
        stack<int>st;
        int len=s.length();
        //making stack for hurdles
        for(int i=0;i<len;i++)
        {
            char ch=s[i];
            if(ch=='(')
                st.push(i); //push index of opening bracket
            else{
                if(!st.empty() && s[st.top()]=='(')
                    st.pop();
                else
                    st.push(i); //index of hurdle
            }
        }
        int maxi=0;
        int l=len;
        while(!st.empty())
        {
            int top=st.top();
            st.pop();
            maxi=max(maxi,l-top-1);
            l=top;
        }
        return max(l,maxi);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends