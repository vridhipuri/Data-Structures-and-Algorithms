//Min Cost PathProblem

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        // start from second row
        for (int i=1;i<N;i++) 
        {
            for (int j=0;j<N;j++) 
           {
                // any path can be taken
              if (j>0 && j<N - 1)
                 Matrix[i][j]+=max({Matrix[i - 1][j],Matrix[i-1][j-1],Matrix[i-1][j+1]});
              
               //downright path is not possible
              else if (j>0)
                 Matrix[i][j]+=max(Matrix[i-1][j],Matrix[i-1][j-1]);
 
               //downleft path is not possible
              else if (j<N-1)
                 Matrix[i][j]+=max(Matrix[i-1][j],Matrix[i-1][j+1]);

        }
    }
    
    // answer will be maximum of all values in the last row 
    int ans = 0;
    for (int j=0;j<N;j++)
        ans = max(Matrix[N-1][j],ans);
        
    return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends