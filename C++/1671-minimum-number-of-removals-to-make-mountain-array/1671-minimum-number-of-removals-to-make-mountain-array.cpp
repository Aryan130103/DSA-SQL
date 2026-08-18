class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),dp1(n,1);
        //int maxx=0,maxx1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
           //maxx=max(maxx,dp[i]);
        }

        
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j] && dp1[i]<dp1[j]+1)
                    dp1[i]=dp1[j]+1;
            }
            //maxx1=max(maxx1,dp1[i]);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]>1 && dp1[i]>1)
            ans=max(ans,dp[i]+dp1[i]-1);
        }
        return n-ans;
    }
};