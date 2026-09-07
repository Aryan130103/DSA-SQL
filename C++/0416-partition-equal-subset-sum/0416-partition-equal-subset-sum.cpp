class Solution {
    bool f(int i,int t,vector<int>& nums,vector<vector<int>>& dp){
        if(t==0) return true;
        if(i==0) return nums[i]==t;
        if(dp[i][t]!=-1) return dp[i][t];

        bool take=false;
        if(nums[i]<=t)
            take=f(i-1,t-nums[i],nums,dp);
        bool notake=f(i-1,t,nums,dp);
        
        return dp[i][t]=take||notake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int t=0;
        for(auto it:nums) sum+=it;
        if(sum%2)return false;
        t=sum/2;
        vector<vector<int>>dp(n,vector<int>(t+1,-1));
        return f(n-1,t,nums,dp);
    }
};