class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int MOD=1e9+7;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<int> ways(n,0);
        vector<long long> time(n,LLONG_MAX);
        time[0]=0;
        ways[0]=1;
        pq.push({0,0});

        while(!pq.empty()){
            auto it=pq.top();
            long long t=it.first;
            int node=it.second;
            pq.pop();

            if(t>time[node]) continue;

            for(auto it:adj[node]){
                int adjnode=it.first;
                long long wt=it.second;

                if(time[adjnode]>t+wt){
                    time[adjnode]=t+wt;
                    ways[adjnode]=ways[node];
                    pq.push({t+wt,adjnode});
                }
                else if(time[adjnode]==t+wt)
                     ways[adjnode]=(ways[adjnode]+ways[node])%MOD;
            }
        }
        return ways[n-1];
    }
};