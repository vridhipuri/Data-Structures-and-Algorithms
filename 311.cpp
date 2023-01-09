//Largest rectangular Area in Histogram (see copy)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long>ps;
        stack<long long>s;
        
        ps.push_back(-1);
        s.push(0); 
        for(int i=1;i<n;i++)
        {
            while(!s.empty() && arr[i]<=arr[s.top()])
            {
                s.pop();
            }
            if(s.empty())
                ps.push_back(-1);
            else
                ps.push_back(s.top());
            s.push(i);
        }
        
        vector<long long>ns;
        stack<long long>st;
        
        ns.push_back(n);
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && arr[i]<=arr[st.top()])
            {
                st.pop();
            }
            if(st.empty())
                ns.push_back(n);
            else
                ns.push_back(st.top());
            st.push(i);
        }
        reverse(ns.begin(),ns.end());
        long long res=0;
        long long area=arr[0];
        for(int i=0;i<n;i++)
        {
            long long height=arr[i];
            area=(ns[i]-ps[i]-1)*height;
            res=max(res,area);
            
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
