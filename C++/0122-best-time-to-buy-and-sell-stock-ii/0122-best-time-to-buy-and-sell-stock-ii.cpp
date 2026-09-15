class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));

       
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<=1;b++){
                 int profit;
                if(b)
                    profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                else
                    profit=max(prices[i]+dp[i+1][1],dp[i+1][0]);

                dp[i][b]=profit;
            }
        }
        return dp[0][1];
    }
};