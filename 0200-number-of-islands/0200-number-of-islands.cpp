class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;

        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0
                && grid[nrow][ncol]=='1')
                    dfs(nrow,ncol,vis,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool boundary= (i==0 || j==0 || i==n-1 || j==m-1);
                if(boundary && grid[i][j]=='1' && !vis[i][j]){
                    c++;
                    dfs(i,j,vis,grid);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    c++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return c;
    }
};