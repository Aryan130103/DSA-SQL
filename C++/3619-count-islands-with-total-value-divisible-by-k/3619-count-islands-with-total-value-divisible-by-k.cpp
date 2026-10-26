class Solution {
    int dr[4]={1,0,-1,0};
    int dc[4]={0,1,0,-1};
private:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid,long long& sum){
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int k=0;k<4;k++){
            int nrow=i+dr[k];
            int ncol=j+dc[k];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]>0){
                sum+=grid[nrow][ncol];
                dfs(nrow,ncol,vis,grid,sum);
            }
        }
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int c=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long sum=0;
                if(!vis[i][j] && grid[i][j]>0){
                    sum=grid[i][j];
                    dfs(i,j,vis,grid,sum);
                    if(sum%k==0)
                        c++;
                }
            }
        }
        return c;
    }
};