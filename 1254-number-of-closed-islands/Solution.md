# Simple to Understand after you read my intuition  | C++ | DFS

# Intuition

0 -> land
1 -> water


1. Mark all the 0 on the boundary as visited and any 0 connecting to them using dfs calls.

Why: Lands on the edges can't be enclosed by water (basic island definition)

2. Now, just traverse all 0 remaining and mark it as well as its connected 0 (simple terms cover all lands that are connected using dfs).

and for every 0 you send for dfs, count the island.


Can't get it still, solve problems like: Number of Island(200), Surrounded regions(130)

# Complexity
- Time complexity: O(n*m)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(n*m)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
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
