class RandomizedSet {
public:
    unordered_map<int,int> m;
    vector<int> data;
    RandomizedSet() {}
    
    bool insert(int val) {
        if(m.count(val)) return false; 
        m[val]=data.size();
        data.push_back(val);
        return true; 
    }
    
    bool remove(int val) {
        if(!m.count(val)) return false;
        
        int idx=m[val];
        int last=data.back();

        data[idx]=last;

        m[last]=idx;
        data.pop_back();
        m.erase(val);
        
        return true; 
    }
    
    int getRandom() {
        int idx=rand()%data.size();
        return data[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */