class Solution {
private:
    int f(int i,int t,vector<int>& coins,vector<vector<int>>&dp){
        if(i==0){
            if(t%coins[i]==0) return 1;
            else return 0;
        }
        if(dp[i][t]!=-1) return dp[i][t];
        int notake=f(i-1,t,coins,dp);
        int take=0;
        if(coins[i]<=t) take=f(i,t-coins[i],coins,dp);
        return dp[i][t]=take+notake;
    }
public:
    int change(int target, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,coins,dp);
    }
};