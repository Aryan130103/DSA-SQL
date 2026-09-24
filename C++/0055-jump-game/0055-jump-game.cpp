class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(maxx<i)
            return false;
            maxx=max(maxx,i+nums[i]);
            if(maxx>=n-1) return true;
        }
        return true;
    }
};