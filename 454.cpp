//Longest Palindromic Subsequence (see copy)
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    /*int lcs(int i,int j,string a,string b)
    {
        if(i==a.length())
            return 0;
        if(j==b.length())
            return 0;
        int ans=0;
        if(a[i]==b[j])
            ans=1+lcs(i+1,j+1,a,b);
        else{
            ans=max(lcs(i+1,j,a,b),lcs(i,j+1,a,b));
        }
        return ans;
    }*/
    /*int memoization(int i,int j,string a,string b,vector<vector<int>> &dp)
    {
        if(i==a.length())
            return 0;
        if(j==b.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        if(a[i]==b[j])
            ans=1+memoization(i+1,j+1,a,b,dp);
        else{
            ans=max(memoization(i+1,j,a,b,dp),memoization(i,j+1,a,b,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }*/
    int tabulation(string a,string b)
    {
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        for(int i=a.length()-1;i>=0;i--)
        {
            for(int j=b.length()-1;j>=0;j--)
            {
                if(a[i]==b[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int longestPalinSubseq(string A) {
        //code here
        string rev=A;
        reverse(A.begin(),A.end());
        //return lcs(0,0,A,rev);
        /*vector<vector<int>>dp(A.length()+1,vector<int>(rev.length()+1,-1));
        return memoization(0,0,A,rev,dp);*/
        return tabulation(A,rev);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends