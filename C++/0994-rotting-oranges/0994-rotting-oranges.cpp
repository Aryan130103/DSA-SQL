class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({0,{i,j}});
                }
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        if(fresh==0) return 0;
        
        int t=0,cnt=0;
        while(!q.empty()){
            auto it=q.front();
            int time=it.first;
            int r=it.second.first;
            int c=it.second.second;
            q.pop();

            t=max(t,time);
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};

            for(int k=0;k<4;k++){
                int nrow=r+dr[k];
                int ncol=c+dc[k];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=2;
                    q.push({time+1,{nrow,ncol}});
                    cnt++;
                }
            }

        }

        if(fresh!=cnt) return -1;
        
    return t;
    }
};