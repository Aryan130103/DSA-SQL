class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        if(n==1 && m==1) return 1;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            int dis=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();

            int dr[]={-1,-1,-1,0,1,1,1,0};
            int dc[]={-1,0,1,1,1,0,-1,-1};
            for(int i=0;i<8;i++){
                int nrow=r+dr[i];
                int ncol=c+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=dis+1;
                    if(nrow==n-1 && ncol==m-1) return dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};