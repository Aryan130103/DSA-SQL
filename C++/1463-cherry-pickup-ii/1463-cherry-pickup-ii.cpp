class Solution {
private:
    int f(int r1,int c1,int c2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
         int n=grid.size();
        int m=grid[0].size();
        
        if( c1>m-1 || c2>m-1 || c1<0 || c2<0) return -1e9;
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        if(r1==n-1){
            if(c1==c2) return grid[r1][c1];
            else return grid[r1][c1]+grid[r1][c2];
        } 
        

        int cherry=(c1==c2)?grid[r1][c1]: grid[r1][c1]+grid[r1][c2];
/*
        int ans=max({f(r1+1,c1,c2,grid,dp),//down down
                    f(r1+1,c1+1,c2+1,grid,dp),//dr dr
                    f(r1+1,c1-1,c2-1,grid,dp),//dl dl
                    f(r1+1,c1-1,c2+1,grid,dp),//dl dr
                    f(r1+1,c1,c2+1,grid,dp),// d dr
                    f(r1+1,c1,c2-1,grid,dp),//d dl
                    f(r1+1,c1-1,c2,grid,dp),//dl d
                    f(r1+1,c1+1,c2,grid,dp),//dr d
                    f(r1+1,c1+1,c2-1,grid,dp)});//dr dl
*/      int ans=0;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                ans=max(ans,(f(r1+1,c1+x,c2+y,grid,dp)));
            }
        }

        return dp[r1][c1][c2]=cherry+ans; 
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return max(0,f(0,0,m-1,grid,dp));
    }
};