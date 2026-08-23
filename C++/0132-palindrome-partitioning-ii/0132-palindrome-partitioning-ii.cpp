class Solution {
private:
    bool palin(int l,int r,string& s){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int f(int i,int j,string& s,vector<vector<int>>& dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(palin(i,j,s)) return 0;
        int minn=j-i+1;
        for(int k=i;k<j;k++){
            if(palin(i,k,s)){
                int cuts=1+f(k+1,j,s,dp);
                minn=min(minn,cuts);
            }
        }
        return dp[i][j]=minn;
    }
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,n-1,s,dp);
    }
};