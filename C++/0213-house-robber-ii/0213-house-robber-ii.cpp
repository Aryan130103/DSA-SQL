class Solution {
private:
    int f(int i,vector<int>& nums, vector<int>& dp){
        if(i<0) return 0;
        if(i==0) return nums[0];
        if(dp[i]!=-1) return dp[i];
        int notake=f(i-1,nums,dp);
        int take=nums[i]+f(i-2,nums,dp);
        
        return dp[i]=max(take,notake);
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        vector<int> dp1(n,-1);
        vector<int> a,b;
        for(int i=0;i<n;i++){
            if(i!=0) a.push_back(nums[i]);
            if(i!=n-1) b.push_back(nums[i]);
        }
        return max(f(n-2,a,dp),f(n-2,b,dp1));
    }
};