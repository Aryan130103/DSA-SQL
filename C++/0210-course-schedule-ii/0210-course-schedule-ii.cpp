class Solution {
private:
    bool dfs(int node,vector<int>& vis,vector<int>& path,vector<vector<int>> &adj,vector<int>& order){
        vis[node]=path[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,path,adj,order)) return true;
            }
            else if(path[it]) return true;
        }
        path[node]=0;
        order.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<int> vis(V,0),path(V,0),order;
        vector<vector<int>>adj(V);
        for(auto i:edges){
            adj[i[1]].push_back(i[0]);
        }

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,path,adj,order)) return {};
            }
        }

        reverse(order.begin(),order.end());
        return order;
    }
};