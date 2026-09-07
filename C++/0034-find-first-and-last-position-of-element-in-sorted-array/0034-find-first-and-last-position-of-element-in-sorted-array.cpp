class Solution {
private:
    int f(vector<int>& nums, int target,bool found) {
        int n=nums.size();
        int l=0,r=n-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans=mid;
                if(found)
                    r=mid-1;
                else
                    l=mid+1;
            }
            else if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {f(nums,target,true),f(nums,target,false)};
    }
};