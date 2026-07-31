class Solution {
private:
    int f(int i,int j,vector<vector<int>>&grid,vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[i][j];
        if(j<0 || i<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=f(i-1,j,grid,dp)+grid[i][j];
        int left=f(i,j-1,grid,dp)+grid[i][j];
        return dp[i][j]=min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,grid,dp);
    }
};