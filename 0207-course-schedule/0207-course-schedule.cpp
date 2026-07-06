class Solution {
private:
    bool dfs(int node,vector<int>& pathvis, vector<int>& vis, vector<vector<int>>& adj){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,pathvis,vis,adj)) return true;
            }
            else if(pathvis[it]) return true;
        }
        pathvis[node]=0;
        return false;
    }
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(auto& i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(V,0),pathvis(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,pathvis,vis,adj)) return false;
            }
        }
        return true;
    }
};