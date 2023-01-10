//Stack Permutations (Check if an array is stack permutation of other) (see copy)

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        int i=0,j=0;
        stack<int>s;
        while(j<N)
        {
            while(i<N && (s.empty() || s.top()!=B[j]))
            {
                s.push(A[i]);
                i++;
            }
            if(!s.empty() && B[j]==s.top())
            {
                s.pop();
                j++;
            }
            else {
                   return 0;
                 }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends