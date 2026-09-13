class Solution {
private:
    bool dfs(int r,int c,int i,auto &word,auto& board){
        int n=board.size();
        int m=board[0].size();

        if(r<0 || r>=n || c<0 || c>=m || board[r][c]!=word[i])
                return false;
        
        if(i==word.size()-1) return true;

        auto temp=board[r][c];
        board[r][c]='#';
        
        bool found=(dfs(r+1,c,i+1,word,board)||
                    dfs(r-1,c,i+1,word,board)||
                    dfs(r,c+1,i+1,word,board)||
                    dfs(r,c-1,i+1,word,board));
        
        board[r][c]=temp;
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(dfs(r,c,0,word,board))
                    return true;
            }
        }
        return false;
    }
};