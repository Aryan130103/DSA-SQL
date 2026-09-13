class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n=nums.size();
        int m=nums[0].size();
        int l=0,r=n*m-1;
        while(l<=r){
            int mid=l+(r-l)/2;

            int row=mid/m;
            int col=mid%m;

            if(nums[row][col]==target) return true;
            if(nums[row][col]<target)
                l=mid+1;
            else 
                r=mid-1;
        }
        return false;   
    }
};