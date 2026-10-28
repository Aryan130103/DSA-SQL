class Solution {
private:
    bool f(int i,int j,int x,vector<vector<vector<int>>>& dp,vector<vector<int>>&grid){
        
        if(i<0 || j<0) return false;
        if(dp[i][j][x]!=-1) return dp[i][j][x];
        if(i==0 && j==0) return dp[i][j][x]=(x==grid[0][0]);

        int prev=x^grid[i][j];

        bool up=f(i-1,j,prev,dp,grid);
        bool left=f(i,j-1,prev,dp,grid);

        return dp[i][j][x]=(up||left);
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(1024,-1)));

        for(int x=0;x<1024;x++){
            if(f(n-1,m-1,x,dp,grid))
                return x;
        }

        return 0;
    }
};