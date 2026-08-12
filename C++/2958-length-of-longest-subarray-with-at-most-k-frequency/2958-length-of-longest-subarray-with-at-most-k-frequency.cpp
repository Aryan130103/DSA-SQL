class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        unordered_map<int,int> m;

        int ans=0;
        for(int r=0;r<n;r++){
            m[nums[r]]++;

            while(m[nums[r]]>k) {
                m[nums[l]]--;
                l++;
            }

            ans=max(ans,r-l+1);
        }

        return ans;
    }
};