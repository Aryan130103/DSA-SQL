class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>>dp(n+1,(vector<int>(5,0)));
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int t=0;t<=3;t++){
                if(t%2==0){
                    profit=max(-p[i]+dp[i+1][t+1],dp[i+1][t]);
                }
                else{
                    profit=max(p[i]+dp[i+1][t+1],dp[i+1][t]);
                }
                dp[i][t]=profit;
            }
        }
        return dp[0][0];
    }
};