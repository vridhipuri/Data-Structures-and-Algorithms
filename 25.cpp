//Find if there is any subarray with sum equal to 0
//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int,int>m;
        int sum=0;
        int curr_sum=0;
        int start=0;
        int end=-1;
        for(int i=0;i<n;i++)
        {
            curr_sum=curr_sum+arr[i];
            if(curr_sum-sum==0)
            {
                start=0;
                end=i;
                break;
            }
            if(m.find(curr_sum-sum)!=m.end())
            {
                start=m[curr_sum-sum]+1;
                end=i;
                break;
            }
            m[curr_sum]=i;
        }
        if(end==-1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends