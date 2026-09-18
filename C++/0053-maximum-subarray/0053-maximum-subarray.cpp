class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxx=INT_MIN;
        int sum=0;
        for(auto& i:nums){
            sum=max(sum+i,i);
            maxx=max(maxx,sum);
        }
        return maxx;
    }
};