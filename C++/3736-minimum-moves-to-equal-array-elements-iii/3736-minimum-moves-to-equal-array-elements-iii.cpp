class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxx=*max_element(nums.begin(),nums.end());

        int total=accumulate(nums.begin(),nums.end(),0);

        int n=nums.size();
        return n*maxx-total;
    }
};