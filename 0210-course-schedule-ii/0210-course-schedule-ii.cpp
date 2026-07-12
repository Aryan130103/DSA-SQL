class Solution {
public:
    bool dfs(int node,vector<int>& pathvis,vector<int>& vis,vector<vector<int>>& adj,vector<int>& order){
        vis[node]=1;
        pathvis[node]=1;

        for(auto& it:adj[node]){
            if(!vis[it]){
                if(dfs(it,pathvis,vis,adj,order)) return true;
            }
            else if(pathvis[it])
                return true;
        }
        pathvis[node]=0;
        order.push_back(node);
        return false;
    }
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        vector<int> order;

        for(auto& i: prerequisites){
                adj[i[1]].push_back(i[0]);
        }

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,pathvis,vis,adj,order)) return {};
            }
        }
        reverse(order.begin(),order.end());
        return order;
    }
};