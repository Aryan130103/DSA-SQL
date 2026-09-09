class SnapshotArray {
public:
    int snap_id=0;
    vector<vector<pair<int,int>>> arr;
    
    SnapshotArray(int length) {
        arr.resize(length);
        for(int i=0;i<length;i++)
            arr[i].push_back({0,0});
    }
    
    void set(int index, int val) {
        arr[index].push_back({snap_id,val});
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        int l=0;
        int r=arr[index].size()-1;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[index][mid].first<=snap_id){
                ans=arr[index][mid].second;
                l=mid+1;
            }
            else 
                r=mid-1;
        }
        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */