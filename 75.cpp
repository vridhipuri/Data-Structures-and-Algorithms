//Minimum number of bracket reversals needed to make an expression balanced. (see copy)
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    
    stack<char>st;
    //check odd case
    if(s.length()%2!=0)
    {
        return -1;
    }
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        if(ch=='{')
        {
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top()=='{')
            {
                st.pop(); //remove valid expression
            }
            else{ 
                st.push(ch); //push closing brace
            }
        }
    }
    
    //now expression only has invalid expression
    
    //now count the no.of open and close braces
    int open=0;
    int close=0;
    int reversalCount;
    while(!st.empty())
    {
        if(st.top()=='{')
        {
            open++;
        }
        else{
            close++;
        }
        st.pop();
    }
    reversalCount=(open+1)/2+(close+1)/2;
    return reversalCount;
}