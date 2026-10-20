class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> pq;

        for(auto& p:points){
            int dis=p[0]*p[0]+p[1]*p[1];
            pq.push({dis,p});
        }

        vector<vector<int>>ans;

        while(k){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};