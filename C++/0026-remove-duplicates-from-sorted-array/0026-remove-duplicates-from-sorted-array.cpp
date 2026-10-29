class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;

        int k=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]!=nums[i])
                nums[k++]=nums[i-1];
        }
        nums[k]=nums[n-1];
        k++;
        return k;
    }
};