class Solution {
private:
    int f(int i,int amount,vector<int>& coins, vector<vector<int>>& dp){
        if(i==0){
            if(amount%coins[i]==0) return amount/coins[i];
            else return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];

        int notake=f(i-1,amount,coins,dp);
        int take=1e9;
        if(coins[i]<=amount)
            take=1+f(i,amount-coins[i],coins,dp);
        return dp[i][amount]=min(take,notake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= f(n-1,amount, coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};