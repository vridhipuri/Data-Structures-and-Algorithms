//Subset Sum Problem (see copy)
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool recursion(int N,int arr[],int target,int i)
    {
        if(i>=N)
            return 0;
        if(target<0)
            return 0;
        if(target==0)
            return 1;
        bool include=recursion(N,arr,target-arr[i],i+1);
        bool exclude=recursion(N,arr,target-0,i+1);
        return (include||exclude);
    }
    bool memoization(int N,int arr[],int target,int i,vector<vector<int>> &dp)
    {
        if(i>=N)
            return 0;
        if(target<0)
            return 0;
        if(target==0)
            return 1;
        if(dp[target][i]!=-1)
            return dp[target][i];
        bool include=memoization(N,arr,target-arr[i],i+1,dp);
        bool exclude=memoization(N,arr,target-0,i+1,dp);
        dp[target][i] = (include||exclude);
        return dp[target][i];
    }
    int equalPartition(int N, int arr[])
    {
        //code here
        int target=0;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum=sum+arr[i];
        }
        if(sum%2!=0)
            return 0;
        target=sum/2;
        //return recursion(N,arr,target,0);
        vector<vector<int>>dp(target+1,vector<int>(N,-1));
        return memoization(N,arr,target,0,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends