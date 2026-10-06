class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int c=0;
            for(auto& n:nums){
                c+=(n>>i)&1;
            }
            if(c%3)
            ans|=1<<i;
        }
        return ans;
    }
};