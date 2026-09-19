class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
            else
                c++;
        }

        int i=nums.size()-1;
        while(c>0){
            nums[i--]=0;
            c--;
        }
    }
};