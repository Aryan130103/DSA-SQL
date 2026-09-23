class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        int t=total-x;
        if(t<0) return -1;
        if(t==0) return n;

        int l=0,sum=0,maxx=-1;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>t){
                sum-=nums[l++];
            }

            if(sum==t){
                maxx=max(maxx,r-l+1);
            }
        }
        return maxx==-1?-1:n-maxx;
    }
};