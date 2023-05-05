//Maximum Sum Increasing Subsequence (do dry run)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int dp[n];
	    for(int i=0;i<n;i++)
	    {
	        dp[i]=arr[i];
	    }
	    //make sum array dp
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<i;j++) //j<i taaki j end tak na pahunch jaaye baar baar as longest increasing
	        {
	            if(arr[j]<arr[i])
	            {
	                dp[i]=max(dp[i],arr[i]+dp[j]);
	            }
	        }
	    }
	    //find max sum
	    int maxi=dp[0];
	    for(int i=0;i<n;i++)
	    {
	        maxi=max(maxi,dp[i]);
	    }
	    return maxi;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends