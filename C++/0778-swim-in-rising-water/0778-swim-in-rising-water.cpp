class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!pq.empty()){
            auto it=pq.top();
            int time=it.first;
            int r=it.second.first;
            int c=it.second.second;
            pq.pop();

            if(r==n-1 && c==n-1) return time;

            for(int i=0;i<4;i++){
                int nrow=r+dr[i];
                int ncol=c+dc[i];
                if(nrow>=0 && nrow<n && ncol<n && ncol>=0){
                    int newtime=max(time,grid[nrow][ncol]);
                    if(newtime<dist[nrow][ncol]){
                        dist[nrow][ncol]=newtime;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};