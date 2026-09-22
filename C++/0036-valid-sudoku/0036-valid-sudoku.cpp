class Solution {
private:
    bool valid(int i,int j,vector<vector<char>>& board){
        for(int x=0;x<9;x++){
            if((x!=i && board[x][j]==board[i][j]) || (x!=j && board[i][x]==board[i][j]))
                return false;
            
            int boxr=3*(i/3)+(x/3);
            int boxc=3*(j/3)+(x%3);
            if((boxr!=i || boxc!=j) &&  board[boxr][boxc]==board[i][j]) return false;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(!valid(i,j,board)) 
                    return false;
            }
        }
        return true;
    }
};