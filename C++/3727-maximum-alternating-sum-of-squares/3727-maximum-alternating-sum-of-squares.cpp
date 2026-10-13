class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        for(auto& n:nums) n=abs(n);

        sort(nums.begin(),nums.end());

        int n=nums.size();
        int mid=n/2;
        long long sum=0;

        for(int i=0;i<mid;i++)
            sum-=nums[i]*nums[i];

        for(int i=mid;i<n;i++)
            sum+=nums[i]*nums[i];

        return sum;
    }
};