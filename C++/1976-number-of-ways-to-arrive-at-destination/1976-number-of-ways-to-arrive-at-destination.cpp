class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        const int MOD=1000000007;
        for(auto &it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});

        while(!pq.empty()){
            auto it=pq.top();
            long long dst=it.first;
            int node=it.second;
            pq.pop();

            if(dst>dist[node]) continue;

            for(auto &it:adj[node]){
                int adjnode=it.first;
                long long wt=it.second;
                if(dst+wt<dist[adjnode]){
                    ways[adjnode]=ways[node];
                    dist[adjnode]=dst+wt;
                    pq.push({dst+wt,adjnode});
                }
                else if(dst+wt==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};