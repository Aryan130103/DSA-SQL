class Solution {
private:
    int rowcheck(int i,int j,int n,vector<vector<char>>& board){
        for(int x=0;x<n;x++){
            if(x!=j && (board[i][x]==board[i][j]))
                return false;
        }
        return true;
    }
    int colcheck(int i,int j,int m,vector<vector<char>>& board){
        for(int x=0;x<m;x++){
            if(x!=i && (board[x][j]==board[i][j]))
                return false;
        }
        return true;
    }
    int gridcheck(int i,int j,vector<vector<char>>& board){
        int boxr=(i/3)*3;
        int boxc=(j/3)*3;

        for(int x=boxr;x<boxr+3;x++){
            for(int y=boxc;y<boxc+3;y++){
                if((x!=i || y!=j) && board[i][j]==board[x][y])
                    return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.') continue;
                if(!rowcheck(i,j,n,board) || !colcheck(i,j,m,board) || !gridcheck(i,j,board))
                    return false;
            }
        }
        return true;
    }
};