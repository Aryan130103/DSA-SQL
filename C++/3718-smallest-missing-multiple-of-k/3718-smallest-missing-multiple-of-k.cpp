class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        //unordered_map<int,int> m;
        //int maxx=0;
        //for(auto i:nums) m[i]++;

        //maxx=*max_element(nums.begin(),nums.end());

        //int n=maxx+2*k;
        //int ans=0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(int i=1;;i++){
            if(s.find(k*i)==s.end()){
                //ans=k*i;
                //break;
                return k*i;
            }
        }
        return 0;
    }
};