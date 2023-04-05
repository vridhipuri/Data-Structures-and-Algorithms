//Course Schedule (see copy)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        unordered_map<int,vector<int>>adj;
	    for(auto it:prerequisites)
	    {
	        int u=it[1]; 
	        int v=it[0];
	        //directed graph
	        adj[u].push_back(v);
	    }
	    //implement kahn's algo (topo sort using bfs)
	     //make indegree array
	     vector<int>indegree(n);
	     for(int i=0;i<n;i++)
	     {
	         for(auto it:adj[i])
	         {
	             indegree[it]++;
	         }
	     }
	     queue<int>q;
	     vector<int>ans;
	     for(int i=0;i<n;i++)
	     {
	         if(indegree[i]==0)
	         {
	             q.push(i);
	         }
	     }
	     while(!q.empty())
	     {
	         int front=q.front();
	         ans.push_back(front);
	         q.pop();
	         for(auto nbr:adj[front])
	         {
	             indegree[nbr]--;
	             if(indegree[nbr]==0)
	             {
	                 q.push(nbr);
	             }
	         }
	         
	     }
	     if(ans.size()==n) //saare nodes present in topo sort
	        return ans;
	   return {};

    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends