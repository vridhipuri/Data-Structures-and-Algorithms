//Check the expression has valid or Balanced parenthesis or not. (see copy)
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>s;
        for(int i=0;i<x.length();i++)
        {
            char ch=x[i];
            if(ch=='(' || ch=='[' || ch=='{')
            {
                s.push(ch);
            }
            else{
                if(s.empty()) //expression ka pehle char is closing bracket so vo stack mein nhi gya so stack remains empty 
                    return false;
                else{
                    char top=s.top(); //opening bracket
                    if((top=='(' && ch==')') ||
                    (top=='[' && ch==']')||
                    (top=='{' && ch=='}'))
                    {
                        s.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(s.empty())
            return true;
        else
            return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
