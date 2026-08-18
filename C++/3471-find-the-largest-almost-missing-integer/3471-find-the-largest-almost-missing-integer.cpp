class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;

        if(k==1){
            for(auto i:nums){
                if(m[i]==1){
                    ans=max(ans,i);
                }
            }
            return ans;
        }

        if(k==n)
            return *max_element(nums.begin(),nums.end());
        
        if(m[nums[0]]==1)
            ans=max(ans,nums[0]);
        
        if(m[nums[n-1]]==1)
            ans=max(ans,nums[n-1]);
        return ans;
    }
};