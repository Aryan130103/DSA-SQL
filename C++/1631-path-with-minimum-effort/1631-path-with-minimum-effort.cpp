class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            int effort=it.first;
            int r=it.second.first;
            int c=it.second.second;
            pq.pop();

            if(r==n-1 && c==m-1) return effort;

            for(int i=0;i<4;i++){
                int nrow=dr[i]+r;
                int ncol=dc[i]+c;
               
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int hdiff=abs(h[r][c]-h[nrow][ncol]);
                    int maxx=max(effort,hdiff);

                    if(maxx<dist[nrow][ncol]){
                        dist[nrow][ncol]=maxx;
                        pq.push({maxx,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};