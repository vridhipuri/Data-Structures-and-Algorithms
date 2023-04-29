//Product array Puzzle
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
          vector<long long int>p;
          
          long long int x=1;
          for(int i=0;i<n;i++)
          {
              x=x*nums[i];  //find product of array which will be our left like approach 2 in copy
              p.push_back(x); 
          }
          
          long long int prod=1;
    
          for(int i=n-1;i>0;i--) 
          {
            p[i]=p[i-1]*prod; //make right array by modifying the left one made above
            prod=prod*nums[i];
          }
          
          p[0]=prod; //didnt consider 0th element in loop coz i=0 ke baad cant do i--
          return p;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends