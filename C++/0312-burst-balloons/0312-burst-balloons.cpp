class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-2;i>=1;i--){
            for(int j=i;j<=n-2;j++){
                int maxx=0;
                if(i>j) continue;
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