//Minimum time taken by each job to be completed given by a Directed Acyclic Graph (see copy)
#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;
int main()
{
    unordered_map<int,vector<int>>adj;
    int v,e;
    cin>>v>>e;
    vector<int> indegree(v+1,0); //1 based indexing
    for(int i=0;i<e;i++) 
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); //directed fgraph
        indegree[v]++;
    }
    vector<int> time(v+1,0);
    queue<int>q;
    for(int i=1;i<=v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            time[i]=1;
        }
    }
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(auto nbr:adj[front])
        {
            indegree[nbr]--;
            if(indegree[nbr]==0)
            {
                q.push(nbr);
                time[nbr]=time[front]+1;
            }
        }
    }
    for(int i=1;i<=v;i++)
    {
        cout<<time[i]<<" ";
    }
    return 0;

}