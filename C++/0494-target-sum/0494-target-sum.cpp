class Solution {
private:
int f(int i,int t,vector<int>& nums,vector<vector<int>>& dp){
    if(i==0) {
        if(t==0 && nums[i]==0) return 2;
        if(t==0 || nums[i]==t) return 1;
        else return 0;
    }
    if(dp[i][t]!=-1) return dp[i][t];

    int notake=f(i-1,t,nums,dp);
    int take=0;
    if(nums[i]<=t) take=f(i-1,t-nums[i],nums,dp);
    return dp[i][t]=take+notake;
}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum<abs(target)) return 0;
        if((sum-target)%2) return 0;
        int s=(sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(s+1,-1));
        return f(n-1,s,nums,dp);
    }
};