class disjoint{
    vector<int>parent,size;
    public:
    disjoint(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int ult_p(int x){
        if(x==parent[x]) return x;
        return parent[x]=ult_p(parent[x]);
    }
/*
    bool find(int u,int v){
        int UP=0,VP=0;
        UP=ult_p(u);
        VP=ult_p(v);
        if(UP==VP) return true;
        return false;
    }*/

    void unionbysize(int u,int v){
        int UP=0,VP=0;
        UP=ult_p(u);
        VP=ult_p(v);
        if(UP==VP) return;
        if(size[UP]>size[VP]){
            parent[VP]=UP;
            size[UP]+=size[VP];
        }
        else{
            parent[UP]=VP;
            size[VP]+=size[UP];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        disjoint d(n);
        for(auto it:connections){
            d.unionbysize(it[0],it[1]);
        }

        int NC=0;
        for(int i=0;i<n;i++){
            if(d.ult_p(i)==i) NC++;
        }
        return NC-1;
    }
};