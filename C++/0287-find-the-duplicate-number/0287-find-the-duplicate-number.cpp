class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n;
        
        while(l<r){
            int c=0;
            int mid=l+(r-l)/2;
            for(auto& i:nums){
                if(i<=mid)c++;
            }

            if(c>mid)
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};