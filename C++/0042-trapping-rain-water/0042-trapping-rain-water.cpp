class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,lmax=0,rmax=0;
        int rain=0;
        while(l<r){
            if(height[l]<=height[r]){
                lmax=max(lmax,height[l]);
                rain+=lmax-height[l];
                l++;
            }
            else{
                rmax=max(rmax,height[r]);
                rain+=rmax-height[r];
                r--;
            }
        }
        return rain;
    }
};