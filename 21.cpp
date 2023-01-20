//Best time to buy and Sell stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit;
        int profitMax=0;
        int mini=prices[0];

       for(int i=0;i<prices.size();i++)
       {
           mini=min(mini,prices[i]);
           profit=prices[i]-mini;
           profitMax=max(profitMax,profit);

       }
       return profitMax;
    }

};