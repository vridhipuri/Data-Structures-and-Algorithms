//Find row with maximum no. of 1's
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int max_row=-1;
	    int r=0;
	    int c=m-1;
	    while(c>=0 && r<n)
	    {
	        if(arr[r][c]==1)
	        {
	            max_row=r;
	            c--;
	        }
	        else{
	            r++;
	        }
	    }
	    if(max_row>-1)
	    {
	        return max_row;
	    }
	    return -1;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends