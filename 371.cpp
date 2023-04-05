//Find whether it is possible to finish all tasks or not from given dependencies (see copy)
// Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    unordered_map<int,vector<int>>adj;
	    for(auto it:prerequisites)
	    {
	        int u=it.first;
	        int v=it.second;
	        //directed graph
	        adj[u].push_back(v);
	    }
	    //implement kahn's algo (topo sort using bfs)
	     //make indegree array
	     vector<int>indegree(N);
	     for(int i=0;i<N;i++)
	     {
	         for(auto it:adj[i])
	         {
	             indegree[it]++;
	         }
	     }
	     queue<int>q;
	     vector<int>ans;
	     for(int i=0;i<N;i++)
	     {
	         if(indegree[i]==0)
	         {
	             q.push(i);
	         }
	     }
	     while(!q.empty())
	     {
	         int front=q.front();
	         ans.push_back(front);
	         q.pop();
	         for(auto nbr:adj[front])
	         {
	             indegree[nbr]--;
	             if(indegree[nbr]==0)
	             {
	                 q.push(nbr);
	             }
	         }
	         
	     }
	     if(ans.size()==N) //saare nodes present in topo sort
	        return true;
	   return false;

	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends