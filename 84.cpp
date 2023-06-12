//Minimum Swaps for Bracket Balancing (see copy)
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        int ans=0;
        int val=0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='[')
            {
                val++;
            }
            else {
                val--;
                if(val<0)
                {
                    ans=ans-val;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends