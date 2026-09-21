class Solution {
private:
    bool valid(int r,int c, vector<vector<char>>& board,char val){
        for(int i=0;i<9;i++){
            if(board[r][i]==val || board[i][c]==val) return false;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==val) return false;
        }
        return true; 
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char val='1';val<='9';val++){
                        if(valid(i,j,board,val)){
                            board[i][j]=val;
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};