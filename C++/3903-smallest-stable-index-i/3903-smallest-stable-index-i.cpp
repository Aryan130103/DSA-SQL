class Solution {
private:
    int maxx(int x,vector<int>& nums){
        int maxi=0;
        int i=0;
        while(i<=x){
            maxi=max(maxi,nums[i]);
            i++;
        }
        return  maxi;
    }

    int minn(int x,vector<int>& nums){
        int mini=INT_MAX;
        int n=nums.size();
        while(x<n){
            mini=min(mini,nums[x]);
            x++;
        }
        return  mini;
    }
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int diff=maxx(i,nums)-minn(i,nums);
            if(diff<=k) return i;
        }
        return -1;
    }
};