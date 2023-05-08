//Egg Dropping Problem
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    int t[201][201];
    
    int helper(int eggs, int floors){

        if(floors == 0 || floors == 1) return floors;
        

        if(eggs == 1) return floors;
        

        if(t[eggs][floors] != -1) return t[eggs][floors];
        
        int ans = INT_MAX; 
         
        for(int k=1;k<=floors;k++){
            int temp = 1 + max(helper(eggs-1, k-1), helper(eggs, floors-k));
            
            ans = min(ans, temp);
        }
        return t[eggs][floors] = ans;
    }
    
    
    
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
      memset(t, -1, sizeof(t));
        return helper(n, k);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends