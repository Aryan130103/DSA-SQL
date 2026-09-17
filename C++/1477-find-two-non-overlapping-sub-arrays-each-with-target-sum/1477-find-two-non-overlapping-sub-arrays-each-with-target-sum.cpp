class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int t) {
        int n=arr.size();
        int res=1e9;
        int l=0,sum=0;

        vector<int> dp(n+1,1e9);

        for(int r=0;r<n;r++){
            sum+=arr[r];
            while(sum>t){
                sum-=arr[l];
                l++;
            }
            dp[r+1]=dp[r];

            if(sum==t){
                res=min(res,r-l+1+dp[l]);
                dp[r+1]=min(dp[r],r-l+1);
            }
        }
        return res==1e9?-1:res;
    }
};