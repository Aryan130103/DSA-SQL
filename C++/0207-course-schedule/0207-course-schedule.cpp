class Solution {
private:
    bool dfs(int node,vector<int>& vis,vector<int>& path,vector<vector<int>>& adj){
        vis[node]=1;
        path[node]=1;

        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,path,adj)) return true;
            }
            else if(path[it]) return true;
        }
        path[node]=0;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        vector<int> path(n,0);

        for(auto it:edges){
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,path,adj)) return false;
            }
        }
        return true;
    }
};