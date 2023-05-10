//Maximum sum of pairs with specific difference (see copy)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here   
        sort(arr,arr+N);
        int i=N-1;
        int j=N-2;
        int ans=0;
        while(j>=0)
        {
            if(arr[i]-arr[j]<K)
            {
                ans=ans+(arr[i]+arr[j]);
                i=i-2;
                j=j-2;
            }
            else{
                i--;
                j--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends