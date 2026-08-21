class Solution {/*
private:
    int f(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxx=0;
        for(int k=i;k<=j;k++){
            int cost=nums[i-1]*nums[k]*nums[j+1]+f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
            maxx=max(maxx,cost);
        }
        return dp[i][j]=maxx;
    }*/
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=n-2;i>=1;i--){
            for(int j=i;j<=n-2;j++){
                int maxx=0;
                for(int k=i;k<=j;k++){
                    int cost=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                    maxx=max(maxx,cost);
                }
                dp[i][j]=maxx;
            }
        }

        return dp[1][n-2];
    }
};