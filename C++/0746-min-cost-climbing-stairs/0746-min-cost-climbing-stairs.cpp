class Solution {
    private:    
    int f(int i,vector<int>& cost, vector<int>& dp){
        if(i==0 || i==1) return 0;
        if(dp[i]!=-1) return dp[i];
    
        int odd=f(i-1,cost,dp)+cost[i-1];
        int even=f(i-2,cost,dp)+cost[i-2];
        
        return dp[i]=min(odd,even);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
         int n=cost.size();
        vector<int> dp(n+1,-1);
        return f(n,cost,dp);
    }
};