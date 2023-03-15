//Shortest Path in Directed Acyclic Graphs (see copy)
#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<stack>
#include<limits.h>
using namespace std;

class Graph{
    public:
    //adjacency list with distance
    unordered_map<int,list<pair<int,int>>> adj;

    void addEdge(int u, int v, int wt)
    {
        pair<int,int>p=make_pair(v,wt);
        adj[u].push_back(p);
    }
    void print()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<"( "<<j.first<<" , "<<j.second<<" ), ";
            }
            cout<<endl;
        }
    }
    void dfs(int node,stack<int> &s, vector<int> &visited)
    {
        visited[node]=1;
        for(auto neighbour:adj[node])
        {
            if(!visited[neighbour.first])
            {
                dfs(neighbour.first,s,visited);
            }
        }
        s.push(node);
    }
    void shortestDist(vector<int> &distance,stack<int> &s)
    {
        while(!s.empty())
        {
            int top=s.top();
            s.pop();
            if(distance[top]!=INT_MAX)
            {
                for(auto i:adj[top])
                {
                    //i.second is wt of edge, i.first is neighbouring node, tabhi it is written like distance[i.first]
                    if(distance[top]+i.second<distance[i.first])  
                    {
                        distance[i.first]=distance[top]+i.second; //updating
                    }
                    
                }
            }
        }
    }
};
int main()
{
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.print();

    int n=6; //no.of nodes
    stack<int>s;
    vector<int>visited(n,0);
    //topological sort
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            g.dfs(i,s,visited);
        }
    }
    int src=1;
    vector<int>distance(n,INT_MAX);
    distance[src]=0;
    g.shortestDist(distance,s);
    for(int i=0;i<distance.size();i++)
    {
        cout<<distance[i]<<" ";
    }
    cout<<endl;
    return 0;

}