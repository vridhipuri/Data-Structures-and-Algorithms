//956. Tallest Billboard

class Solution {
public:
    /*int recursion(vector<int> &rods, int index, int r1, int r2)
    {
        if(index==rods.size())
        {
            if(r1==r2)
            {
                return r1;
            }
            return 0;
        }
        
        int r1Taken=recursion(rods,index+1,r1+rods[index],r2);
        int r2Taken=recursion(rods,index+1,r1,r2+rods[index]);
        int notTakenAny=recursion(rods,index+1,r1,r2);
        return max(notTakenAny,max(r1Taken,r2Taken));
    }*/
    int memoization(vector<int> &rods, int index, int diff, vector<vector<int>> &dp)
    {
        if(index==rods.size())
        {
            if(diff==0)
            {
                return 0;
            }
            return INT_MIN;
        }
        if(dp[index][diff+5000]!=-1)
        {
            return dp[index][diff+5000];
        }
        
        int r1Taken=rods[index]+memoization(rods,index+1,diff+rods[index],dp);
        int r2Taken=memoization(rods,index+1,diff-rods[index],dp);
        int notTakenAny=memoization(rods,index+1,diff,dp);
        return dp[index][diff+5000]=max(notTakenAny,max(r1Taken,r2Taken));
    }
    int tallestBillboard(vector<int>& rods) {
        //return recursion(rods,0,0,0);
        vector<vector<int>>dp(21,vector<int>(2*5000+1,-1));
        return memoization(rods,0,0,dp);
    }
};