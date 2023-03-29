//Bridge in graph (see copy)
#include<unordered_map>
#include<vector>
#include<list>

void dfs(int node,int parent,vector<int> &disc, vector<int> &low, 
unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adj, vector<vector<int>> &res,
int &timer)
{
    visited[node]=true;
    disc[node]=low[node]=timer++;
    for(auto nbr:adj[node])
    {
        if(nbr==parent)
        {
            continue;
        }
        if(!visited[nbr])
        {
            dfs(nbr,node,disc,low,visited,adj,res,timer);
            low[node]=min(low[node],low[nbr]);
            //check if edge is bridge
            if(low[nbr]>disc[node])
            {
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(nbr);
                res.push_back(ans);
            }
        }
        else{
            //node visited and not parent
            //back edge found
            low[node]=min(low[node],disc[nbr]);
        }

    }
}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here

    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer=0;
    vector<int>disc(v,-1);
    vector<int>low(v,-1);
    int parent=-1;
    unordered_map<int,bool>visited;
    vector<vector<int>> res;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            dfs(i,parent,disc,low,visited,adj,res,timer);
        }
    }
    return res;

}