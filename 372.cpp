//Find the no. of Isalnds (see copy)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void bfs(vector<vector<char>>& grid, vector<vector<int>> &visited, int row, int col)
    {
        visited[row][col]=1;
        queue<pair<int,int>>q;
        int m=grid.size();
        int n=grid[0].size();
        q.push({row,col});
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            //find nbrs
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int nbrRow=r+i;
                    int nbrCol=c+j;
                    //if nbrRow and nbrCol lie in matrix and if they are land and if they are not visited
                    if(nbrRow>=0 && nbrRow<m && nbrCol>=0 && nbrCol<n
                    && grid[nbrRow][nbrCol]=='1' && !visited[nbrRow][nbrCol])
                    {
                        visited[nbrRow][nbrCol]=1;
                        q.push({nbrRow,nbrCol});
                    }
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int islands=0; //no.of connected components
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                    //if land   and    not visited
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    islands++;
                    bfs(grid,visited,i,j);
                }
            }
        }
        return islands;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends