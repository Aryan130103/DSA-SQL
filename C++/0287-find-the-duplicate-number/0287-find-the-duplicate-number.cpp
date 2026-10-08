class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=1,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            int c=0;
            for(auto& it:nums){
                if(it<=mid)c++;
            }

            if(c>mid) r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};