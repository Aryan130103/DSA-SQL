class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0,cost=prices[0];
        for(int d=1;d<n;d++){
            cost=min(cost,prices[d-1]);
            profit=max(profit,prices[d]-cost);
        }
        return profit;
    }
};