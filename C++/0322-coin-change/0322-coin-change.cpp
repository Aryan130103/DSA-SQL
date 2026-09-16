class Solution {
private:
    int f(int i,int t,vector<int>& coins,vector<vector<int>>& dp){
        if(i==0){
            if(t%coins[i]==0) return t/coins[i];
            else return 1e9;
        }
        if(dp[i][t]!=-1) return dp[i][t];

        int take=1e9;
        if(coins[i]<=t)
            take=1+f(i,t-coins[i],coins,dp);
        int notake=f(i-1,t,coins,dp);
        
        return dp[i][t]=min(take,notake);
    }
public:
    int coinChange(vector<int>& coins, int t) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(t+1,-1));
        int ans= f(n-1,t,coins,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};