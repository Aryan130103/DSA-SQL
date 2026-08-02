class Solution {
private:
    int f(int r1,int c1,int r2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int c2=r1+c1-r2;
        if(r1<0 || c1<0 || r2<0 || c2<0) return -1e9;
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1) return -1e9;
        if(r1==0 && c1==0) return grid[0][0];
        if(dp[r1][c1][r2]!=-1e9) return dp[r1][c1][r2];

        int cherry=(r1==r2 && c1==c2)?grid[r1][c1]: grid[r1][c1]+grid[r2][c2];

        int ans=max({f(r1-1,c1,r2-1,grid,dp),//up up
                    f(r1-1,c1,r2,grid,dp),
                    f(r1,c1-1,r2-1,grid,dp),
                    f(r1,c1-1,r2,grid,dp)});
        
        return dp[r1][c1][r2]=cherry+ans; 
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1e9)));
        return max(0,f(n-1,n-1,n-1,grid,dp));
    }
};