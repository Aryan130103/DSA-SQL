class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>dist(n,1e9);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[src]=0;
        pq.push({0,{src,0}});

        while(!pq.empty()){
            auto it=pq.top();
            int cost=it.second.second;
            int stops=it.first;
            int node=it.second.first;
            pq.pop();

            if(stops>k) continue;
            
            for(auto it:adj[node]){
                int adjnode=it.first;
                int newCost=it.second;
                if(dist[adjnode]>cost+newCost && stops<=k){
                    dist[adjnode]=cost+newCost;
                    pq.push({stops+1,{adjnode,dist[adjnode]}}) ;
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};