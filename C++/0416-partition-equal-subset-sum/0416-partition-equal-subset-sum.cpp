class Solution {
private:
    bool f(int i,int s,vector<int>& nums,vector<vector<int>>& dp){
        if(s==0) return true;
        if(i==0) return (nums[i]==s);
        if(dp[i][s]!=-1) return dp[i][s];

        bool notake=f(i-1,s,nums,dp);
        bool take=false;
        if(nums[i]<=s)
            take=f(i-1,s-nums[i],nums,dp);
        return dp[i][s]=take || notake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i:nums) sum+=i;
        if(sum%2) return false;
        int s=sum/2;
        vector<vector<int>> dp(n,vector<int>(s+1,-1));
        return f(n-1,s,nums,dp);
    }
};