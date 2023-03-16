//Dijkstra algo (see copy)
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) 
{
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<edges;i++)
    {
        int u=vec[i][0];
        int v=vec[i][1];
        int wt=vec[i][2];
        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }
    vector<int>dist(vertices);
    for(int i=0;i<vertices;i++)
    {
        dist[i]=INT_MAX;
    }
    set<pair<int,int>>s;
    dist[source]=0;
    s.insert(make_pair(0,source));
    while(!s.empty())
    {
        //fetch top record
        auto top=*(s.begin());
        int nodeDist=top.first;
        int topNode=top.second;
        //remove top record from set
        s.erase(s.begin());
            
        for(auto neighbour:adj[topNode])
        {
            if(nodeDist+neighbour.second<dist[neighbour.first])
            {
                auto record=s.find(make_pair(dist[neighbour.first],neighbour.first));
                //if set already has the record w same node, delete it
                if(record!=s.end())
                {
                        s.erase(record);
                }
                //update in distance vector
                dist[neighbour.first]=nodeDist+neighbour.second;
                //put (updated distance,node) in set
                s.insert(make_pair(dist[neighbour.first],neighbour.first));
                
            }
        }
    }
    return dist;
}
