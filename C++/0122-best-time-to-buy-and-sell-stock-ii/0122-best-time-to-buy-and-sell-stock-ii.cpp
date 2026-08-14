class Solution {
private:/*
    int f(int i,int buy,vector<int>& p,vector<vector<int>>& dp){
        if(i==p.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit=0;
        if(buy){
            profit=max((-p[i]+f(i+1,0,p,dp)),f(i+1,1,p,dp));
        }
        else{
            profit=max((p[i]+f(i+1,1,p,dp)),f(i+1,0,p,dp));
        }
        return dp[i][buy]=profit;
    }*/
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
       // vector<vector<int>>dp(n+1,vector<int>(2,-1));
       vector<int> ahead(2,0),cur(2,0);
        ahead[0]=ahead[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=max((-p[i]+ahead[0]),ahead[1]);
                }
                else{
                    profit=max((p[i]+ahead[1]),ahead[0]);
                }
                cur[buy]=profit;
            }
            ahead=cur;
        }
        return ahead[1];
    }
};