class Solution {
private:
    void dfs(int i,int j,vector<vector<int>>& h,vector<vector<int>>& vis){
        vis[i][j]=1;
        int n=h.size();
        int m=h[0].size();
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

        for(auto& d:dir){
            int x=d[0]+i,y=j+d[1];
            if(x<0 || y<0 || x>=n || y>=m || vis[x][y] || h[x][y]<h[i][j])
                continue;

            dfs(x,y,h,vis);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();

        vector<vector<int>>p (n,vector<int>(m,0));
        vector<vector<int>>a (n,vector<int>(m,0));

        for(int i=0;i<n;i++) dfs(i,0,h,p);
        for(int j=0;j<m;j++) dfs(0,j,h,p);

        for(int i=n-1;i>=0;i--) dfs(i,m-1,h,a);
        for(int j=m-1;j>=0;j--) dfs(n-1,j,h,a);

        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[i][j] && a[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};