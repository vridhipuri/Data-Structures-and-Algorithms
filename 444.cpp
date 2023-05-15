//Minimum removals from array to make max –min <= K (see copy)
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int dp[1000][1000];
int fun(int i,int j,vector<int> &arr,int k)
{
	if(i>=j) return 0;
	if(arr[j]-arr[i]<=k) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	return dp[i][j]= min(fun(i+1,j,arr,k),fun(i,j-1,arr,k))+1;
}
    int removals(vector<int>& arr, int k){
        //Code here
        memset(dp,-1,sizeof(dp));
	sort(arr.begin(),arr.end());
	int n=arr.size();
	return fun(0,n-1,arr,k);
    }
    
              
    
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends