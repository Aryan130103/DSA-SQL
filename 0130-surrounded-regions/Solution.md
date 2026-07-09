# Beats 100% | Simple Easy Solution | Clean multi-source DFS Traversal 

# Intuition
- The key observation is: an 'O' can only survive (not get flipped to 'X') if it's connected to a boundary 'O', directly or through a chain of adjacent 'O's. 
- Any 'O' region that never touches the edge of the board is fully surrounded and must become 'X'.
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
- Traverse every boundary element of the board and check if it was not visited before and is equal to 'O'.
![1.png](https://assets.leetcode.com/users/images/3f5bd5d0-2dd9-4db3-9482-7c8ed24baec1_1783538107.2297533.png)

- Call the DFS function and mark all the 'O' connected to the boundary 'O' as visited.
![dfs.png](https://assets.leetcode.com/users/images/220f84bf-9708-46a9-aac6-08ab1ab35f6f_1783538194.003989.png)

- Traverse the board matrix and what all is not visited, just mark them as 'X'.
![3.png](https://assets.leetcode.com/users/images/9e11bb40-f75a-47ed-83df-696e00ceda9f_1783538226.3962915.png)

<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity: O(n × m)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(n × m)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
     void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
        int n=board.size();
        int m=board[0].size();

        vis[row][col]=1;

        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && board[nrow][ncol]=='O' && vis[nrow][ncol]==0) 
                    dfs(nrow,ncol,board,vis);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool isboundary=(i==0 || j==0 || i==n-1 || j==m-1);
                if(isboundary && vis[i][j]==0 && board[i][j]=='O')
                    dfs(i,j,board,vis);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};
```
![LC.png](https://assets.leetcode.com/users/images/cfeae800-284f-408a-b732-86f7b43c10ed_1783537781.840206.png)
