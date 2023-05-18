//minimum no. of swaps required to sort the array
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int>temp=nums;
	    unordered_map<int,int>m;
	    int count=0;
	    
	    sort(temp.begin(),temp.end());
	    
	    for(int i=0;i<nums.size();i++)
	    {
	        m[nums[i]]=i;
	    }
	    
	    for(int i=0;i<nums.size();i++)
	    {
	        if(temp[i]!=nums[i])
	        {
	            count++;
	            int x=nums[i];
	            //to swap elemnts in array
	            int j=m[temp[i]];
	            int t=nums[i];
	            nums[i]=nums[j];
	            nums[j]=t;
	            //to swap indexes in map
	            
	            m[x]=m[temp[i]];
	            m[temp[i]]=i;
	        }  
	            
	    }
	    return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends