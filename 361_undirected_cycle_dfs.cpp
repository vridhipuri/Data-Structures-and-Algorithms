//Cycle Detection In Undirected Graph using dfs (see copy)
#include<unordered_map>
#include<list>

bool cycleDfs(int node,unordered_map<int,bool> &visited,int parent,unordered_map<int,list<int>> &adj)
{
    visited[node]=true;
    for(auto neighbour:adj[node])
    {
        if(!visited[neighbour])
        {
            bool ans=cycleDfs(neighbour,visited, node, adj);
            if(ans==true)
                return true;
        }
        //visited but not parent
        else if(neighbour!=parent) //cycle present
        {
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    //find out adjacency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool>visited;
    bool ans;
    //for loop to handle disconnected components
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            ans=cycleDfs(i,visited,-1,adj); //initially -1 is parent of src node
        }
        if(ans==true)
            return "Yes";
    }
    return "No";
}
