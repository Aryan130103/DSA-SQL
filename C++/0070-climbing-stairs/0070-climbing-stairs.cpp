class Solution {
public:
    int climb(int n,unordered_map<int,int>& dp){
        if(n==0 || n==1) return 1;
        if(dp.find(n)==dp.end()){
            dp[n]=climb(n-1,dp)+climb(n-2,dp);
        }
        return dp[n];
    }

    int climbStairs(int n){
        unordered_map<int,int> dp;
        return climb(n,dp);
    }
};