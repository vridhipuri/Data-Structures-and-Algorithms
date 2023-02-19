//Min Cost Climbing Stairs (see copy)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        int prev1=cost[1]; //i-1 th step
        int prev2=cost[0]; //i-2 th step
        int curr;
        for(int i=2;i<n;i++)
        {
            curr=cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=curr;
        }
        return min(prev1,prev2);
    }
};