class Solution {
private:
    bool dfs(int i,int j,int x,vector<vector<char>>& b, string& word){
        int n=b.size();
        int m=b[0].size();

        if(i<0 || j<0 || i>=n ||j>=m || b[i][j]!=word[x]) return false;

        if(x==word.size()-1) return true;

        char temp=b[i][j];
        b[i][j]='@';

        bool found=(dfs(i-1,j,x+1,b,word) ||
                    dfs(i+1,j,x+1,b,word) ||
                    dfs(i,j+1,x+1,b,word) ||
                    dfs(i,j-1,x+1,b,word));
        
        b[i][j]=temp;
        
        return found;
    }
public:
    bool exist(vector<vector<char>>& b, string word) {
        int n=b.size();
        int m=b[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(i,j,0,b,word)) return true;
            }
        }
        return false;
    }
};