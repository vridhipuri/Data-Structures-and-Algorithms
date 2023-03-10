#include <bits/stdc++.h> 

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<int>neighbours[n];
    for(int i=0;i<m;i++)
    {
        //extracting vertices of each edge
        int u=edges[i][0];
        int v=edges[i][1];

        //creating undirectional graph
        neighbours[u].push_back(v);
        neighbours[v].push_back(u);
    }
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++)
    {
        adj[i].push_back(i); //adj vector ke ith index be store node i
        //store neighbours in front node i
        for (int j = 0; j < neighbours[i].size();j++) // traverse neighbours for each node i
        {
          adj[i].push_back(neighbours[i][j]);
        }
    }
    return adj;
}