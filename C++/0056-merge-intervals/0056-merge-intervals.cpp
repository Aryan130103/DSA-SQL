class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<=1) return intervals;
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;
        int e=intervals[0][1];
        int s=intervals[0][0];

        for(int i=1;i<n;i++){
            if(intervals[i][0]<=e){
                e=max(e,intervals[i][1]);
            }
            else{
                ans.push_back({s,e});
                e=intervals[i][1];
                s=intervals[i][0];
            }       
        }
        ans.push_back({s,e});
        return ans;
    }
};