class Solution {
private:
    void dfs(int i,int j,vector<vector<int>>& vis,int og,int color,vector<vector<int>>& image){
        int n=image.size();
        int m=image[0].size();
        vis[i][j]=1;
        image[i][j]=color;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int k=0;k<4;k++){
            int nrow=i+dr[k];
            int ncol=j+dc[k];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && image[nrow][ncol]==og){
                dfs(nrow,ncol,vis,og,color,image);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        dfs(sr,sc,vis,og,color,image);
            
        return image;

    }
};