struct Node{
    int key,val,cnt;
    Node* prev,*next;
    Node(int a,int b){
        key=a;
        val=b;
        cnt=1;
        next=nullptr;
        prev=nullptr;
    }
};

struct List{
    Node* head;
    Node* tail;
    int size;

    List(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }

    void deletenode(Node* node){
        Node* p=node->prev;
        Node* n=node->next;

        p->next=n;
        n->prev=p;
        size--;
    }

    void insertnode(Node* node){
        Node* curr=head->next;

        node->next=curr;
        node->prev=head;
        head->next=node;
        curr->prev=node;
        size++;
    }
};
class LFUCache {
public:
    unordered_map<int,Node*> m;
    unordered_map<int,List*> freqlistmap;
    int cap=0;
    int minfreq,cursize;

    LFUCache(int capacity) {
        cap=capacity;
        cursize=0;
        minfreq=0;
    }

    void updatefreqlistmap(Node* node){
        m.erase(node->key);
        freqlistmap[node->cnt]->deletenode(node);
        if(node->cnt==minfreq && freqlistmap[node->cnt]->size==0)
            minfreq++;
        
        List* nextgreaterfreqlist;
        if(freqlistmap.find(node->cnt+1)!=freqlistmap.end())
            nextgreaterfreqlist=freqlistmap[node->cnt+1];
        else
            nextgreaterfreqlist=new List();

        node->cnt+=1;
        nextgreaterfreqlist->insertnode(node);
        m[node->key]=node;
        freqlistmap[node->cnt]=nextgreaterfreqlist;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* node=m[key];
            updatefreqlistmap(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap==0) return;

        if(m.find(key)!=m.end()){
            Node* node=m[key];
            node->val=value;
            updatefreqlistmap(node);
        }
        else{
            if(cursize==cap){
                List* list=freqlistmap[minfreq];
                Node* node=list->tail->prev;
                freqlistmap[minfreq]->deletenode(node);
                m.erase(node->key);
                delete(node);
                cursize--;
            }
            cursize++;
            minfreq=1;
            List* listfreq=new List();
            if(freqlistmap.find(minfreq)!=freqlistmap.end())
                listfreq=freqlistmap[minfreq];
            
            Node* node=new Node(key,value);
            listfreq->insertnode(node);
            m[key]=node;
            freqlistmap[minfreq]=listfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */