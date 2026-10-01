class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int rem=0;
        for(int i=0;i<nums.size();i++){
            rem=target-nums[i];
            if(m.count(rem))
                return {i,m[rem]};
            m[nums[i]]=i;
        }
        return {-1};
    }
};