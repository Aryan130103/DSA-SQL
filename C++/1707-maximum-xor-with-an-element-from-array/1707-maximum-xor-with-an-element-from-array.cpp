struct Node{
    Node* list[2];
    Node(){
        list[0]=nullptr;
        list[1]=nullptr;
    }
    bool contain(int bit){
        return list[bit]!=NULL;
    }
    void put(int bit, Node* node){
        list[bit]=node;
    }
    Node* get(int bit){
        return list[bit];
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->contain(bit))
                node->put(bit,new Node());
            node=node->get(bit);
        }
    }
    int getMax(int num){
        Node* node=root;
        int maxx=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->contain(1-bit)){
                maxx|= 1<<i;
                node=node->get(1-bit);
            }
            else
                node=node->get(bit);
        }
        return maxx;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        sort(nums.begin(),nums.end());
        int q=queries.size();
        vector<pair<int,pair<int,int>>> oQ;
        for(int i=0;i<q;i++){
            oQ.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(oQ.begin(),oQ.end());
        int n=nums.size();
        int idx=0;
        vector<int> ans(q,0);
        for(int i=0;i<q;i++){
            int A=oQ[i].first;
            int X=oQ[i].second.first;
            int Qi=oQ[i].second.second;

            while(idx<n && nums[idx]<=A){
                trie.insert(nums[idx]);
                idx++;
            }
            if(idx==0) ans[Qi]= -1;
            else 
                ans[Qi]=trie.getMax(X);
        }
        return ans;
    }
};