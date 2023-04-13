//Count Derangements (Permutation such that no element appears in its original position) [ IMPORTANT ] (see copy)

//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //TABULATION
    /*long int disarrange(int N){
        long int mod=1000000007;
        vector<int>dp(N+1,0);
        dp[1]=0;
        dp[2]=1;
        for(int i=3;i<=N;i++)
        {
            long int a=dp[i-1]%mod;
            long int b=dp[i-2]%mod;
            long int sum=(a+b)%mod;
            long int ans=((i-1)*sum)%mod;
            dp[i]=ans;
        }
        return dp[N];
    }*/
    //SPACE OPTIMIZATION
    long int disarrange(int N){
        
        long int mod=1000000007;
    
        long int prev2=0;
        long int prev1=1;
        long int curr;
        for(int i=3;i<=N;i++)
        {
            long int a=prev1%mod;
            long int b=prev2%mod;
            long int sum=(a+b)%mod;
            long int ans=((i-1)*sum)%mod;
            curr=ans;
            prev2=prev1;
            prev1=curr;
            
        }
        return prev1;
    }
    
    
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends