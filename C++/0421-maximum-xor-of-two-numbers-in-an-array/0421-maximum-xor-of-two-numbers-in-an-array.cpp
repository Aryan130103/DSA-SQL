struct Node{
    Node* list[2];

    Node(){
        list[1]=nullptr;
        list[0]=nullptr;
    }
    bool contain(int bit){
        return list[bit]!=NULL;
    }
    void put(int bit,Node* node){
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
                    maxx= maxx | 1<<i;
                    node=node->get(1-bit);
                }
                else
                    node=node->get(bit);
            }
            return maxx;
        }
};

class Solution{
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(auto& it:nums) t.insert(it);
        int maxx=0;
        for(auto it:nums){
            maxx=max(maxx,t.getMax(it));
        } 

        return maxx;
    }
};