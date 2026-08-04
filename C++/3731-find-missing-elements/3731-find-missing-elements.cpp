class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;

        int n=*max_element(nums.begin(),nums.end());
        int i=*min_element(nums.begin(),nums.end());
        vector<int> ans;
        for( i;i<=n;i++){
            if(m[i]==0) ans.push_back(i);
        }
        return ans; 
    }
};