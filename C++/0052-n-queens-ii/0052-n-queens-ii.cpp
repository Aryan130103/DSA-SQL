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
    void solve(vector<string>& board,int row,int n,int& ans){
        if(row==n){
            ans++;
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
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        int ans=0;

        solve(board,0,n,ans);
        return ans;
    }
};