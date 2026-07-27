class Solution {
public:
    int maxProduct(vector<int>& nums) {
       // sort(nums.begin(),nums.end());
        int n=nums.size();
        int m1=0,m2=0;
        for(auto& it:nums){
            if(it>m1){
                m2=m1;
                m1=it;
            }
            else if(it>m2)
            m2=it;
        }
        return (m1-1)*(m2-1);
    }
};