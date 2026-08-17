class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            for(int prev=0;prev<i; prev++){
                if(nums[i]%nums[prev]==0 && dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                    parent[i]=prev;
                }
            }
        }

        int last=0;
        for(int i=1;i<n;i++){
            if(dp[i]>dp[last]){
                last=i;
            }
        }

        vector<int> ans;
        while(parent[last]!=last){
            ans.push_back(nums[last]);
            last=parent[last];
        }
        ans.push_back(nums[last]);
        return ans;
    }
};