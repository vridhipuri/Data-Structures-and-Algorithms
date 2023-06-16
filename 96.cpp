//Check if two given strings are isomorphic to each other (see copy)
//Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        vector<int>m1(256,0);
        vector<int>m2(256,0);
        int m=str1.length();
        int n=str2.length();
        
        if(m!=n)
        {
            return false;
        }
        for(int i=0;i<m;i++)
        {
            if(!m1[str1[i]] && !m2[str2[i]])
            {
                m1[str1[i]]=str2[i];
                m2[str2[i]]=str1[i];
            }
            else{
                if(m1[str1[i]]!=str2[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends