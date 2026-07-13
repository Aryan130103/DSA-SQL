class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<vector<int>> adjrev(V);        
        vector<int> indeg(V,0);

        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adjrev[it].push_back(i);
                indeg[i]++;   
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it :adjrev[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};