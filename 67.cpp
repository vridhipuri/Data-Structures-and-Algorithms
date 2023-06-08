

//MY SOLUTION
/*
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    int memoization(vector<int> &nums, int rem, int i, int k)
    {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        int cost;
        //base case- if you reach last word, uski cost is 0 (given)
        if(i==n)
        {
            return 0;
        }
        if(dp[i][rem]!=-1)
        {
            return dp[i][rem];
        }
        if(nums[i]>rem)
        {
            cost=(rem+1)*(rem+1)+memoization(nums,k-nums[i]-1,i+1,k);
        }
        else{
            //put word in next line
            int choice1=(rem+1)*(rem+1)+memoization(nums,k-nums[i]-1,i+1,k);
            //put word in same line
            int choice2=memoization(nums,k-nums[i]-1,i+1,k);
            cost=min(choice1,choice2);
        }
        dp[i][rem]=cost;
        return dp[i][rem];
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        //initially rem=k and we start with index=0 of array
        return memoization(nums,k,0,k);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends

*/

//CORRECT ONE,IDK WHAT WAS THE MISTAKE IN MINE, MINE GAVE OUTPUT WRONG, REFER MINE FOR EXPLANATION

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    int dp[505][2005];
int rec(int i, int rem, vector<int>& nums, int& k)
{
    if(i==nums.size())
    {
        return 0;
    }
    if(dp[i][rem]!=-1)
    {
        return dp[i][rem];
    }
    int ans;
    if(nums[i]>rem)
    {
        ans=(rem+1)*(rem+1)+rec(i+1, k-nums[i]-1,nums, k );
    }
    else
    {
        int choice1= rec(i+1, rem-nums[i]-1, nums, k);
        int choice2=(rem+1)*(rem+1)+ rec(i+1, k-nums[i]-1, nums, k);
        ans= min(choice1, choice2);
    }
    return dp[i][rem]=ans;
}
    int solveWordWrap(vector<int>nums, int k) 
    { 
        memset(dp,-1,sizeof(dp));
        return rec(0,k, nums, k);
        
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends