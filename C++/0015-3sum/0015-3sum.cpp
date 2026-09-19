class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(j<k){
                
                int target=nums[i]+nums[j]+nums[k];
                if(target>0)
                    k--;
                else if(target<0)
                    j++;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(j<k && nums[j]==nums[j-1]) j++;
                }
            }
        }
        return ans;
    }
};