//Given a sorted Dictionary of an Alien Language, find order of characters (see copy)
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    public:
    
    void dfs(int node, vector<int> adj[],unordered_map<int,bool> &visited,stack<int> &s)
    {
        visited[node]=true;
        for(auto nbrs:adj[node])
        {
            if(!visited[nbrs])
            {
                dfs(nbrs,adj,visited,s);
            }
            
        }
        s.push(node);
    }
    string findOrder(string dict[], int N, int K) {
        
        vector<int>adj[K]; //K size ki adj list as K nodes will be there
        //traverse dict
        //we need to get pairs so iterate till 2nd last string ie N-1
        for(int i=0;i<N-1;i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            
            //make graph by comparing strings
            //we will compare till length of smaller string
            int len=min(s1.size(),s2.size());
            for(int j=0;j<len;j++)
            {
                if(s1[j]!=s2[j]) 
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    //-a as we will store nodes as 0,1,2
                    break;
                }
            }
        }
        vector<int>topo(K);
        stack<int>s;
        unordered_map<int,bool>visited;
        for(int i=0;i<K;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,s);
            }
        }
        //we got topo sort in stack
        //we need to put the sort in a string in the form of chars
        //so again convert from ascii value to chars by using +'a'
        string ans="";
        while(!s.empty())
        {
            int top=s.top();
            s.pop();
            ans=ans+char(top+'a');
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends