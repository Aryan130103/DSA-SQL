class Solution {
private:
    void dfs(int node,vector<int> ls[],vector<int>& vis){
        vis[node]=1;
        for(auto it:ls[node]){
            if(!vis[it])
                dfs(it,ls,vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int> ls[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(adj[i][j]==1 && i!=j){
                    ls[i].push_back(j);
                    ls[j].push_back(i);
                }
            }
        }
        int c=0;
        vector<int> vis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                c++;
                dfs(i,ls,vis);
            }
        }
        return c;
    }
};