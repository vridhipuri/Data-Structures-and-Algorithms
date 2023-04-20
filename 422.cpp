//Friends Pairing Problem (see copy)
//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int mod=1000000007;
    /*int recursion(int n)
    {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int ans;
        ans=recursion(n-1)+(n-1)*recursion(n-2);
        return ans%mod;
        
    }*/
    /*long long memoization(int n,vector<long long> &dp)
    {
        if(dp[n]!=-1){
            return dp[n];
        }
        if (n > 2)
            return dp[n] = (memoization(n - 1, dp)%mod + ((n - 1) * memoization(n - 2, dp))%mod)%mod;
        else
            return dp[n] = n;
        
    }*/
    long long tabulation(int n)
    {
        vector<long long>dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        dp[0]=0;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+(i-1)*dp[i-2];
        }
        return dp[n]%mod;
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        //return recursion(n);
        /*vector<long long>dp(n+1,-1);
        return memoization(n,dp);*/
        return tabulation(n);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends