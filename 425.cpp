//Painting the Fenceproblem (see copy)
//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long mod=1000000007;
    
    int add(int a,int b)
    {
        return ((a%mod)+(b%mod))%mod;
    }
    int mul(int a,int b)
    {
        return ((a%mod)*(b%mod))%mod;
    }
    /*int recursion(int n,int k)
    {
        //base case
        if(n==1)
        {
            return k;
        }
        if(n==2)
        {
            return long long mod=1000000007;
    
    int add(int a,int b)
    {
        return ((a%mod)+(b%mod))%mod;
    }
    int mul(int a,int b)
    {
        return ((a%mod)*(b%mod))%mod;
    }
    int recursion(int n,int k)
    {
        //base case
        if(n==1)
        {
            return k;
        }
        if(n==2)
        {
            return add(k,mul(k,k-1));
        }
        return add(mul(recursion(n-2,k),k-1),mul(recursion(n-1,k),k-1));
    }
    long long countWays(int n, int k){
       return recursion(n,k);
    }
        }
        return add(mul(recursion(n-2,k),k-1),mul(recursion(n-1,k),k-1));
    }*/
    /*int memoization(int n,int k, vector<int> &dp)
    {
        if(n==1)
        {
            return k;
        }
        if(n==2)
        {
            return add(k,mul(k,k-1));
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans=add(mul(memoization(n-2,k,dp),k-1),mul(memoization(n-1,k,dp),k-1));
        dp[n]=ans;
        return dp[n];
    }*/
    /*int tabulation(int n,int k)
    {
        vector<int>dp(n+1,0);
        dp[1]=k;
        dp[2]=add(k,mul(k,k-1));
        
        for(int i=3;i<=n;i++)
        {
            dp[i]=add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
        }
        return dp[n];
        
    }*/
    int spaceOpti(int n,int k)
    {
        int curr;
        int prev2=k;
        int prev1=add(k,mul(k,k-1));
        for(int i=3;i<=n;i++)
        {
            curr=add(mul(prev2,k-1),mul(prev1,k-1));
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    long long countWays(int n, int k){
       //return recursion(n,k);
       //vector<int>dp(n+1,-1);
       //return memoization(n,k,dp);
       //return tabulation(n,k);
       return spaceOpti(n,k);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends