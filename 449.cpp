//Smallest sum contiguous subarray (do dry run)
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      
       int sum=INT_MAX;
       int mini=INT_MAX;
       
       for(int i=0;i<a.size();i++)
       {
           if(sum>0)
            sum=a[i];
          
           else{
               sum=sum+a[i];
           }
           mini=min(sum,mini);
       }
       return mini;
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends