class Solution {
 /*MEMOISATION   
private:
    int f(int i,vector<int>& nums,vector<int>& dp){
        if(i==0) return nums[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=f(i-2,nums,dp)+nums[i];
        int notpick=f(i-1,nums,dp);
        
        return dp[i]=max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }*/

//TABULATION
/*
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=dp[i-2];
            int notake=dp[i-1];
            dp[i]=max(take,notake);
        }
    return dp[n-1];
    }*/

//SPACE OPTIMISATION
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=nums[0];
        int prev2=0,curr=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int notake=prev1;
            curr=max(take,notake);
            prev2=prev1;
            prev1=curr;
        }
    return prev1;
    }
};