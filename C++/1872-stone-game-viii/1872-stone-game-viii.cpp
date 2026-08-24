class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        for(int i=1;i<n;i++){
            stones[i]+=stones[i-1];
        }
        int dp=stones[n-1];

        for(int k=n-2;k>0;k--){
            dp=max(dp,stones[k]-dp);
        }
        return dp;
    }
};