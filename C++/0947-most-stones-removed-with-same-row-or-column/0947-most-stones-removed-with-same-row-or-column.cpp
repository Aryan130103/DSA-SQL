class Disjoint{
    public:
        vector<int> parent,size;
        Disjoint(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++) parent[i]=i;
        }

        int ult_p(int n){
            if(n==parent[n]) return n;
            return parent[n]=ult_p(parent[n]);
        }

        void unionbysize(int u,int v){
            int UP=ult_p(u);
            int VP=ult_p(v);

            if(UP==VP) return ;

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
        int maxxr=0,maxxc=0;
        

        for(auto& it:stones){
            if(it[0]>maxxr) maxxr=it[0];
            if(it[1]>maxxc) maxxc=it[1];
        }

        unordered_map<int,int> m;
        Disjoint d(maxxr+maxxc+1);
        
        for(auto& it:stones){
            int nrow=it[0];
            int ncol=it[1]+maxxr+1;
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