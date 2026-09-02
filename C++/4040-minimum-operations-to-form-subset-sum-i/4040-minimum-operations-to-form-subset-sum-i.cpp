class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<int>dp(sum+1,1e9);
        int n=nums.size();
        dp[0]=0;
        vector<int> ndp;
        for(int i=0;i<n;i++){
            ndp=dp;
            int x=nums[i];
            int v=x;
            int cost=0;

            while(v>0){
                if(v<=sum){
                    for(int s=sum;s>=v;s--){
                        if(ndp[s-v]!=1e9)
                            ndp[s]=min(ndp[s],dp[s-v]+cost);
                    }
                }
                v/=2;
                cost++;
            }

            v=x;
            cost=0;

            while(v<=sum){
                if(v>0){
                    for(int s=sum;s>=v;s--){
                        if(ndp[s-v]!=1e9)
                            ndp[s]=min(ndp[s],dp[s-v]+cost);
                    }
                }
                if(v>sum/2) break;
                v*=2;
                cost++;
            }
            dp=ndp;
        }

        return dp[sum]==1e9?-1:dp[sum];
    }
};