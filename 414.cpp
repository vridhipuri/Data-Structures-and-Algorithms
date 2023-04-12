//Coin Change (see copy)
// Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>>dp(N,vector<long long int>(sum+1,0));
        for(int i=0;i<=sum;i++)
        {
            dp[0][i]=(i%coins[0]==0);
        }
        for(int i=1;i<N;i++)
        {
            for(int t=0;t<=sum;t++)
            {
                long long int notTake=dp[i-1][t];
                long long int take=0;
                if(coins[i]<=t)
                {
                    take=dp[i][t-coins[i]];
                }
                dp[i][t]=take+notTake;
            }
        }
        return dp[N-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends