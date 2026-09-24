class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        int r=0,l=0,maxx=0;
        while(r<n-1){
            for(int i=l;i<=r;i++)
                maxx=max(maxx,i+nums[i]);
            l=r+1;
            r=maxx;
            c++;
        }
        return c;
    }
};