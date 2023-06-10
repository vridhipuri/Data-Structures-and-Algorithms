//Converting Roman Numerals to Decimal (see copy)
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int>m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        
        int lastcharIndex=str.length()-1;
        int res=m[str[lastcharIndex]];
        for(int i=str.length()-2;i>=0;i--)
        {
            if(m[str[i]]<m[str[i+1]])
            {
                res=res-m[str[i]];
            }
            else{
                res=res+m[str[i]];
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends