//Detect cycle in an undirected graph using bfs (see copy)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool bfsCycle(int node,unordered_map<int,bool> &visited,vector<int> adj[] )
  {
      visited[node]=true;
      unordered_map<int,int>parent;
      parent[node]=-1; //starting node ka parent will be -1
      queue<int>q;
      q.push(node);
      while(!q.empty())
      {
          int first=q.front();
          q.pop();
          for(auto neighbour:adj[first])
          {
              if(visited[neighbour]==true && neighbour!=parent[first])
              {
                  return true;
              }
              else if(visited[neighbour]==false)
              {
                  q.push(neighbour);
                  visited[neighbour]=true;
                  parent[neighbour]=first;
              }
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        unordered_map<int,bool> visited;
        
        //to handle disconnected graph
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
              bool ans= bfsCycle(i,visited,adj);
              if(ans==true)
              {
                  return true;
              }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends