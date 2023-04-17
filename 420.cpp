//Edit Distance (see copy)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    /*int solve(string a, string b, int i, int j)
    {
        //base cases
        if(i==a.length())
            return b.length()-j;
        if(j==b.length())
            return a.length()-i;
        
        int ans=0;
        
        if(a[i]==b[j])
        {
            return solve(a,b,i+1,j+1);
        }
        
        else{
            //insert
            int insertAns=1+solve(a,b,i,j+1);
            
            //delete
            int deleteAns=1+solve(a,b,i+1,j);
            
            //replace
            int replaceAns=1+solve(a,b,i+1,j+1);
            
            ans=min(insertAns, min(deleteAns,replaceAns));
        }
        return ans;
    }*/
    /*int memoization(string a, string b, int i, int j,vector<vector<int>> &dp)
    {
        //base cases
        if(i==a.length())
            return b.length()-j;
        if(j==b.length())
            return a.length()-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        
        if(a[i]==b[j])
        {
            return memoization(a,b,i+1,j+1,dp);
        }
        
        else{
            //insert
            int insertAns=1+memoization(a,b,i,j+1,dp);
            
            //delete
            int deleteAns=1+memoization(a,b,i+1,j,dp);
            
            //replace
            int replaceAns=1+memoization(a,b,i+1,j+1,dp);
            
            ans=min(insertAns, min(deleteAns,replaceAns));
            
            dp[i][j]=ans;
        }
        return dp[i][j];
    }*/
    int tabulation(string a,string b)
    {
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        int ans=0;
        //base cases
        //i is fixed as a.length()
        for(int j=0;j<b.length();j++)
        {
            dp[a.length()][j]=b.length()-j;
        }
        //j is fixed as b.length()
        for(int i=0;i<a.length();i++)
        {
            dp[i][b.length()]=a.length()-i;
        }
        for(int i=a.length()-1;i>=0;i--)
        {
            for(int j=b.length()-1;j>=0;j--)
            {
                if(a[i]==b[j])
                    ans=dp[i+1][j+1];
                else{
                int insertAns=1+dp[i][j+1];
                int delAns=1+dp[i+1][j];
                int replaceAns=1+dp[i+1][j+1];
                ans=min(insertAns,min(delAns,replaceAns));
                }
                dp[i][j]=ans;
            }
            
        }
        return dp[0][0];
    }
    int editDistance(string s, string t) {
        
        //return solve(s,t,0,0);
        /*vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
        return memoization(s,t,0,0,dp);*/
        return tabulation(s,t);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends