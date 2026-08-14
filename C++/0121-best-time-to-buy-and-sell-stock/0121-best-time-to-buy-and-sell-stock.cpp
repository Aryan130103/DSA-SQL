class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int minn=p[0],profit=0;
        for(int i=1;i<n;i++){
            int cost=p[i]-minn;
            profit=max(profit,cost);
            minn=min(minn,p[i]);
        }
        return profit;
    }
};