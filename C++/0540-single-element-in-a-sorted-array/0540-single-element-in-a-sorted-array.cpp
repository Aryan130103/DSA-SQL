class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int k=2;
        int l=0,r=(n-1)/k;

        while(l<r){
            int mid=l+(r-l)/2;
            int start=mid*k;
            int end=start+k-1;

            if(end<n && nums[start]==nums[end])
                l=mid+1;
            else
                r=mid;
        }
        return nums[l*k];
    }
};