class Solution {
private:
    bool dfs(int i,vector<int>& vis, vector<int>& path, vector<int>& order, vector<vector<int>>& adj){
        vis[i]=1;
        path[i]=1;

        for(auto& it:adj[i]){
            if(vis[it]==0){
                if(dfs(it,vis,path,order,adj)) return true;
            }
            else if(path[it]) return true;
        }
        path[i]=0;
        order.push_back(i);
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int> vis(n,0),path(n,0),order;

        for(auto& it:edges){
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(dfs(i,vis,path,order,adj)) return {};
            }
        }

        reverse(order.begin(),order.end());
        return order;
    }
};