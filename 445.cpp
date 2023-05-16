//Longest Common Substring (see copy)
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int maxi=INT_MIN;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(S1[i-1]!=S2[j-1])
                {
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                maxi=max(dp[i][j],maxi);
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends