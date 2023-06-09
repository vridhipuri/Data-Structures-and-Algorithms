//Word Break (see my code for explanation and see copy)
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

    unordered_map<string,int>dp;
    int memoization(string A,vector<string> &B)
    {
        int found=0;
        
        int n=A.length();
        //if entire string is found in array, then jo string size humein recursion mein bhejna hoga vo 0 hoga
        if(n==0)
        {
            return 1;
        }
        //map mein by default 0 hota hai so writing 0 instead of -1 and agar final ans false hua toh returning -1
        if(dp[A]!=0)
        {
            return dp[A];
        }
        
        //break string into smaller strings
        for(int i=1;i<=n;i++)
        {
            string ss=A.substr(0,i);
            //check is ss is found in array
            for(int j=0;j<B.size();j++)
            {
                if(ss.compare(B[j])==0)
                {
                    found=1; //ek substring found
                    break; //toh break krke ab baaki ka substring bhejo and check kro
                }
            }
            if(found==1 && memoization(A.substr(i,n-i),B)==1)
            {
                return dp[A]=1;
            }
        }
        return dp[A]=-1; //not possible
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        int x=memoization(A,B);
        if(x==1)
        {
          return 1;  
        }
        else 
        {
            return 0;
        }
    }
    /*unordered_map<string,int> dp;
int solve(string s, vector<string> &dic)
{
    int i,j;
    int n = s.size();
    if(n==0) return 1;
    if(dp[s]!=0) return dp[s];
    for(i=1;i<=n;i++)
    {
        int flag =0;
        string ss = s.substr(0,i);
        for(j=0;j<dic.size();j++)
        {
           if(ss.compare(dic[j])==0)
           {
               flag =1;
               break;
           }
        }
    
    if(flag==1 && solve(s.substr(i,n-i),dic)==1)
    return dp[s] =1;
    }
  
    return dp[s]= -1;
}
int wordBreak(string s, vector<string> &dic) 
{ 
    int x = solve(s,dic);
    if(x==1)
    return 1;
    else
    return 0;
}*/
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends