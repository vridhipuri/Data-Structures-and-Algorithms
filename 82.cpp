//Number of flips to make binary string alternate (see copy)
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    
    //if even index has 0, increment flip
    //if odd index has 1, increment flip
    
    int flips=0;
    
    for(int i=0;i<S.length();i++)
    {
        if(i%2==0 && S[i]=='0')
        {
            flips++;
        }
        else if(i%2!=0 && S[i]=='1')
        {
            flips++;
        }
        
    }
    int toFindMin=S.length()-flips;
    return min(flips,toFindMin);
}