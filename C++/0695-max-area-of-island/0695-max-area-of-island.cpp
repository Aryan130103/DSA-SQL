class Solution {
    int dr[4]={1,0,-1,0};
    int dc[4]={0,1,0,-1};

private:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid,int& area){
        int n=grid.size();
        int m=grid[0].size();

        vis[i][j]=1;
        area++;

        for(int k=0;k<4;k++){
            int nrow=i+dr[k];
            int ncol=j+dc[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
                dfs(nrow,ncol,vis,grid,area);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int maxx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int area=0;
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(i,j,vis,grid,area);
                    maxx=max(maxx,area);
                }
            }
        }
        return maxx;
    }
};