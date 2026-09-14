class Solution {
private:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        for(int k=0;k<4;k++){
            int nrow=dr[k]+i;
            int ncol=dc[k]+j;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(i,j,vis,grid);
                    c++;
                }
            }
        }
        return c;
    }
};