class Solution {
    int dr[4]={1,0,-1,0};
    int dc[4]={0,1,0,-1};
private:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();

        vis[i][j]=1;

        for(int k=0;k<4;k++){
            int nrow=i+dr[k];
            int ncol=j+dc[k];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==0)
                dfs(nrow,ncol,vis,grid);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool boundary=(i==0 || j==0 || i==n-1 || j==m-1);
                if(boundary && !vis[i][j] && grid[i][j ]==0)
                    dfs(i,j,vis,grid);
            }
        }

        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    dfs(i,j,vis,grid);
                    c++;
                }
            }
        }
        return c;
    }
};