struct Node{
    int key,val;
    Node* prev;
    Node* next;
    Node(int k,int v):key(k),val(v),prev(nullptr),next(nullptr){}
};

class LRUCache {
public:
    int cap=0;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> m;

    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        m.clear();
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        
        Node* node=m[key];
        deletenode(node);
        insertnode(node);
        
        return node->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* node=m[key];
            node->val=value;
            deletenode(node);
            insertnode(node);
        }
        else{
            if(m.size()==cap){
                Node* node=tail->prev;
                m.erase(node->key);
                deletenode(node);
                delete node;
            }

            Node* node= new Node(key,value);
            m[key]=node;
            insertnode(node);
        }
    }

    void deletenode(Node* node){
         Node* p=node->prev;
         Node* n=node->next;

         p->next=n;
         n->prev=p;
    }

    void insertnode(Node* node){
        Node* curr=head->next;

        node->next=curr;
        node->prev=head;
        head->next=node;
        curr->prev=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */