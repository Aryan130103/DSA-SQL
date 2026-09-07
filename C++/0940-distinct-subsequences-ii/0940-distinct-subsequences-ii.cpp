class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD=1e9+7;
        vector<long long>dp(26,0);
        long long total=0;
        for(auto ch:s){
            int c=ch-'a';
            long long newTotal=(total+1)%MOD;
            total=(total-dp[c]+newTotal+MOD)%MOD;
            dp[c]=newTotal;
        }
        return total;
    }
};