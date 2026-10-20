class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>> jobs;
        for(int i=0;i<n;i++)
            jobs.push_back({endTime[i],startTime[i],profit[i]});
        
        sort(jobs.begin(),jobs.end());
        
        vector<int> ends(n);
        for(int i=0;i<n;i++){
            ends[i]=jobs[i][0];
        }

        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int e=jobs[i-1][0];
            int s=jobs[i-1][1];
            int p=jobs[i-1][2];

            int idx=upper_bound(ends.begin(),ends.begin()+i-1,s)-ends.begin();
            dp[i]=max(dp[i-1],dp[idx]+p);
        }
        return dp[n];
    }
};