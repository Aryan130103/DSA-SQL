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
            parent[UP]=parent[VP];
            size[VP]+=size[UP];
        }
        else{
            parent[VP]=parent[UP];
            size[UP]+=size[VP];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;

        disjointset ds(n);
        for(auto &it:connections){
            int u=it[0];
            int v=it[1];
            ds.unionbysize(u,v);
        }

        int NC=0;
        for(int i=0;i<n;i++){
            if(ds.ult_p(i)==i) NC++;
        }

        return NC-1;
    }
};