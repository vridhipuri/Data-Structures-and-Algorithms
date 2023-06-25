//1575. Count All Possible Routes

class Solution {
public:

    int mod=1000000007;
    int solve(vector<int>& locations, int curr, int finish,int fuel, vector<vector<int>>& dp)
    {
        int res=0;
        if(fuel<0)
        {
            return 0;
        }
        if(curr==finish)
        {
            res++;
        }
        if(dp[curr][fuel]!=-1)
        {
            return dp[curr][fuel];
        }
        for(int i=0;i<locations.size();i++)
        {
            if(curr==i)
            {
                continue;
            }
            int cost=abs(locations[i]-locations[curr]);
            res=res+solve(locations,i,finish,fuel-cost,dp);
            res=res%mod;
        }
        return dp[curr][fuel]=res;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {

        vector<vector<int>> dp(locations.size(),vector<int>(fuel+1,-1));
        return solve(locations,start,finish,fuel,dp);
    }
};