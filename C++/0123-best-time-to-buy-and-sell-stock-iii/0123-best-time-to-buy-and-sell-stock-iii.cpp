class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(5,0));

       
        for(int i=n-1;i>=0;i--){
            for(int t=0;t<=3;t++){
                 int profit;
                if(t%2==0)
                    profit=max(-prices[i]+dp[i+1][t+1],dp[i+1][t]);
                else
                    profit=max(prices[i]+dp[i+1][t+1],dp[i+1][t]);

                dp[i][t]=profit;
            }
        }
        return dp[0][0];
    }
};