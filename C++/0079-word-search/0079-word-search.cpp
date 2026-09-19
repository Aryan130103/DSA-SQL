class Solution {
private:
    bool dfs(int r,int c,int i,string &word,vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();
        if(r<0 || c<0 || r>=n || c>=m || board[r][c]!=word[i])
        return false;

        if(i==word.size()-1) return true;

        char temp=board[r][c];
        board[r][c]='@';
        bool found= (dfs(r-1,c,i+1,word,board)||
                    dfs(r+1,c,i+1,word,board)||
                    dfs(r,c-1,i+1,word,board)||
                    dfs(r,c+1,i+1,word,board)
                    );
        
        board[r][c]=temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(i,j,0,word,board))
                    return true;
            }
        }
        return false;
    }
};