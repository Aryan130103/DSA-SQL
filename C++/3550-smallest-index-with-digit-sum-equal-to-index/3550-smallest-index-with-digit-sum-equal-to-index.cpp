class Solution {
private:
    int f(int num){
        if(num==0) return 0;
        int s=0;
        while(num>0){
            s+=num%10;
            num/=10;
        }
        return s;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();

        for(auto &i:nums){
                i=f(i);
        }

        for(int i=0;i<n;i++){
            if(i==nums[i])
                return i;
        }
        return -1;
    }
};