//Implement Topological Sort (see copy)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void topological(int node, vector<int> adj[], vector<int> &visited, stack<int> &s)
	{
	    visited[node]=1;
	    for(auto neighbour:adj[node])
	    {
	        if(!visited[neighbour])
	        {
	            topological(neighbour,adj,visited,s);
	        }
	    }
	    s.push(node); //return krte hue push the current node in stack
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans;
	    vector<int>visited(V,0);
	    stack<int>s;
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            topological(i,adj,visited,s);
	        }
	    }
	    //topo order will come in stack, we are storing it in ans vector to return
	    while(!s.empty()) 
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
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
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends