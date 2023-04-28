//Count triplet with sum smaller than a given value
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    int start;
	    int end;
	    int i;
	    int count=0;
	    for(i=0;i<n-2;i++)
	    {
	        start=i+1;
	        end=n-1;
	        while(start<end)
	        {
	            if(arr[i]+arr[start]+arr[end]<sum)
	            {
	                count=count+end-start;
	                start++;
	            }
	            else
	            {
	                end--;
	            }
	        }
	    }
	    return count;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends