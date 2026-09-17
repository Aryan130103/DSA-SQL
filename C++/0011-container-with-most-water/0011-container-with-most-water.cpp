class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int n=height.size();
        int l=0,r=n-1;
        while(l<r){
            area=max(area,min(height[r],height[l])*(r-l));  
            if(height[r]>height[l]){
                l++;
            }
            else{
                r--;
            }
        }
        return area;
    }
};