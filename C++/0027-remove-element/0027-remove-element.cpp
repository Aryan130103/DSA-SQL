class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int freq[101]={0};
        for(auto& i:nums)
            freq[i]++;
        
        int l=0,r=n-1;
        while(l<r){
            if(nums[l]==val && nums[r]!=val)
                swap(nums[l++],nums[r--]);
            else if(nums[l]==val){
                r--;   
            }
            else
            l++;
        }
        
        return nums.size()-freq[val];
    }
};