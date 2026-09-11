class disjoint{
public:
    vector<int> parent,size;
    disjoint(int n){
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
        int UP=0,VP=0;
        UP=ult_p(u);
        VP=ult_p(v);
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxr=0,maxc=0;
        for(auto &it:stones){
            maxr=max(maxr,it[0]);
            maxc=max(maxc,it[1]);
        }
        disjoint d(maxr+maxc+1);
        unordered_map<int,int> m;

        for(auto &it : stones){
            int nrow=it[0];
            int ncol=it[1]+maxr+1;
            d.unionbysize(nrow,ncol);
            m[nrow]=1;
            m[ncol]=1;
        }

        int NC=0;
        for(auto& it:m){
            if(it.first==d.ult_p(it.first))
                NC++;
        }
        return n-NC;
    }
};