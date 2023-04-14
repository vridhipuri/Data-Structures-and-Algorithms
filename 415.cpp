//0 - 1 Knapsack Problem (see copy)
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    /*int recursion(int W, int wt[], int val[], int index)
    {
        //base case - if only one element is left at ibdex=0
        if(index==0)
        {
            if(wt[0]<=W)
            {
                return val[0]; //include it
            }
            else{
                return 0;
            }
        }
        int include=0;
        if(wt[index]<=W)
        {
            include=val[index]+recursion(W-wt[index],wt,val,index-1);
        }
        int exclude=0+recursion(W,wt,val,index-1);
        int ans=max(include,exclude);
        return ans;
    }*/
    /*int memoization(int W, int wt[], int val[], int index,vector<vector<int>> &dp)
    {
        //base case - if only one element is left at index=0
        if(index==0)
        {
            if(wt[0]<=W)
            {
                return val[0]; //include it
            }
            else{
                return 0;
            }
        }
        if(dp[index][W]!=-1)
        {
            return dp[index][W];
        }
        int include=0;
        if(wt[index]<=W)
        {
            include=val[index]+memoization(W-wt[index],wt,val,index-1,dp);
        }
        int exclude=0+memoization(W,wt,val,index-1,dp);
        dp[index][W]=max(include,exclude);
        return dp[index][W];
    }*/
    int tabulation(int W,int wt[],int val[],int n)
    {
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        //base case->handling 0th row
        for(int w=wt[0];w<=W;w++)
        {
            if(wt[0]<=W)
            {
                dp[0][w]=val[0];
            }
            else{
                dp[0][w]=0;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int w=0;w<=W;w++)
            {
                int include=0;
                if(wt[i]<=w)
                {
                    include=val[i]+dp[i-1][w-wt[i]];
                }
                int exclude=0+dp[i-1][w];
                dp[i][w]=max(include,exclude);
            }
        }
        return dp[n-1][W];
        
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       //return recursion(W,wt,val,n-1);
       /*vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return memoization(W,wt,val,n-1,dp);*/
       return tabulation(W,wt,val,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends