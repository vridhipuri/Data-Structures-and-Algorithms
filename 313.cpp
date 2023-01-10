//Expression contains redundant bracket or not (see copy and do dry run)
//https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;
bool findRedundantBrackets(string &s)
{
    stack<int>st;
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/')
        {
            st.push(ch);
        }
        else{            //closing bracket or alphabet
            if(ch==')')
            {
                bool isRedundant=true;
                while(st.top()!='(')
                {
                    char top=st.top();
                    if(top=='+' || top=='-' || top=='*' || top=='/')
                    {
                        isRedundant=false;
                    }
                    st.pop();
                }
                if(isRedundant==true)
                    return true;
                st.pop();   
            }
        }
    }
    return false;
}
int main()
{
    string s="((a+b))";
    cout<<findRedundantBrackets(s);
    return 0;
}