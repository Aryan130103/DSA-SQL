class Solution {
private:
    void dfs(int i,int j,vector<vector<int>>& heights, vector<vector<int>>& vis){
        int n=heights.size();
        int m=heights[0].size();

        vis[i][j]=1;
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

        for(auto& d:dir){
            int x=i+d[0],y=j+d[1];
            if(x<0 || y<0 || x>=n || y>=m) continue;
            if(heights[x][y]<heights[i][j]) continue;
            if(vis[x][y]) continue;

            dfs(x,y,heights,vis);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));

        for(int i=0;i<n;i++) dfs(i,0,heights,pacific);
        for(int j=0;j<m;j++) dfs(0,j,heights,pacific);

        for(int j=m-1;j>=0;j--) dfs(n-1,j,heights,atlantic);
        for(int i=n-1;i>=0;i--) dfs(i,m-1,heights,atlantic);

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};