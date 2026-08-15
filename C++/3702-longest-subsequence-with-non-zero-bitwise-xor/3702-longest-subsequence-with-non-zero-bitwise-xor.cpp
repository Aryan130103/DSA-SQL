class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        bool nonzero=false;
        for(auto i: nums){
            ans =ans^i;
            if(i!=0) nonzero=true;
        }     
        //if(c==n) return 0;
        if(ans!=0) return n;
        else if(nonzero)
        return n-1;

        return 0;
    }
}; 