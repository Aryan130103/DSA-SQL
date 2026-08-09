class Solution {
    int f(int i,int j,vector<int>& num1,vector<int>& num2,vector<vector<int>>& dp){
        if(i<0 ||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(num1[i]==num2[j])
            return dp[i][j]=1+f(i-1,j-1,num1,num2,dp);
        else
            return dp[i][j]=0;
    }
public:
    int findLength(vector<int>& num1, vector<int>& num2) {
        int n=num1.size();
        int m=num2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(num1[i-1]==num2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=0;
                ans=max(ans,dp[i][j]);
            }
        }

        return ans;
    }
};