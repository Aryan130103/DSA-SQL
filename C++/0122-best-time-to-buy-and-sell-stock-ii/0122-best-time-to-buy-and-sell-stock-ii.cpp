class Solution {
private:
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
    }
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,p,dp);
    }
};