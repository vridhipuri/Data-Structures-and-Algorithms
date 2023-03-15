//Shortest Path in Unweighted Graphs (see copy)
#include<unordered_map>
#include<list>
#include<vector>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	//create adjacency list
	unordered_map<int,list<int>>adj;
	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i].first;
		int v=edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//do bfs
	queue<int>q;
	unordered_map<int,int>visited;
	unordered_map<int,int>parent;
	visited[s]=1;
	parent[s]=-1;
	q.push(s);
	while(!q.empty())
	{
		int front=q.front();
		q.pop();
		for(auto neighbour:adj[front])
		{
			if(!visited[neighbour])
			{
				
				visited[neighbour]=1;
				parent[neighbour]=front;
				q.push(neighbour);
			}
		}
	}
	//prepare shortest path
	vector<int>ans;
	int curr=t;
	ans.push_back(t);
	while(curr!=s)
	{
		curr=parent[curr];
		ans.push_back(curr);
	}
	reverse(ans.begin(),ans.end());
	return ans;
	
}
