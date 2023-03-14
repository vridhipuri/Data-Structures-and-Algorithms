//Kahn's Algorithm (see copy)
#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    //make adjacency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];

        //directed graph
        adj[u].push_back(v);
    }

    //make indegree array
    vector<int>indegree(v);
    for(auto i:adj)
    {
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }
    //push 0 indegree wale in queue
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    //do bfs
    vector<int>ans;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        ans.push_back(front);

        //find neighbours
        for(auto neighbour:adj[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}