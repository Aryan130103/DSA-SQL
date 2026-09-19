class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxx=INT_MIN;
        int sum=0;
        for(auto n:nums){
            sum=max(sum+n,n);
            maxx=max(maxx,sum);
        }
        return maxx;
    }
};