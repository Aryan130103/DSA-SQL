class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int og){
        int n=image.size();
        int m=image[0].size();

        image[sr][sc]=color;

        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=sr+drow[i];
            int ncol=sc+dcol[i];

            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && image[nrow][ncol]==og)
                dfs(image,nrow,ncol,color,og);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og=image[sr][sc];
        if(og==color) return image;

        dfs(image,sr,sc,color,og);
        return image;
    }
};