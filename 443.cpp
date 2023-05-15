//Minimum cost to fill given weight in a bag (see copy)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int memoization(int cost[],int i,int W,vector<vector<int>> &dp)
	{
	    if(W==0 && i==-1)
	    {
	        return 0;
	    }
	    if(i==-1)
	    {
	        return 1e9; 
	    }
	    if(W==0)
	    {
	        return 0;
	    }
	    if(dp[i][W]!=-1)
	    {
	        return dp[i][W];
	    }
	    if((i+1)>W || cost[i]==-1)
	    {
	        return dp[i][W]=memoization(cost,i-1,W,dp);
	    }
	    int take=cost[i]+memoization(cost,i,W-(i+1),dp); //i-1 nhi as i phirse consider hoga w some other element in recursionn
	    int not_take=memoization(cost,i-1,W,dp);
	    return dp[i][W]=min(take,not_take);
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
        int ans=memoization(cost,N-1,W,dp);
        if(ans>=1e9)
        {
            return -1;
        }
        return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends