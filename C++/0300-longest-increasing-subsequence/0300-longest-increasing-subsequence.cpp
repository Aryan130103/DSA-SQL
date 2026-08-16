class Solution {/*
private:
    int f(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
        int n=nums.size();
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int take=0,notake=0;
        if(prev==-1 || nums[i]>nums[prev])
            take=1+f(i+1,i,nums,dp);
        notake=f(i+1,prev,nums,dp);

        return dp[i][prev+1]=max(take,notake);
    }*/
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxx=1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dp[i]=max(1+dp[prev],dp[i]);
                }
            }
            maxx=max(maxx,dp[i]);
        }
        return maxx;

        /*
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int take=0,notake=0;
                if(prev==-1 || nums[i]>nums[prev])
                    take=1+dp[i+1][i+1];
                notake=dp[i+1][prev+1];

                dp[i][prev+1]=max(take,notake);
            }
        }
        return dp[0][-1+1];
        */

        /*
        vector<int> temp;
        temp.push_back(nums[0]);
        int l=1;
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                l++;
            }
            else{
                int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
        }
        return l;*/
    }
};