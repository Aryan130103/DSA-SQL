class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,lmax=0,rmax=0,water=0;
        while(l<r){
            if(height[l]<=height[r]){
                lmax=max(lmax,height[l]);
                water+=lmax-height[l];
                l++;
            }
            else{
                rmax=max(rmax,height[r]);
                water+=rmax-height[r];
                r--;
            }
        }
        return water;
    }
};