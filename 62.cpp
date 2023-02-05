//Write a program to find the longest Palindrome in a string.[ Longest palindromic Substring] (dry run)
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        
        int len=0;
        int start=0;
        int n=S.length();
        int maxlen=INT_MIN;
        
        //even length
        for(int i=0;i<n-1;i++)
        {
            int l=i;
            int r=i+1;
            while(S[l]==S[r] && l>=0 && r<n)
            {  
                //to maximise the length
                l--;
                r++;
            }
            len=r-l-1;
            if(len>maxlen)
            {
                maxlen=len;
                start=l+1;
            }
        }
        
        //odd length
        for(int i=0;i<n-1;i++)
        {
            int l=i;
            int r=i;
            while(S[l]==S[r] && l>=0 && r<n)
            {
                //to maximise the length
                l--;
                r++;
            }
            len=r-l-1;
            if(len>maxlen)
            {
                maxlen=len;
                start=l+1;
            }
        }
        return S.substr(start,maxlen);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends