class disjointset{
    public:
    vector<int> size,parent;
    disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int ult_p(int n){
        if(n==parent[n]) return n;
        return parent[n]=ult_p(parent[n]);
    }
    void unionbysize(int u,int v){
        int UP=ult_p(u);
        int VP=ult_p(v);
        if(UP==VP) return;
        
        if(size[UP]<size[VP]){
            parent[UP]=VP;
            size[VP]+=size[UP];
        }
        else{
            parent[VP]=UP;
            size[UP]+=size[VP];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        disjointset ds(n*n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int dr[]={-1,0,1,0};
                    int dc[]={0,1,0,-1};
                    for(int k=0;k<4;k++){
                        int nrow=i+dr[k];
                        int ncol=j+dc[k];
                        if(ncol>=0 && nrow>=0 && nrow<n && ncol<n){
                            if(grid[nrow][ncol]==1){
                                int node=i*n+j;
                                int adjnode=nrow*n+ncol;
                                ds.unionbysize(node,adjnode);
                            }
                        
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int> st;
                    int dr[]={-1,0,1,0};
                    int dc[]={0,1,0,-1};
                    for(int k=0;k<4;k++){
                        int nrow=i+dr[k];
                        int ncol=j+dc[k];
                        if(ncol>=0 && nrow>=0 && nrow<n && ncol<n){
                            if(grid[nrow][ncol]==1){
                                int adjnode=nrow*n+ncol;
                                st.insert(ds.ult_p(adjnode));
                            }
                        }
                    }
                    int c=1;
                    for(auto it:st)
                        c+=ds.size[it];
        
                    ans=max(ans,c);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans=max(ans,ds.size[ds.ult_p(i*n+j)]);
                }
            }
        }
    return ans;
    }
};