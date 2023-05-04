//LCS of three strings
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int lcs(string A, string B, string C, int i, int j, int k,vector<vector<vector<int>>>&dp){
    if(i==A.size() || j==B.size() || k==C.size()){
        return 0;
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    int b1=0;
    int b2=0;int b3=0;int b4=0;int b5=0;int b6=0;int b7=0;int b8=0;
    int a=0;
    int mx = 0;
    
    if(A[i]==B[j] && A[i]==C[k]){
        a = 1 + lcs(A,B,C,i+1,j+1,k+1,dp);
    }
    else{
        b1 = lcs(A,B,C,i+1,j,k,dp);
        b2 = lcs(A,B,C,i,j+1,k,dp);
        b3 = lcs(A,B,C,i,j,k+1,dp);
        b4 = lcs(A,B,C,i+1,j+1,k,dp);
        b5 = lcs(A,B,C,i+1,j,k+1,dp);
        b6 = lcs(A,B,C,i,j+1,k+1,dp);
        b7 = lcs(A,B,C,i+1,j+1,k,dp);
        b8 = lcs(A,B,C,i+1,j+1,k+1,dp);
        
        mx = max(mx,b1);
        mx = max(mx,b2);
        mx = max(mx,b3);
        mx = max(mx,b4);
        mx = max(mx,b5);
        mx = max(mx,b6);
        mx = max(mx,b7);
        mx = max(mx,b8);
    }
    
    return dp[i][j][k] = max(mx,a);
    
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
   vector<vector<vector<int>>> dp(n1,vector<vector<int>> (n2,vector<int> (n3,-1)));
   return lcs(A,B,C,0,0,0,dp);
}