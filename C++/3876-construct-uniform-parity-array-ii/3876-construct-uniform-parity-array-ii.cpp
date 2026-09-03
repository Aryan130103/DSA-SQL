class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        bool odd=true;
        bool even=true;
        int minn=INT_MAX;
        
        for(auto &it:nums)
            if(it%2)
                minn=min(minn,it);
        
        for(auto &it:nums){
            if(it%2==0 && it<=minn)
                odd=false;
            if(it%2==1 && it<=minn)
                even=false;
        }
        return odd || even;
    }
};