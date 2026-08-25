class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int maxx=0;
        for(auto i:nums) m[i]++;

        maxx=*max_element(nums.begin(),nums.end());

        int n=maxx+2*k;
        int ans=0;
        for(int i=1;i<n;i++){
            if(m.find(k*i)==m.end()){
                ans=k*i;
                break;
            }
        }
        return ans;
    }
};