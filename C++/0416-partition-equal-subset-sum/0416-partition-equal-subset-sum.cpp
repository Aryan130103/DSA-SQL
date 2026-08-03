class Solution {/*
private:
    int f(int i,int s,vector<int>& nums,vector<vector<int>>& dp){
        if(s==0) return true;
        if(dp[i][s]!=-1) return dp[i][s];
        if(i==0) return (nums[i]==s);

        bool notake=f(i-1,s,nums,dp);
        bool take=false;
        if(nums[i]<=s)
            take=f(i-1,s-nums[i],nums,dp);

        return dp[i][s]= take ||  notake;
    }*/
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum%2) return false; 
        int s=sum/2;
        vector<vector<bool>>dp(n,vector<bool>(s+1,false));
        
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=s) dp[0][nums[0]]=true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=s;j++){
                bool notake=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j)
                    take=dp[i-1][j-nums[i]];

                dp[i][j]= take ||  notake;
            }
        }
        
        return dp[n-1][s];
    }
};