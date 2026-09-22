# C++ | Backtracking | 

# Complexity
- Time complexity: 	O(N!*N)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(N²)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
private:
    bool valid(vector<string>& board,int row,int col,int n){
        for(int r=0;r<row;r++){
            if(board[r][col]=='Q')
                return false;
        }
        for(int r=row-1,c=col-1;r>=0 && c>=0;r--,c--){
            if(board[r][c]=='Q') return false;
        }
        for(int r=row-1,c=col+1;r>=0 && c<n;r--,c++){
            if(board[r][c]=='Q') return false;
        }
        return true;
    }   
    void solve(vector<string>& board,int row,int n,vector<vector<string>>& ans){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(valid(board,row,col,n)){
                board[row][col]='Q';
                solve(board,row+1,n,ans);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>> ans;

        solve(board,0,n,ans);
        return ans;
    }
};
```