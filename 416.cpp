//Binomial CoefficientProblem (see copy)
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long mod=10000007;
    /*int recursion(int n,int r)
    {
        if(r==n || r==0)
        {
            return 1;
        }
        int ans=0;
        ans = ((recursion(n-1,r-1)%mod)+(recursion(n-1,r)%mod))%mod;
        return ans;
    }*/
    int tabulation(int n,int r)
    {
        if(n<r){
            return 0;
        }
        if((n-r) < r){
            r=n-r;
        }
        
        vector<int>dp(r+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            
            for(int j=min(r,i);j>0;j--){
                dp[j]=(dp[j]+dp[j-1])%1000000007;
            }
            
        }
        
        return dp[r];
    }
    int nCr(int n, int r){
        // code here
        //return recursion(n,r);
        return tabulation(n,r);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends