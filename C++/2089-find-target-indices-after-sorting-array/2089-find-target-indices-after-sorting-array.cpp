class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int smaller=0,c=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==target)
                c++;
            if(nums[i]<target)
                smaller++;
        }

        for(int i=smaller;i<n;i++){
            if(c==0) break;
            ans.push_back(i);
            c--;
        }

        return ans;
    }
};