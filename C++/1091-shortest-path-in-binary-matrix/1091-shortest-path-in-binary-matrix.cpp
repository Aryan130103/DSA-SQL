class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        dist[0][0]=1;
        pq.push({1,{0,0}});

        int dr[]={-1,-1,-1,0,1,1,1,0};
        int dc[]={-1,0,1,1,1,0,-1,-1};

        while(!pq.empty()){
            auto it=pq.top();
            int dst=it.first;
            int r=it.second.first;
            int c=it.second.second;
            pq.pop();

            if(r==n-1 && c==m-1) return dst;

            for(int i=0;i<8;i++){
                int nrow=dr[i]+r;
                int ncol=dc[i]+c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0){
                    if(dist[nrow][ncol]>dst+1){
                        dist[nrow][ncol]=dst+1;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};