//Second most repeated string in a sequence (see copy)
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
                //string, frequency
        unordered_map<string,int>m;
        
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++; //inserting string w its frequency in map
        }
        
        //make min heap
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
                        //frequency,string
        
        //push elements in min heap from map in the form of pair
        for(auto i:m)
        {
            pq.push(make_pair(i.second,i.first));
                          //frequency    string
            if(pq.size()>2)
            {
                pq.pop();
            }
        }
        if(pq.size()>1)
        {
            return pq.top().second;
        }
        return "";
    
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends