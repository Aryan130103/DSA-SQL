class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
                
        int minn=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
         vector<int> dist(n,1e9);
         dist[i]=0;
         pq.push({0,i});
         while(!pq.empty()){
            auto it=pq.top();
            int dst=it.first;
            int node=it.second;
            pq.pop();

            if(dst>dist[node]) continue;
            for(auto& it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(dst+wt<dist[adjnode]){
                    dist[adjnode]=dst+wt;
                    pq.push({dst+wt,adjnode});
                }
            }
         }

         int c=0;
         for(int i=0;i<n;i++){
            if(dist[i]<=distanceThreshold)
                c++;
         }
         if(c<=minn){
            minn=c;
            ans=i;
         }
        }
         return ans;
    }
};