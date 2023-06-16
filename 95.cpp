//Transform One String to Another using Minimum Number of Given Operation (see vid)
//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.

        //to get freq of chars
        vector<int>a(256,0);
        vector<int>b(256,0);
        
        //mismatch possible if length is diff
        if(A.length()!=B.length())
        {
            return -1;
        }
        
        for(int i=0;i<A.length();i++)
        {
            a[A[i]]++;
        }
        for(int j=0;j<B.length();j++)
        {
            b[B[j]]++;
        }
        
        //check for freq of chars
        for(int i=0;i<256;i++)
        {
            if(a[i]!=b[i]) //if freq at a char is not same,then mismatch
            {
                return -1;
            }
            
        }
         //to check for match
         int count=0; //to get to know how many mismatches or kitne chars se move krna hai
         int i=A.length();
         int j=B.length();
         while(i>=0 && j>=0)
         {
             while(i>=0 && A[i]!=B[j])
             {
                 //if mimatch then move i to check A[i] with B[j]
                 i--;
                 count++;
             }
             //if match
             i--;
             j--;
         }
         return count;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends
