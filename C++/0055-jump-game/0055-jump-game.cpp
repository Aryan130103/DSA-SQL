class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxx=0;

        for(int i=0;i<nums.size();i++){
            if(maxx<i)
                return false;

            maxx=max(maxx,i+nums[i]);
            if(maxx>=nums.size()-1)
                return true;
        }
        return true;
    }
};