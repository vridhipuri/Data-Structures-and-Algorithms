//Write a program tofind the smallest window that contains all characters of string itself. (see copy)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int>m;
        unordered_set<char>s;
        for(int i=0;i<str.length();i++)
        {
            s.insert(str[i]);
        }
        int totalDistinct=s.size();
        int i=0;
        int j=1;
        m[str[i]]++; //pehle element ki frequency 1 krdo in map
        int countOfDistinct=0;
        countOfDistinct++;
        int ans=str.length(); //max window size can be equal to length of string eg "abc"
        while(i<=j && j<str.length())
        {
            if(countOfDistinct<totalDistinct)
            {
                if(m[str[j]]==0)
                {
                    countOfDistinct++;
                }
                m[str[j]]++;
                j++;
            }
            else if(countOfDistinct==totalDistinct)
            {
                ans=min(ans,j-i);
                if(m[str[i]]==1)
                {
                    countOfDistinct--;
                }
                m[str[i]]--;
                i++;
            }
        }
        while(countOfDistinct==totalDistinct)
        {
            ans=min(ans,j-i);
            if(m[str[i]]==1)
            {
                countOfDistinct--;
            }
            m[str[i]]--;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends