class Solution {
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
    }
public:
    int maxProfit(vector<int>& p) {
          int n=p.size();
          vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
       
        return f(0,1,2,p,dp);
    }
};