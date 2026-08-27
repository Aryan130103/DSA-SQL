class Solution {
private:
    int f(int n,unordered_map<int ,int>& dp){
        if(n==0 || n==1) return 1;
        if(dp.find(n)==dp.end())
            dp[n]=f(n-1,dp)+f(n-2,dp);
        
        return dp[n];
    }
public:
    int climbStairs(int n) {
        unordered_map<int ,int> dp;
        return f(n,dp);
    }
};