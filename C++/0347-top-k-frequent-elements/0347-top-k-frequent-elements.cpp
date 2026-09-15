class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>>pq;
        for(auto& i:nums) m[i]++;

        for(auto& [key,count]:m){
            pq.push({count,key});
        }

        vector<int> ans;
        while(!pq.empty() && k>0){
            auto [v,key]=pq.top();
            pq.pop();
            ans.push_back(key);
            k--;
        }
        return ans;
    }
};