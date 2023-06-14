//Find the smallest window in a string containing all characters of another string (see vid)
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int>m(256,0);
        
        for(int i=0;i<p.length();i++) //vector has chars of p
        {
            m[p[i]]++; //ascii char string conversion done automatically
        }
        
        if(s.length()==0 || p.length()==0 || s.length()<p.length())
        {
            return "-1";
        }
        int start=0;
        int end=0;
        int count=0; //to check if we have reached p's length
        int ansLen=INT_MAX;
        int ans_start=0;
        
        while(end<s.length())
        {
            if(m[s[end]]>0) //if map has char of s
            {
                count++;
            }
            m[s[end]]--; //agar freq remains same then it'll affect aage ke chars and decreasingfreq means we are using the char
            while(count==p.length()) //window condn
            {
                if(ansLen>end-start+1)
                {
                    ansLen=end-start+1;
                    ans_start=start;
                }
                //ab jab koi window mil gyi toh restore kro frequency
                m[s[start]]++; 
                //when freq becomes greater than 0, it means we havent used that char and the count will reduce.
                //it means if we shift the window is the window condn still being satisfied in the shifted window
                //as new window mein we need the chars so unki freq increase honi chahiye
                if(m[s[start]]>0)
                {
                    count--;
                }
                start++;
            }
            end++;
        }
        
        if(ansLen==INT_MAX)
        {
            return "-1";
        }
        else
        {
            return s.substr(ans_start,ansLen);
        }
        
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends