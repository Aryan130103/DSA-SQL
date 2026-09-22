class Solution {
private:
    bool valid(int i,int j,vector<vector<char>>& board,char val){
        for(int x=0;x<9;x++){
            if(board[x][j]==val || board[i][x]==val) return false;
            if(board[3*(i/3)+x/3][3*(j/3)+x%3]==val) return false;
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