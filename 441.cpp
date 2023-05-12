//Maximum difference of zeros and ones in binary string (see copy)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int count=0; //return count if string has all ones
	    int sum=0;
	    int val;
	    int ans=0;
	    for(int i=0;i<S.length();i++)
	    {
	        if(S[i]=='0')
	        {
	            val=1;
	        }
	        else if(S[i]=='1'){
	            val=-1;
	            count++;
	        }
	        sum=max(val,val+sum);
	        ans=max(ans,sum);
	    }
	    if(count==S.length()) //when string has all ones
	    {
	        return -1;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends
