class Solution {
private:
    int f(int i,int k,vector<int>& arr,vector<int>&dp){
        int n=arr.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=0,maxx=0,sum=0,len=0;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxx=max(maxx,arr[j]);
            sum=len*maxx+f(j+1,k,arr,dp);
            ans=max(ans,sum);
        }
        return dp[i]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return f(0,k,arr,dp);
    }
};