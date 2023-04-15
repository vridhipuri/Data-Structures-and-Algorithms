//Longest Common Subsequence (see copy)
//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    /*int recursion(int i,int j,string s1, string s2)
    {
        if(i==s1.length())
        {
            return 0;
        }
        if(j==s2.length())
        {
            return 0;
        }
        int ans=0;
        if(s1[i]==s2[j])
        {
            ans= 1+recursion(i+1,j+1,s1,s2);
        }
        else{
            ans= max(recursion(i,j+1,s1,s2),recursion(i+1,j,s1,s2));
        }
        return ans;
    }*/
    /*int memoization(int i,int j,string s1,string s2,vector<vector<int>> &dp)
    {
        if(i==s1.length())
        {
            return 0;
        }
        if(j==s2.length())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j])
        {
            ans= 1+memoization(i+1,j+1,s1,s2,dp);
        }
        else{
            ans= max(memoization(i,j+1,s1,s2,dp),memoization(i+1,j,s1,s2,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }*/
    int tabulation(string s1,string s2)
    {
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
        for(int i=s1.length()-1;i>=0;i--)
        {
            for(int j=s2.length()-1;j>=0;j--)
            {
                if(s1[i]==s2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        //return recursion(0,0,s1,s2);
        /*vector<vector<int>>dp(s1.length(),vector<int>(s2.length(),-1));
        return memoization(0,0,s1,s2,dp);*/
        return tabulation(s1,s2);
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends