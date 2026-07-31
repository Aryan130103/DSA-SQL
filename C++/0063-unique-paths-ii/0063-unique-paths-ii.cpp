class Solution {
private:
    int f(int i,int j,vector<vector<int>>&grid,vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[0][0]==0;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(grid[i][j]==1) return 0;
        
        int up=f(i-1,j,grid,dp);
        int left=f(i,j-1,grid,dp);
        
        return dp[i][j]=up+left; 
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,grid,dp);
    }
};