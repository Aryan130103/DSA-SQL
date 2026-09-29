class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k=accumulate(nums.begin(),nums.end(),0);
        if(k<=1) return 0;

        int n=nums.size();
        int ones=0,maxx=0;

        for(int i=0;i<n+k-1;i++){
            ones+=nums[i%n];
            if(i>=k) ones-=nums[(i-k)%n];
            maxx=max(maxx,ones);
        }
        return k-maxx;
    }
};