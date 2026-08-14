class Solution {/*
private:
    int f(int i,int buy,int cap,vector<int>& p,vector<vector<vector<int>>>& dp){
        if(cap==0) return 0;
        if(i==p.size()) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        int profit=0;
        if(buy){
            profit=max((-p[i]+f(i+1,0,cap,p,dp)),f(i+1,1,cap,p,dp));
        }
        else{
            profit=max((p[i]+f(i+1,1,cap-1,p,dp)),f(i+1,0,cap,p,dp));
        }
        return dp[i][buy][cap]=profit;
    }*/
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        /*
        for(int i=n;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                dp[i][buy][0]=0;
            }
        }
        dp[n][0][1]=dp[n][0][2]=0;
        dp[n][1][1]=dp[n][1][2]=0;*/

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<3;cap++){
                    int profit=0;
                    if(buy){
                        profit=max(-p[i]+dp[i+1][0][cap], dp[i+1][1][cap]);
                    }
                    else{
                        profit=max(p[i]+dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }
                    dp[i][buy][cap]=profit;
                }
            }
        }
    return dp[0][1][2];
    }
};