//String matching where one string contains wildcard characters (see copy)
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    
    bool helper(int i,int j,string& wild,string& pattern,vector<vector<int>>& dp){
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0){
            for(int ii=0;ii<=j;ii++){
                if(wild[ii]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(pattern[i]==wild[j] || wild[j] == '?') return dp[i][j] = helper(i-1,j-1,wild,pattern,dp);
        if(wild[j]=='*') return dp[i][j]= (helper(i-1,j,wild,pattern,dp) | helper(i,j-1,wild,pattern,dp));
        
        return dp[i][j]=false;
    }
    
    bool match(string wild, string pattern)
    {
        int n= pattern.size();
        int m= wild.size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return helper(n-1,m-1,wild,pattern,dp);
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends