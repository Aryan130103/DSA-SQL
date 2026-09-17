struct Node{
    int key,val,cnt;
    Node* next;
    Node* prev;
    Node(int a,int b){
        key=a;
        val=b;
        cnt=1;
    }
};
struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head= new Node(-1,-1);
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
        Node* cur=head->next;
        node->next=cur;
        node->prev=head;
        head->next=node;
        cur->prev=node;
        size++;
    }
};

class LFUCache {
public:
    int cap;
    unordered_map<int,Node*> m;
    unordered_map<int,List*> freqlistmap;
    int minfreq;
    int cursize;

    LFUCache(int capacity) {
        cap=capacity;
        minfreq=0;
        cursize=0;
    }

    void updatefreqlist(Node* node){
        m.erase(node->key);
        freqlistmap[node->cnt]->deletenode(node);
        if(node->cnt==minfreq && freqlistmap[node->cnt]->size==0)
            minfreq++;
        
        List* nextHigherFreqList;
        if(freqlistmap.find(node->cnt+1)!=freqlistmap.end())
            nextHigherFreqList=freqlistmap[node->cnt+1];
        else
            nextHigherFreqList=new List();

        node->cnt+=1;
        nextHigherFreqList->insertnode(node);
        freqlistmap[node->cnt]=nextHigherFreqList;
        m[node->key]=node;

    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* node=m[key];
            updatefreqlist(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap==0) return;

        if(m.find(key)!=m.end()){
            Node* node=m[key];
            node->val=value;
            updatefreqlist(node);
        }
        else{
            if(cursize==cap){
                List* list=freqlistmap[minfreq];
                Node* node=list->tail->prev;
                m.erase(node->key);
                freqlistmap[minfreq]->deletenode(node);
                delete node;
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