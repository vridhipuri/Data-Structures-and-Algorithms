//Count All Palindromic Subsequence in a given String (see copy)
//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int mod=1e9+7;
    
    long long int memoization(int i,int j,string a,vector<vector<long long int>> &dp)
    {
        if(i==j)
            return 1;
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==a[j])
            dp[i][j]=(1+(memoization(i+1,j,a,dp))%mod+(memoization(i,j-1,a,dp))%mod)%mod;
        else{
            dp[i][j]=(((mod+memoization(i+1,j,a,dp))%mod+(memoization(i,j-1,a,dp))%mod-(memoization(i+1,j-1,a,dp))%mod))%mod;
        }
        return dp[i][j];
    }
    
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       vector<vector<long long int>>dp(str.length(),vector<long long int>(str.length(),-1));
       return (memoization(0,str.length()-1,str,dp))%mod;
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends