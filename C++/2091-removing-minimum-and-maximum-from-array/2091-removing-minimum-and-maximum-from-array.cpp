class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxx=max_element(nums.begin(),nums.end())-nums.begin();
        int minn=min_element(nums.begin(),nums.end())-nums.begin();

        int n=nums.size();

        int l=min(minn,maxx);
        int r=max(minn,maxx);

        int removeLeft=r+1;
        int removeRight=n-l;
        int removeBothEnd=l+1+n-r;

        int ans =min({removeLeft,removeRight,removeBothEnd});
        
        return ans;
    }
};