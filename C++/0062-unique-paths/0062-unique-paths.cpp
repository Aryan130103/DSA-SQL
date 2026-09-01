class Solution {
private:
    int f(int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=0;
        int left=0;
        if(i>0) 
            left=f(i-1,j,dp);
        if(j>0)
            up=f(i,j-1,dp);
        int maxx=0;
        return dp[i][j]=up+left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,dp);
    }
};