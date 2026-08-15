class Solution {
public:
    int maxProfit(vector<int>& p) {
        int minn=p[0],profit=0;
        int n=p.size();
        for(int i=0;i<n;i++){
            profit=max(profit,p[i]-minn);
            minn=min(minn,p[i]);
        }
        return profit;
    }
};