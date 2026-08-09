class Solution {
private:
vector<int> suffix;
    int f(int i,int M,vector<int>& piles, vector<vector<int>>& dp){
        int n=piles.size();
        if(i>=n) return 0;
        if(2*M>=n-i) return suffix[i];
        if(dp[i][M]!=-1) return dp[i][M];
        int ans=0;
        for(int X=1;X<=2*M && X+i<=n;X++){
            ans=max(ans,suffix[i]-f(i+X,max(M,X),piles,dp));
        }
        return dp[i][M]=ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        suffix.resize(n);
        suffix[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+piles[i];
        }
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,1,piles,dp);
    }
};