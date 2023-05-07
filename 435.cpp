//Maximum subsequence sum such that no three are consecutive (see copy)
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  
  int memoization(vector<int> &a, int i, vector<int> &dp)
  {
      if(i<=-1)
      {
          return 0;
      }
      if(i==0)
      {
          return a[0];
      }
      if(i==1)
      {
          return a[0]+a[1];
      }
      if(dp[i]!=-1)
      {
          return dp[i];
      }
         // including current element and the next consecutive element in subsequence
         int x = a[i] + a[i - 1] + memoization(a, i - 3, dp);
     
        // not including the current element in subsequence
        int b = memoization(a, i - 1, dp);
     
        // including current element but skipping next consecutive element
        int c = a[i] + memoization(a, i - 2, dp);
     
        // returning the max of above 3 cases
        return dp[i] = max(x, max(b, c));
  }
  int findMaxSum(vector<int>& a){
      //Code Here
      int n=a.size();
      vector<int>dp(n,-1);
      return memoization(a,n-1,dp);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
